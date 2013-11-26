#ifndef __APP_LUA_H__
#define __APP_LUA_H__

#ifdef __cplusplus
extern "C"
{
#endif
#include "tolua++.h"
#ifdef __cplusplus
}
#endif

class AppLua
{
public:
    /** 注册扩展 */
    static void registerExtend(lua_State *tolua_S);
    
};

#endif // __APP_LUA_H__
