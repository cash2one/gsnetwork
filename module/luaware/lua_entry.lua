---------------------------------------------------------
--Author: wangbin
--Email:  wang70bin@163.com
--Date:	2015/5/31
--Desc:	Define the main entry of game lua
---------------------------------------------------------
--setup lua path
package.path=package.path..";lualib/?.lua;luascript/?.lua"
package.cpath=package.cpath..";luaclib/?.so" 

print(package.cpath)
---------------------------------------------------------
--include needed module
--require "game_math"
--require "game_config"
--require "game_module_test"
--require "game_class_test"
--require "game_coroutine"
require "game_udp"
---------------------------------------------------------
--Rule: No more code
