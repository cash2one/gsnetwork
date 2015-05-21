#include <stdio.h>
#include <string.h>
#include "lua.hpp"

extern "C" 
int add(lua_State* L) 
{
    long long op1 = (long long)luaL_checknumber(L,1);
//    double op2 = (double)luaL_checknumber(L,2);
    long long op2 = (long long)luaL_checknumber(L,2);
    printf("xxxx %d %ld \n",op1,op2);
    lua_pushnumber(L,op1 + op2);
    return 1;
}
 
extern "C" 
int sub(lua_State* L)
{
    double op1 = luaL_checknumber(L,1);
    double op2 = luaL_checknumber(L,2);
    lua_pushnumber(L,op1 - op2);
    return 1;
}
static luaL_Reg math_lib_name[] = { 
    {"add_two_num", add},
    {"sub_two_num", sub},
    {NULL, NULL} 
}; 
 
extern "C"
int luaopen_game_math_lib(lua_State* L) 
{
    const char* libName = "gamemathlib";
	luaL_newlib(L,math_lib_name);
    return 1;
}
