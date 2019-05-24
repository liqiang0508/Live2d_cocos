#include "lua_Live2d_Manual.hpp"
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
#include "../Live2DModel.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"
#include "CCLuaValue.h"
#include "CCLuaEngine.h"

static int handleUIEvent(int handler, Touch* touches, ui::TouchEventType eventType)
{
	LuaStack* stack = LuaEngine::getInstance()->getLuaStack();

	stack->pushObject(touches, "cc.Touch");
	stack->pushInt(eventType);


	stack->executeFunctionByHandler(handler, 2);
	stack->clean();

	return 0;
}

int lua_Live2DModel_addClickTouchEvent(lua_State* L)
{
	if (nullptr == L)
		return 0;

	int argc = 0;
	Live2DModel* self = nullptr;

	self = static_cast<Live2DModel*>(tolua_tousertype(L, 1, 0));
	argc = lua_gettop(L) - 1;
	if (1 == argc)
	{
		LUA_FUNCTION handler = (toluafix_ref_function(L, 2, 0));
		self->addClickTouchEvent([=](Touch* touches, ui::TouchEventType eventType) {
			handleUIEvent(handler, touches, eventType);
		});
		return 1;
	}
	return 0;
}

int lua_Live2DModel_StartMotion(lua_State* L)
{
	int argc = 0;
	Live2DModel* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(L, 1, "Live2DModel", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = static_cast<Live2DModel*>(tolua_tousertype(L, 1, 0));

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(L, "invalid 'cobj' in function 'lua_Live2DModel_StartMotion'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(L) - 1;
	if (argc == 5)
	{
		const char* arg0;
		int arg1;
		int arg2;
		std::function<void()> arg3;
		bool arg4;

		std::string arg0_tmp; 

		ok &= luaval_to_std_string(L, 2, &arg0_tmp, "Live2DModel:StartMotion"); 
		arg0 = arg0_tmp.c_str();

		ok &= luaval_to_int32(L, 3, (int *)&arg1, "Live2DModel:StartMotion");

		

		ok &= luaval_to_int32(L, 4, (int *)&arg2, "Live2DModel:StartMotion");

		LUA_FUNCTION handler = (toluafix_ref_function(L, 5, 0));

		ok &= luaval_to_boolean(L, 6,&arg4, "Live2DModel:StartMotion");

		if (!ok)
		{
			tolua_error(L, "invalid arguments in function 'lua_Live2DModel_StartMotion'", nullptr);
			return 0;
		}
		cobj->setAniFinishLuaFunc([=]() {

			LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
			/*stack->pushObject(touches, "cc.Touch");
			stack->pushInt(eventType);*/
			stack->executeFunctionByHandler(handler, 02);
			stack->clean(); });

		cobj->StartMotion(arg0, arg1, arg2, arg3,arg4);
		lua_settop(L, 1);
		return 1;
	}
	luaL_error(L, "%s has wrong number of arguments: %d, was expecting %d \n", "Live2DModel:StartMotion", argc, 3);
	return 0;

#if COCOS2D_DEBUG >= 1
	tolua_lerror:
				tolua_error(L, "#ferror in function 'lua_Live2DModel_StartMotion'.", &tolua_err);
#endif

				return 0;
}
int lua_Live2DModel_StartRandomMotion(lua_State* L)
{
	int argc = 0;
	Live2DModel* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(L, 1, "Live2DModel", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = static_cast<Live2DModel*>(tolua_tousertype(L, 1, 0));

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(L, "invalid 'cobj' in function 'lua_Live2DModel_Live2DModel_StartRandomMotion'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(L) - 1;
	if (argc == 3)
	{
		const char* arg0;
		int arg1;
		std::function<void()> arg2;

		std::string arg0_tmp; ok &= luaval_to_std_string(L, 2, &arg0_tmp, "Live2DModel:StartRandomMotion"); arg0 = arg0_tmp.c_str();

		ok &= luaval_to_int32(L, 3, (int *)&arg1, "Live2DModel:StartRandomMotion");

		LUA_FUNCTION handler = (toluafix_ref_function(L,4, 0));
		
		if (!ok)
		{
			tolua_error(L, "invalid arguments in function 'lua_Live2DModel_Live2DModel_StartRandomMotion'", nullptr);
			return 0;
		}
		cobj->setAniFinishLuaFunc([=]() { 
			
			LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
			/*stack->pushObject(touches, "cc.Touch");
			stack->pushInt(eventType);*/
			stack->executeFunctionByHandler(handler,0);
			stack->clean(); });

		cobj->StartRandomMotion(arg0, arg1, arg2);
		lua_settop(L, 1);
		return 1;
	}
	luaL_error(L, "%s has wrong number of arguments: %d, was expecting %d \n", "Live2DModel:StartRandomMotion", argc, 3);
	return 0;

#if COCOS2D_DEBUG >= 1
	tolua_lerror:
				tolua_error(L, "#ferror in function 'lua_Live2DModel_Live2DModel_StartRandomMotion'.", &tolua_err);
#endif

				return 0;
}
int lua_register_Live2DModel_manual(lua_State* L) {
	tolua_usertype(L, "Live2DModel");
	tolua_cclass(L, "Live2DModel", "Live2DModel", "", nullptr);

	tolua_beginmodule(L, "Live2DModel");
	tolua_function(L, "addClickTouchEvent", lua_Live2DModel_addClickTouchEvent);
	tolua_function(L, "StartRandomMotion", lua_Live2DModel_StartRandomMotion);
	tolua_function(L, "StartMotion", lua_Live2DModel_StartMotion);
	tolua_endmodule(L);
	std::string typeName = typeid(Live2DModel).name();
	g_luaType[typeName] = "Live2DModel";
	g_typeCast["Live2DModel"] = "Live2DModel";
	return 1;
}

TOLUA_API int register_all_Live2DModel_Manual(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	tolua_module(tolua_S, nullptr, 0);

	tolua_beginmodule(tolua_S, nullptr);
	lua_register_Live2DModel_manual(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}





#endif