#include "lua_Live2d_auto.hpp"
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
#include "../Live2DModel.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"


int lua_Live2DModel_Live2DModel_onEnter(lua_State* tolua_S)
{
    int argc = 0;
    Live2DModel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Live2DModel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Live2DModel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Live2DModel_Live2DModel_onEnter'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Live2DModel_Live2DModel_onEnter'", nullptr);
            return 0;
        }
        cobj->onEnter();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Live2DModel:onEnter",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Live2DModel_Live2DModel_onEnter'.",&tolua_err);
#endif

    return 0;
}
int lua_Live2DModel_Live2DModel_setDebugRectsNode(lua_State* tolua_S)
{
    int argc = 0;
    Live2DModel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Live2DModel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Live2DModel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Live2DModel_Live2DModel_setDebugRectsNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::DrawNode* arg0;

        ok &= luaval_to_object<cocos2d::DrawNode>(tolua_S, 2, "cc.DrawNode",&arg0, "Live2DModel:setDebugRectsNode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Live2DModel_Live2DModel_setDebugRectsNode'", nullptr);
            return 0;
        }
        cobj->setDebugRectsNode(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Live2DModel:setDebugRectsNode",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Live2DModel_Live2DModel_setDebugRectsNode'.",&tolua_err);
#endif

    return 0;
}
int lua_Live2DModel_Live2DModel_HitTest(lua_State* tolua_S)
{
    int argc = 0;
    Live2DModel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Live2DModel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Live2DModel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Live2DModel_Live2DModel_HitTest'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        const char* arg0;
        double arg1;
        double arg2;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "Live2DModel:HitTest"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_number(tolua_S, 3,&arg1, "Live2DModel:HitTest");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "Live2DModel:HitTest");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Live2DModel_Live2DModel_HitTest'", nullptr);
            return 0;
        }
        bool ret = cobj->HitTest(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Live2DModel:HitTest",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Live2DModel_Live2DModel_HitTest'.",&tolua_err);
#endif

    return 0;
}
int lua_Live2DModel_Live2DModel_StartRandomMotion(lua_State* tolua_S)
{
    int argc = 0;
    Live2DModel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Live2DModel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Live2DModel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Live2DModel_Live2DModel_StartRandomMotion'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        const char* arg0;
        int arg1;
        std::function<void ()> arg2;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "Live2DModel:StartRandomMotion"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "Live2DModel:StartRandomMotion");

        do {
			// Lambda binding for lua is not supported.
			assert(false);
		} while(0)
		;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Live2DModel_Live2DModel_StartRandomMotion'", nullptr);
            return 0;
        }
        cobj->StartRandomMotion(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Live2DModel:StartRandomMotion",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Live2DModel_Live2DModel_StartRandomMotion'.",&tolua_err);
#endif

    return 0;
}
int lua_Live2DModel_Live2DModel_drawDebugRects(lua_State* tolua_S)
{
    int argc = 0;
    Live2DModel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Live2DModel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Live2DModel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Live2DModel_Live2DModel_drawDebugRects'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Live2DModel_Live2DModel_drawDebugRects'", nullptr);
            return 0;
        }
        cobj->drawDebugRects();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Live2DModel:drawDebugRects",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Live2DModel_Live2DModel_drawDebugRects'.",&tolua_err);
#endif

    return 0;
}
int lua_Live2DModel_Live2DModel_setModelColor(lua_State* tolua_S)
{
    int argc = 0;
    Live2DModel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Live2DModel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Live2DModel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Live2DModel_Live2DModel_setModelColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color4B arg0;

        ok &=luaval_to_color4b(tolua_S, 2, &arg0, "Live2DModel:setModelColor");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Live2DModel_Live2DModel_setModelColor'", nullptr);
            return 0;
        }
        cobj->setModelColor(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Live2DModel:setModelColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Live2DModel_Live2DModel_setModelColor'.",&tolua_err);
#endif

    return 0;
}
int lua_Live2DModel_Live2DModel_SetRandomExpression(lua_State* tolua_S)
{
    int argc = 0;
    Live2DModel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Live2DModel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Live2DModel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Live2DModel_Live2DModel_SetRandomExpression'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Live2DModel_Live2DModel_SetRandomExpression'", nullptr);
            return 0;
        }
        cobj->SetRandomExpression();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Live2DModel:SetRandomExpression",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Live2DModel_Live2DModel_SetRandomExpression'.",&tolua_err);
#endif

    return 0;
}
int lua_Live2DModel_Live2DModel_init(lua_State* tolua_S)
{
    int argc = 0;
    Live2DModel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Live2DModel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Live2DModel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Live2DModel_Live2DModel_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "Live2DModel:init"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Live2DModel_Live2DModel_init'", nullptr);
            return 0;
        }
        bool ret = cobj->init(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Live2DModel:init",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Live2DModel_Live2DModel_init'.",&tolua_err);
#endif

    return 0;
}
int lua_Live2DModel_Live2DModel_updateViewMatrix(lua_State* tolua_S)
{
    int argc = 0;
    Live2DModel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Live2DModel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Live2DModel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Live2DModel_Live2DModel_updateViewMatrix'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 5) 
    {
        double arg0;
        double arg1;
        double arg2;
        double arg3;
        double arg4;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "Live2DModel:updateViewMatrix");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "Live2DModel:updateViewMatrix");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "Live2DModel:updateViewMatrix");

        ok &= luaval_to_number(tolua_S, 5,&arg3, "Live2DModel:updateViewMatrix");

        ok &= luaval_to_number(tolua_S, 6,&arg4, "Live2DModel:updateViewMatrix");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Live2DModel_Live2DModel_updateViewMatrix'", nullptr);
            return 0;
        }
        cobj->updateViewMatrix(arg0, arg1, arg2, arg3, arg4);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Live2DModel:updateViewMatrix",argc, 5);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Live2DModel_Live2DModel_updateViewMatrix'.",&tolua_err);
#endif

    return 0;
}
int lua_Live2DModel_Live2DModel_setOpcaity(lua_State* tolua_S)
{
    int argc = 0;
    Live2DModel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Live2DModel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Live2DModel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Live2DModel_Live2DModel_setOpcaity'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "Live2DModel:setOpcaity");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Live2DModel_Live2DModel_setOpcaity'", nullptr);
            return 0;
        }
        cobj->setOpcaity(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Live2DModel:setOpcaity",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Live2DModel_Live2DModel_setOpcaity'.",&tolua_err);
#endif

    return 0;
}
int lua_Live2DModel_Live2DModel_getCanvasRect(lua_State* tolua_S)
{
    int argc = 0;
    Live2DModel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Live2DModel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Live2DModel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Live2DModel_Live2DModel_getCanvasRect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Live2DModel_Live2DModel_getCanvasRect'", nullptr);
            return 0;
        }
        cocos2d::Rect ret = cobj->getCanvasRect();
        rect_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Live2DModel:getCanvasRect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Live2DModel_Live2DModel_getCanvasRect'.",&tolua_err);
#endif

    return 0;
}
int lua_Live2DModel_Live2DModel_draw(lua_State* tolua_S)
{
    int argc = 0;
    Live2DModel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Live2DModel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Live2DModel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Live2DModel_Live2DModel_draw'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Renderer* arg0;
        cocos2d::Mat4 arg1;
        unsigned int arg2;

        ok &= luaval_to_object<cocos2d::Renderer>(tolua_S, 2, "cc.Renderer",&arg0, "Live2DModel:draw");

        ok &= luaval_to_mat4(tolua_S, 3, &arg1, "Live2DModel:draw");

        ok &= luaval_to_uint32(tolua_S, 4,&arg2, "Live2DModel:draw");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Live2DModel_Live2DModel_draw'", nullptr);
            return 0;
        }
        cobj->draw(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Live2DModel:draw",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Live2DModel_Live2DModel_draw'.",&tolua_err);
#endif

    return 0;
}
int lua_Live2DModel_Live2DModel_onDraw(lua_State* tolua_S)
{
    int argc = 0;
    Live2DModel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Live2DModel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Live2DModel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Live2DModel_Live2DModel_onDraw'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Mat4 arg0;
        unsigned int arg1;

        ok &= luaval_to_mat4(tolua_S, 2, &arg0, "Live2DModel:onDraw");

        ok &= luaval_to_uint32(tolua_S, 3,&arg1, "Live2DModel:onDraw");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Live2DModel_Live2DModel_onDraw'", nullptr);
            return 0;
        }
        cobj->onDraw(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Live2DModel:onDraw",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Live2DModel_Live2DModel_onDraw'.",&tolua_err);
#endif

    return 0;
}
int lua_Live2DModel_Live2DModel_SetExpression(lua_State* tolua_S)
{
    int argc = 0;
    Live2DModel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Live2DModel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Live2DModel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Live2DModel_Live2DModel_SetExpression'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "Live2DModel:SetExpression"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Live2DModel_Live2DModel_SetExpression'", nullptr);
            return 0;
        }
        cobj->SetExpression(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Live2DModel:SetExpression",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Live2DModel_Live2DModel_SetExpression'.",&tolua_err);
#endif

    return 0;
}
int lua_Live2DModel_Live2DModel_OnTap(lua_State* tolua_S)
{
    int argc = 0;
    Live2DModel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Live2DModel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Live2DModel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Live2DModel_Live2DModel_OnTap'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        double arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "Live2DModel:OnTap");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "Live2DModel:OnTap");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Live2DModel_Live2DModel_OnTap'", nullptr);
            return 0;
        }
        cobj->OnTap(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Live2DModel:OnTap",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Live2DModel_Live2DModel_OnTap'.",&tolua_err);
#endif

    return 0;
}
int lua_Live2DModel_Live2DModel_StartMotion(lua_State* tolua_S)
{
    int argc = 0;
    Live2DModel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Live2DModel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Live2DModel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Live2DModel_Live2DModel_StartMotion'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        const char* arg0;
        int arg1;
        int arg2;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "Live2DModel:StartMotion"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "Live2DModel:StartMotion");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "Live2DModel:StartMotion");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Live2DModel_Live2DModel_StartMotion'", nullptr);
            return 0;
        }
        cobj->StartMotion(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 4) 
    {
        const char* arg0;
        int arg1;
        int arg2;
        bool arg3;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "Live2DModel:StartMotion"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "Live2DModel:StartMotion");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "Live2DModel:StartMotion");

        ok &= luaval_to_boolean(tolua_S, 5,&arg3, "Live2DModel:StartMotion");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Live2DModel_Live2DModel_StartMotion'", nullptr);
            return 0;
        }
        cobj->StartMotion(arg0, arg1, arg2, arg3);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Live2DModel:StartMotion",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Live2DModel_Live2DModel_StartMotion'.",&tolua_err);
#endif

    return 0;
}
int lua_Live2DModel_Live2DModel_LoadAssets(lua_State* tolua_S)
{
    int argc = 0;
    Live2DModel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Live2DModel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Live2DModel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Live2DModel_Live2DModel_LoadAssets'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        const char* arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "Live2DModel:LoadAssets"); arg0 = arg0_tmp.c_str();

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "Live2DModel:LoadAssets"); arg1 = arg1_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Live2DModel_Live2DModel_LoadAssets'", nullptr);
            return 0;
        }
        cobj->LoadAssets(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Live2DModel:LoadAssets",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Live2DModel_Live2DModel_LoadAssets'.",&tolua_err);
#endif

    return 0;
}
int lua_Live2DModel_Live2DModel_SetTouchEnable(lua_State* tolua_S)
{
    int argc = 0;
    Live2DModel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Live2DModel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Live2DModel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Live2DModel_Live2DModel_SetTouchEnable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "Live2DModel:SetTouchEnable");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Live2DModel_Live2DModel_SetTouchEnable'", nullptr);
            return 0;
        }
        cobj->SetTouchEnable(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Live2DModel:SetTouchEnable",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Live2DModel_Live2DModel_SetTouchEnable'.",&tolua_err);
#endif

    return 0;
}
int lua_Live2DModel_Live2DModel_transformScreenX(lua_State* tolua_S)
{
    int argc = 0;
    Live2DModel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Live2DModel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Live2DModel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Live2DModel_Live2DModel_transformScreenX'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "Live2DModel:transformScreenX");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Live2DModel_Live2DModel_transformScreenX'", nullptr);
            return 0;
        }
        double ret = cobj->transformScreenX(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Live2DModel:transformScreenX",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Live2DModel_Live2DModel_transformScreenX'.",&tolua_err);
#endif

    return 0;
}
int lua_Live2DModel_Live2DModel_transformScreenY(lua_State* tolua_S)
{
    int argc = 0;
    Live2DModel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Live2DModel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Live2DModel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Live2DModel_Live2DModel_transformScreenY'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "Live2DModel:transformScreenY");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Live2DModel_Live2DModel_transformScreenY'", nullptr);
            return 0;
        }
        double ret = cobj->transformScreenY(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Live2DModel:transformScreenY",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Live2DModel_Live2DModel_transformScreenY'.",&tolua_err);
#endif

    return 0;
}
int lua_Live2DModel_Live2DModel_transformViewY(lua_State* tolua_S)
{
    int argc = 0;
    Live2DModel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Live2DModel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Live2DModel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Live2DModel_Live2DModel_transformViewY'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "Live2DModel:transformViewY");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Live2DModel_Live2DModel_transformViewY'", nullptr);
            return 0;
        }
        double ret = cobj->transformViewY(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Live2DModel:transformViewY",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Live2DModel_Live2DModel_transformViewY'.",&tolua_err);
#endif

    return 0;
}
int lua_Live2DModel_Live2DModel_transformViewX(lua_State* tolua_S)
{
    int argc = 0;
    Live2DModel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Live2DModel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Live2DModel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Live2DModel_Live2DModel_transformViewX'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "Live2DModel:transformViewX");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Live2DModel_Live2DModel_transformViewX'", nullptr);
            return 0;
        }
        double ret = cobj->transformViewX(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Live2DModel:transformViewX",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Live2DModel_Live2DModel_transformViewX'.",&tolua_err);
#endif

    return 0;
}
int lua_Live2DModel_Live2DModel_onExit(lua_State* tolua_S)
{
    int argc = 0;
    Live2DModel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Live2DModel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Live2DModel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Live2DModel_Live2DModel_onExit'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Live2DModel_Live2DModel_onExit'", nullptr);
            return 0;
        }
        cobj->onExit();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Live2DModel:onExit",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Live2DModel_Live2DModel_onExit'.",&tolua_err);
#endif

    return 0;
}
int lua_Live2DModel_Live2DModel_OnDrag(lua_State* tolua_S)
{
    int argc = 0;
    Live2DModel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Live2DModel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Live2DModel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Live2DModel_Live2DModel_OnDrag'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        double arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "Live2DModel:OnDrag");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "Live2DModel:OnDrag");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Live2DModel_Live2DModel_OnDrag'", nullptr);
            return 0;
        }
        cobj->OnDrag(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Live2DModel:OnDrag",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Live2DModel_Live2DModel_OnDrag'.",&tolua_err);
#endif

    return 0;
}
int lua_Live2DModel_Live2DModel_getCanvasSize(lua_State* tolua_S)
{
    int argc = 0;
    Live2DModel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Live2DModel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Live2DModel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_Live2DModel_Live2DModel_getCanvasSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Live2DModel_Live2DModel_getCanvasSize'", nullptr);
            return 0;
        }
        cocos2d::Size ret = cobj->getCanvasSize();
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Live2DModel:getCanvasSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Live2DModel_Live2DModel_getCanvasSize'.",&tolua_err);
#endif

    return 0;
}
int lua_Live2DModel_Live2DModel_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"Live2DModel",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "Live2DModel:create"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Live2DModel_Live2DModel_create'", nullptr);
            return 0;
        }
        Live2DModel* ret = Live2DModel::create(arg0);
        object_to_luaval<Live2DModel>(tolua_S, "Live2DModel",(Live2DModel*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "Live2DModel:create",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_Live2DModel_Live2DModel_create'.",&tolua_err);
#endif
    return 0;
}
int lua_Live2DModel_Live2DModel_constructor(lua_State* tolua_S)
{
    int argc = 0;
    Live2DModel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_Live2DModel_Live2DModel_constructor'", nullptr);
            return 0;
        }
        cobj = new Live2DModel();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"Live2DModel");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Live2DModel:Live2DModel",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_Live2DModel_Live2DModel_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_Live2DModel_Live2DModel_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Live2DModel)");
    return 0;
}

int lua_register_Live2DModel_Live2DModel(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"Live2DModel");
    tolua_cclass(tolua_S,"Live2DModel","Live2DModel","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"Live2DModel");
        tolua_function(tolua_S,"new",lua_Live2DModel_Live2DModel_constructor);
        tolua_function(tolua_S,"onEnter",lua_Live2DModel_Live2DModel_onEnter);
        tolua_function(tolua_S,"setDebugRectsNode",lua_Live2DModel_Live2DModel_setDebugRectsNode);
        tolua_function(tolua_S,"HitTest",lua_Live2DModel_Live2DModel_HitTest);
        tolua_function(tolua_S,"StartRandomMotion",lua_Live2DModel_Live2DModel_StartRandomMotion);
        tolua_function(tolua_S,"drawDebugRects",lua_Live2DModel_Live2DModel_drawDebugRects);
        tolua_function(tolua_S,"setModelColor",lua_Live2DModel_Live2DModel_setModelColor);
        tolua_function(tolua_S,"SetRandomExpression",lua_Live2DModel_Live2DModel_SetRandomExpression);
        tolua_function(tolua_S,"init",lua_Live2DModel_Live2DModel_init);
        tolua_function(tolua_S,"updateViewMatrix",lua_Live2DModel_Live2DModel_updateViewMatrix);
        tolua_function(tolua_S,"setOpcaity",lua_Live2DModel_Live2DModel_setOpcaity);
        tolua_function(tolua_S,"getCanvasRect",lua_Live2DModel_Live2DModel_getCanvasRect);
        tolua_function(tolua_S,"draw",lua_Live2DModel_Live2DModel_draw);
        tolua_function(tolua_S,"onDraw",lua_Live2DModel_Live2DModel_onDraw);
        tolua_function(tolua_S,"SetExpression",lua_Live2DModel_Live2DModel_SetExpression);
        tolua_function(tolua_S,"OnTap",lua_Live2DModel_Live2DModel_OnTap);
        tolua_function(tolua_S,"StartMotion",lua_Live2DModel_Live2DModel_StartMotion);
        tolua_function(tolua_S,"LoadAssets",lua_Live2DModel_Live2DModel_LoadAssets);
        tolua_function(tolua_S,"SetTouchEnable",lua_Live2DModel_Live2DModel_SetTouchEnable);
        tolua_function(tolua_S,"transformScreenX",lua_Live2DModel_Live2DModel_transformScreenX);
        tolua_function(tolua_S,"transformScreenY",lua_Live2DModel_Live2DModel_transformScreenY);
        tolua_function(tolua_S,"transformViewY",lua_Live2DModel_Live2DModel_transformViewY);
        tolua_function(tolua_S,"transformViewX",lua_Live2DModel_Live2DModel_transformViewX);
        tolua_function(tolua_S,"onExit",lua_Live2DModel_Live2DModel_onExit);
        tolua_function(tolua_S,"OnDrag",lua_Live2DModel_Live2DModel_OnDrag);
        tolua_function(tolua_S,"getCanvasSize",lua_Live2DModel_Live2DModel_getCanvasSize);
        tolua_function(tolua_S,"create", lua_Live2DModel_Live2DModel_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(Live2DModel).name();
    g_luaType[typeName] = "Live2DModel";
    g_typeCast["Live2DModel"] = "Live2DModel";
    return 1;
}
TOLUA_API int register_all_Live2DModel(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,nullptr,0);
	tolua_beginmodule(tolua_S,nullptr);

	lua_register_Live2DModel_Live2DModel(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

#endif
