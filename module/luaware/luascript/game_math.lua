local mathlib = require "game_math_lib"
assert(mathlib)

local modulename = ...  --filename's prefix such as takplace.lua

function getMaxLevNum(valI,valII)
	--print("valis"..valI..valII)
end

function addNumber(a,b)
    local test_long= b;
    test_long = test_long + 1000
	return mathlib.add_two_num(a,test_long)					--defined through func lib
end

function test_c_lib(v1,v2)
end


local simplefunctionset = require "function_base"
print(simplefunctionset.multi_add(3,10,33))
print(simplefunctionset.add(3000,100))
print(simplefunctionset.sub(3,10))
print(simplefunctionset.devide(3,10))
print(simplefunctionset.multi(3,10))
