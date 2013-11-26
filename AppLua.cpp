#include "AppLua.h"

void AppLua::registerExtend(lua_State *_state)
{
	tolua_beginmodule(_state, NULL);
	tolua_endmodule(_state);
}
