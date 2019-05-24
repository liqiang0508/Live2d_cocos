/*
* Copyright(c) Live2D Inc. All rights reserved.
*
* Use of this source code is governed by the Live2D Open Software license
* that can be found at http://live2d.com/eula/live2d-open-software-license-agreement_en.html.
*/

#include "Live2DModel.h"
#include "LAppDefine.hpp"
#include "LAppPal.hpp"
#include "LAppModel.hpp"
#include "Framework/src/Rendering/OpenGL/CubismRenderer_OpenGLES2.hpp"
using namespace Csm;
using namespace LAppDefine;

USING_NS_CC;

Live2DModel::Live2DModel() : Node()
, _debugRects(NULL), _model(nullptr), listener(nullptr), _TouchCall(nullptr), m_AniLoop(false), m_AniEndCall(nullptr)
{
	assert(CubismFramework::IsStarted());

	CubismFramework::Initialize();
}
Live2DModel::~Live2DModel()
{
	CubismFramework::Dispose();
	Director::getInstance()->getEventDispatcher()->removeEventListener(_recreatedEventlistener);
}


void Live2DModel::onEnter()
{
	Node::onEnter();

	// タッチ関係のイベント管理
	touchMgr = new TouchManager();

	Size size = Director::getInstance()->getVisibleSize();

	float width = size.width;
	float height = size.height;
	float ratio = (float)height / width;
	float left = ViewLogicalLeft;
	float right = ViewLogicalRight;
	float bottom = -ratio;
	float top = ratio;

	viewMatrix->SetScreenRect(left, right, bottom, top); // デバイスに対応する画面の範囲。 Xの左端, Xの右端, Yの下端, Yの上端

	float screenW = abs(left - right);
	deviceToScreen->ScaleRelative(screenW / width, -screenW / width);

	auto screenPos = this->getParent()->convertToWorldSpace(this->getPosition());
	deviceToScreen->TranslateRelative(-screenPos.x / 1.0f, -(height- screenPos.y) / 1.0f);




	// 表示範囲の設定
	viewMatrix->SetMaxScale(ViewMaxScale); // 限界拡大率
	viewMatrix->SetMinScale(ViewMinScale); // 限界縮小率

										   // 表示できる最大範囲
	viewMatrix->SetMaxScreenRect(
		ViewLogicalMaxLeft,
		ViewLogicalMaxRight,
		ViewLogicalMaxBottom,
		ViewLogicalMaxTop
	);

	// イベントリスナー作成
	listener = EventListenerTouchOneByOne::create();

	// タッチメソッド設定
	listener->onTouchBegan = CC_CALLBACK_2(Live2DModel::onTouchesBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(Live2DModel::onTouchesMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(Live2DModel::onTouchesEnded, this);
	listener->onTouchCancelled = CC_CALLBACK_2(Live2DModel::onTouchCancelled, this);
	listener->setSwallowTouches(true);
	// 優先度100でディスパッチャーに登録
	this->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 100);


	_recreatedEventlistener = cocos2d::EventListenerCustom::create(EVENT_RENDERER_RECREATED, [this](EventCustom*)
	{
		_model->ReloadRnederer();
		
	});
	auto director = Director::getInstance();
	director->getEventDispatcher()->addEventListenerWithFixedPriority(_recreatedEventlistener, -1);

	Size s = getCanvasRect().size;
	this->setContentSize(s);
	this->ignoreAnchorPointForPosition(false);
	this->setAnchorPoint(Vec2(0.5, 0.5));

	this->scheduleUpdate();
	

}

void Live2DModel::update(float t) {

	if (_model->AniIsFinish())
	{
		if (m_AniLoop)
		{
			/*this->runAction(Sequence::create(DelayTime::create(5), CallFunc::create([=]() {
				StartMotion(m_CurAniGroup.c_str(), m_CurAniNum, PriorityNormal, m_AniLoop);
			}), nullptr));*/

			/*return;*/
		}
		if (m_AniEndCall)
		{
			m_AniEndCall();
			m_AniEndCall = nullptr;
		}
	}

}

void Live2DModel::onExit()
{
	Node::onExit();

	delete touchMgr;
	delete deviceToScreen;
	delete viewMatrix;
}
bool Live2DModel::init(const csmChar* path)
{
	if (!Node::init())
	{
		return false;
	}
	
	std::string tempPath = path;
	int pos = tempPath.find_last_of('/');
	std::string dir = tempPath.substr(0, pos+1);
	std::string filename = tempPath.substr(pos + 1);
	
	m_resDir = dir.c_str();
	m_resName = filename.c_str();

	viewMatrix = new CubismViewMatrix();
	deviceToScreen = new CubismMatrix44();
	this->LoadAssets(m_resDir, m_resName);

	
	return true;
}

void Live2DModel::draw(cocos2d::Renderer* renderer, const cocos2d::Mat4& transform, uint32_t flags)
{
	
	
	
	_customCommand.init(_globalZOrder);
	_customCommand.func = CC_CALLBACK_0(Live2DModel::onDraw, this, transform, flags);
	renderer->addCommand(&_customCommand);
	Node::draw(renderer, transform, flags);
}

Size Live2DModel::getCanvasSize()
{
	return{ _model->GetModel()->GetCanvasWidth(),_model->GetModel()->GetCanvasHeight() };
}
Rect Live2DModel::getCanvasRect()
{
	const auto window = Director::getInstance()->getWinSize();
	const auto scale_x = window.width / getScaleX()*0.5;
	const auto scale_y = window.height / getScaleY()*0.5;
	CubismMatrix44 currentMatrix(_viewMatrix);
	currentMatrix.MultiplyByMatrix(_model->GetModelMatrix());
	const auto size = getCanvasSize();
	const float right = size.width / 2;
	const float left = -right;
	const float bottom = size.height / 2;
	const float top = -bottom;
	const auto arr = currentMatrix.GetArray();
	const auto convertLeft = (left * arr[0] + top * arr[1]) * scale_x;
	const auto convertTop = (left * arr[4] + top * arr[5]) * scale_y;
	const auto convertRight = (right * arr[0] + bottom * arr[1]) * scale_x;
	const auto convertBottom = (right * arr[4] + bottom * arr[5]) * scale_y;
	// origin is left-bottom
	return Rect(std::min(convertLeft, convertRight), std::min(convertBottom, convertTop),
		std::abs(convertRight - convertLeft), std::abs(convertTop - convertBottom));
}
void Live2DModel::onDraw(const cocos2d::Mat4& transform, uint32_t flags)
{
	
	Director::getInstance()->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
	Director::getInstance()->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW, transform);

	auto a = transform.m;
	
	auto _Pos = this->getParent()->convertToWorldSpace(this->getPosition());

	CubismMatrix44 projection;
	Director* director = Director::getInstance();
	Size window = director->getVisibleSize();
	projection.Scale(1, window.width / window.height);
	projection.ScaleRelative(a[5], a[10]);
	float posx = _Pos.x+ director->getVisibleOrigin().x;
	float posy = _Pos.y + director->getVisibleOrigin().y;
	float x = (posx - window.width/2) / (window.width/2);
	float y = (posy - window.height/2) / (window.height/2);
	projection.Translate(x, y);

	_viewMatrix = projection;

	if (viewMatrix != NULL)
	{
		projection.MultiplyByMatrix(viewMatrix);
	}

	_model->Update();
	_model->Draw(projection);///< 参照渡しなのでprojectionは変質する
	if (DebugDrawRectEnable)
	{
		drawDebugRects();
	}
	
	

	Director::getInstance()->popMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
	
}
void Live2DModel::LoadAssets(const csmChar* dir, const csmChar* fileName)
{
	if (_model==nullptr)
	{
	    _model = new LAppModel();
		_model->LoadAssets(dir,fileName);
	}

}
bool Live2DModel::onTouchesBegan(Touch* touches, Event* event)
{
	Rect rec = this->getBoundingBox();
	Vec2 pos = this->getParent()->convertToNodeSpace( touches->getLocation());
	if (!rec.containsPoint(pos))
	{
		return false;

	}
		Point pt = touches->getLocationInView();
		if (DebugTouchLogEnable)LAppPal::PrintLog("[Live2DModel]touchesBegan x:%.0f y:%.0f", pt.x, pt.y);
		touchMgr->touchesBegan(pt.x, pt.y);
		if (_TouchCall) {
			_TouchCall(touches, ui::TouchEventType::TOUCH_EVENT_BEGAN);
		
		}
	return true;
}


void Live2DModel::addClickTouchEvent(const std::function<void(Touch* touches, ui::TouchEventType)> &call)
{

	_TouchCall = call;
}
void Live2DModel::onTouchesMoved(Touch* touches, Event* event)
{

	Point pt = touches->getLocationInView();

	touchMgr->touchesMoved(pt.x, pt.y);
	if (_TouchCall) {
		_TouchCall(touches, ui::TouchEventType::TOUCH_EVENT_MOVED);

	}

}

Csm::csmBool Live2DModel::HitTest(const Csm::csmChar* hitAreaName, Csm::csmFloat32 x, Csm::csmFloat32 y)
{
	x = deviceToScreen->TransformX(x);
	y = deviceToScreen->TransformY(y);
	return _model->HitTest(hitAreaName,x,y);
}
void Live2DModel::SetExpression(const Csm::csmChar* expressionID)
{
	_model->SetExpression(expressionID);

}
void Live2DModel::SetRandomExpression()
{
	_model->SetRandomExpression();
}
void Live2DModel::setModelColor(const Color4B& color)
{
	_model->GetRenderer<Rendering::CubismRenderer_OpenGLES2>()->SetModelColor(
		color.r / 255.f, color.g / 255.f, color.b / 255.f, color.a / 255.f);
}
void Live2DModel::setOpcaity(float f)
{
	if (_model)
	{
		//_model->SetOpacity(f);
		_model->GetRenderer<Rendering::CubismRenderer_OpenGLES2>()->SetModelColor(
			1, 1, 1, f / 255.f);

	}
}

void Live2DModel::setAniFinishLuaFunc(const std::function<void()> &endcall)
{
	m_AniEndCall = endcall;
}
void Live2DModel::StartMotion(const csmChar* group, csmInt32 no, csmInt32 priority, std::function<void()> &endcall, bool loop)
{
	m_AniLoop = loop;
	m_CurAniGroup = group;
	m_CurAniNum = no;
	_model->StartMotion(group,no, PriorityForce);
	
	
}
void Live2DModel::StartRandomMotion(const csmChar* group, csmInt32 priority, std::function<void()> &endcall)
{
	m_AniLoop = false;
	_model->StartRandomMotion(group, priority);
	
}
void Live2DModel::OnDrag(csmFloat32 x, csmFloat32 y) 
{
	    x = this->transformViewX(x);
		y = this->transformViewY(y);
		_model->SetDragging(x, y);
	
}

void Live2DModel::onTouchCancelled(Touch* touches, cocos2d::Event* event)
{
	this->onTouchesEnded(touches, event);

}
void Live2DModel::onTouchesEnded(Touch* touches, cocos2d::Event* event)
{
	// タッチ終了
	_model->SetDragging(0, 0);
	Point pt = touches->getLocationInView();
	//float x = deviceToScreen->TransformX(touchMgr->getX()); // 論理座標変換した座標を取得。
	//float y = deviceToScreen->TransformY(touchMgr->getY()); // 論理座標変換した座標を取得。

	//if (DebugTouchLogEnable) LAppPal::PrintLog("[Live2DModel]touchesEnded x:%.2f y:%.2f", x, y);
	//this->OnTap(pt.x, pt.y);
	//this->OnTap(x, y);

	if (_TouchCall) {
		_TouchCall(touches, ui::TouchEventType::TOUCH_EVENT_ENDED);

	}
	
}

void Live2DModel::OnTap(csmFloat32 x, csmFloat32 y)
{
	x = deviceToScreen->TransformX(x); 
	y = deviceToScreen->TransformY(y);
	if (DebugLogEnable) LAppPal::PrintLog("[Live2DModel]tap point: {x:%.2f y:%.2f}", x, y);


		if (_model->HitTest(HitAreaNameHead, x, y))
		{
			if (DebugLogEnable) LAppPal::PrintLog("[Live2DModel]hit area: [%s]", HitAreaNameHead);
			_model->SetRandomExpression();
		}
		else if (_model->HitTest(HitAreaNameBody, x, y))
		{
			if (DebugLogEnable) LAppPal::PrintLog("[Live2DModel]hit area: [%s]", HitAreaNameBody);
			_model->StartRandomMotion(MotionGroupTapBody, PriorityForce);
		}
	
}
void Live2DModel::updateViewMatrix(float dx, float dy, float cx, float cy, float scale)
{
	
	// 拡大縮小
	viewMatrix->AdjustScale(cx, cy, scale);

	// 移動
	viewMatrix->AdjustTranslate(dx, dy);


}

float Live2DModel::transformViewX(float deviceX)
{
	float screenX = deviceToScreen->TransformX(deviceX); // 論理座標変換した座標を取得。
	return viewMatrix->InvertTransformX(screenX); // 拡大、縮小、移動後の値。
}

float Live2DModel::transformViewY(float deviceY)
{
	float screenY = deviceToScreen->TransformY(deviceY); // 論理座標変換した座標を取得。
	return viewMatrix->InvertTransformY(screenY); // 拡大、縮小、移動後の値。
}

float Live2DModel::transformScreenX(float deviceX)
{
	return deviceToScreen->TransformX(deviceX);
}

float Live2DModel::transformScreenY(float deviceY)
{
	return deviceToScreen->TransformY(deviceY);
}

void Live2DModel::setDebugRectsNode(DrawNode* debugRects)
{
	_debugRects = debugRects;
}
void Live2DModel::drawDebugRects()
{
	const Color4F hitAreaColor = Color4F(1.0f, 0, 0, 0.5f);
	const Color4F userDataAreaColor = Color4F(0, 0, 1.0f,0.5f);

	CubismMatrix44 projection;
	const Size window = Director::getInstance()->getWinSize();
	const CubismVector2 windowSize = CubismVector2(window.width, window.height);
	projection.Scale(1, window.width / window.height);

	if (viewMatrix != NULL)
	{
		projection.MultiplyByMatrix(viewMatrix);
	}
		_debugRects->clear();
		LAppModel* model = _model;
		const Csm::csmVector<Csm::csmRectF>& userDataAreas = model->GetUserDataAreas(projection, windowSize);
		for (csmUint32 j = 0; j < userDataAreas.GetSize(); ++j)
		{
			_debugRects->drawSolidRect(Vec2(userDataAreas[j].X, userDataAreas[j].Y)
				, Vec2(userDataAreas[j].GetRight(), userDataAreas[j].GetBottom())
				, userDataAreaColor);
		}

		const Csm::csmVector<Csm::csmRectF>& hitAreas = model->GetHitAreas(projection, windowSize);
		for (csmUint32 j = 0; j < hitAreas.GetSize(); ++j)
		{
			_debugRects->drawSolidRect(Vec2(hitAreas[j].X, hitAreas[j].Y)
				, Vec2(hitAreas[j].GetRight(), hitAreas[j].GetBottom())
				, hitAreaColor);
		}
	
}

Live2DModel* Live2DModel::create(const csmChar* path)
{
	Live2DModel* ret = new(std::nothrow) Live2DModel();
	if (ret && ret->init(path))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}
