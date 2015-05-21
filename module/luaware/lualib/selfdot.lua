Class = {}
Class.__index = Class
 
function Class:new(x,y)   --Class.new(self,x,y)
    local temp = {}
    setmetatable(temp, Class)
    temp.x = x
    temp.y = y
    return temp
end
 
function Class:test()
    print(self.x,self.y)
end
 
 
object = Class:new(10,20)  --Class.new(self,10,10)
 
object:test()
