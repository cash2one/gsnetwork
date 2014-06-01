/*******************************************************************
*  Copyright(c) 2000-2013 linghegu
*  All rights reserved.
*  Author: 	wangbin
*  Email:  	wang70bin@163.com
*  CreateTime: 2014/05/29
******************************************************************/
#ifndef __MODULE_LUAWARE_LUAINSTANCE_H__
#define __MODULE_LUAWARE_LUAINSTANCE_H__

#include "lua.hpp"
#include "luabinder.h"
class LuaInstance
{
	public:
		LuaInstance();
		~LuaInstance();
	public:

		/*
		 * init the lua enviroment,includeing io,math etc.
		 * */
		bool init();

		/*
		 *We only need to load file of head-file of lua environment
		 *The other lua file can load by useing "require"
		 * */
		bool load_lua_head_file(const char* filename);

		/*Registe all of the C/C++ fun used by lua*/
		bool register_lua_func();

		/*call function sit in lua chunk from c/c++*/
		template<typename RetT,typename T1,typename T2>
		RetT call(const char* func,T1 v1,T2 v2)const
		{
			lua_getglobal(lua_state_, func);
			
			int ret = -1;
			if (lua_isfunction(lua_state_,-1)) {
				luabinder::push(lua_state_,v1);
				luabinder::push(lua_state_,v2);
				ret = lua_pcall(lua_state_,2,1,0);
			}
			if (ret > 0) printf("lua_pcall failed:%s\n",lua_tostring(lua_state_,-1));
			if (ret < 0) printf("get func from failed:%s\n",lua_tostring(lua_state_,-1));
			
			return luabinder::pop<RetT>(lua_state_);
		}
		
		template<typename RetT>
		RetT get_var(const char* varname) const
		{
			lua_getglobal(lua_state_,varname);
			return luabinder::read<RetT>(lua_state_,-1);
		}

		void lua_perror(int errcode)const;
	private:
		void _bind_func();
	private:
		lua_State*	lua_state_;
};


static void *
l_alloc (void *ud, void *ptr, size_t osize,size_t nsize);
#endif
