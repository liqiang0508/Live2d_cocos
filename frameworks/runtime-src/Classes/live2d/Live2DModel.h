
/*
* Copyright(c) Live2D Inc. All rights reserved.
*
* Use of this source code is governed by the Live2D Open Software license
* that can be found at http://live2d.com/eula/live2d-open-software-license-agreement_en.html.
*/

#pragma once


#include "Framework/src/CubismFramework.hpp"
#include "Framework/src/Math/CubismMatrix44.hpp"
#include "Framework/src/Math/CubismViewMatrix.hpp"
#include "TouchManager.h"
#include "2d/CCSprite.h"
#include "cocos2d.h"
#include <vector>
#include "LAppLive2DManager.hpp"
#include "LAppDefine.hpp"
#include "ui/CocosGUI.h"

//#include "CCLuaEngine.h"

USING_NS_CC;
using namespace Csm;
using namespace cocos2d;
using namespace std;
using namespace ui;
class Live2DModel : public cocos2d::Node
{
public:
	Live2DModel();
	virtual ~Live2DModel();

	virtual void onEnter();
	virtual void onExit();
	void update(float t);
	virtual void draw(cocos2d::Renderer* renderer, const cocos2d::Mat4& transform, uint32_t flags);
	virtual void onDraw(const cocos2d::Mat4& transform, uint32_t flags);

	bool onTouchesBegan(Touch* touches, cocos2d::Event* event);
	void onTouchesMoved(Touch*  touches, cocos2d::Event* event);
	void onTouchesEnded(Touch*  touches, cocos2d::Event* event);
	void onTouchCancelled(Touch* touches, cocos2d::Event* event);

	void updateViewMatrix(float dx, float dy, float cx, float cy, float scale);
	float transformViewX(float deviceX);
	float transformViewY(float deviceY);
	float transformScreenX(float deviceX);
	float transformScreenY(float deviceY);

	void setDebugRectsNode(DrawNode* debugRects);
	void drawDebugRects();
	Size getCanvasSize();
	Rect getCanvasRect();
	static Live2DModel* create(const csmChar* path);

	virtual bool init(const csmChar* path);// { return true; }
	void LoadAssets(const csmChar* dir, const csmChar* fileName);
	void OnTap(csmFloat32 x, csmFloat32 y);
	void OnDrag(Csm::csmFloat32 x, Csm::csmFloat32 y) ;

	void StartRandomMotion(const csmChar* group, csmInt32 priority, std::function<void()> &endcall);//随机播放群组里面的一个动画
	void StartMotion(const csmChar* group, csmInt32 no,csmInt32 priority, std::function<void()> &endcall ,bool loop = false);

	void setOpcaity(float f);
	void setModelColor(const Color4B& color);

	void SetRandomExpression();
	void SetExpression(const Csm::csmChar* expressionID);
	void SetTouchEnable(bool b) { if(listener)listener->setEnabled(b); };

	void addClickTouchEvent(const std::function<void(Touch* touches, ui::TouchEventType)> &call);
	void setAniFinishLuaFunc(const std::function<void()> &endcall);
	Csm::csmBool HitTest(const Csm::csmChar* hitAreaName, Csm::csmFloat32 x, Csm::csmFloat32 y);
private:
	TouchManager* touchMgr;
	Csm::CubismMatrix44* deviceToScreen;
	Csm::CubismViewMatrix* viewMatrix;
	DrawNode* _debugRects;
	Csm::CubismMatrix44       _viewMatrix;
	LAppModel* _model;
	const Csm::csmChar* m_resDir;
	const Csm::csmChar* m_resName;

	cocos2d::EventListenerCustom* _recreatedEventlistener;
	EventListenerTouchOneByOne* listener;
	std::function<void(Touch* touches, ui::TouchEventType)> _TouchCall;//点击回调
	std::function<void()> m_AniEndCall;//动画结束回调
	bool m_AniLoop;
	bool m_AniPlaying;
	std::string m_CurAniGroup = "";
	csmInt32 m_CurAniNum = 0;

protected:
	cocos2d::CustomCommand _customCommand;
};
