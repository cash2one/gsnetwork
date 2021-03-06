#include <unistd.h>
#include <stdio.h>
#include "luainstance.h"
#include <dlfcn.h>

int
main()
{
	LuaInstance lua_instance;
	lua_instance.init();
	
//	void* dl_handle = dlopen("luaclib/mytestlib.so",RTLD_LAZY);
//	if (dlopen == NULL) {
//		printf("Can not load dl\n");
//		return 1;
//	}
	
//	int (*lua_addr)(lua_State*) = 0;
//	*(void **) (&lua_addr) = dlsym(dl_handle,"luaopen_mytestlib");
	//luaopen_mytestlib(NULL);
//	if (lua_addr) { printf("symbol add %x\n",lua_addr); lua_addr(0);}
//	else printf("Can not find symbol\n");


	if (!lua_instance.load_lua_head_file("./lua_entry.lua"))
		return 0;
	
	lua_instance.register_lua_func();

	lua_instance.call<int>("getMaxLevNum","test",0);
	printf("config: %0.1f\n",lua_instance.get_config_var<float>("game_monster_config","param5"));
    long long long_num=4503599627370496;
//	printf("addNumber %d\n",lua_instance.call<int>("addNumber",10,long_num));
//	printf("addNumber %d\n",lua_instance.call<long long>("addNumber",10,4503599627370496));
	printf("addNumber %d\n",lua_instance.call<long long>("addNumber",10,18014398509482083));

	sleep(100000);
}
