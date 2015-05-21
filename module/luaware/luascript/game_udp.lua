local socket = require "socket"
local lib = require("struct")

 stringstr = "abcdefghik"
 print(string.sub(stringstr,1,10))

 print(2^52 + 10000)

-- tests for long long
if lib.unpack("i8", string.rep("\255", 8)) ~= -1 then
  print("no support for 'long long'")
else
  local lim = 800
  assert(lib.pack(">i8", 2^52) == "\0\16\0\0\0\0\0\0")
  local t = {}; for i = 1, lim do t[i] = 2^52 end
  assert(lib.pack(">" .. string.rep("i8", lim), unpack(t, 1, lim))
                  == string.rep("\0\16\0\0\0\0\0\0", lim))
  assert(lib.pack("<i8", 2^52 - 1) == "\255\255\255\255\255\255\15\0")
  assert(lib.pack(">i8", -2^52 - 1) == "\255\239\255\255\255\255\255\255")
  assert(lib.pack("<i8", -2^52 - 1) == "\255\255\255\255\255\255\239\255")

  assert(lib.unpack(">i8", "\255\239\255\255\255\255\255\255") == -2^52 - 1)
  assert(lib.unpack("<i8", "\255\255\255\255\255\255\239\255") == -2^52 - 1)
  assert(lib.unpack("<i8", "\255\255\254\255\255\255\015\000") ==
                            2^52 - 1 - 2^16)
  assert(lib.unpack(">i8", "\000\015\255\255\255\255\254\254") == 2^52 - 258)

  local fmt = ">" .. string.rep("i16", lim)
  local t1 = {lib.unpack(fmt, lib.pack(fmt, unpack(t)))}
  assert(t1[#t1] == 16*lim + 1  and #t == #t1 - 1)
  for i = 1, lim do assert(t[i] == t1[i]) end
  print'+'
end



--[[



local port = 8003
local udpsocket = socket.udp()
-- udpsocket.settimeout(0)
udpsocket:setsockname('*', port)

local running = true

while running do
    data, msg_or_ip, port_or_nil = udpsocket:receivefrom()
    if data then
         print(string.len(data))
         print(structlib.unpack("!1<c2HHBBH",string.sub(data,1,10)))
    end
end
]]
