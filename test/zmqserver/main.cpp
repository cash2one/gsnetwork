#include "zmqwrap.h"
#include <iostream>
//

int main(int argc,char* argv[])
{
	CZmqWrapper _zmqwrap(MAX_ZMQ_THREAD_NUMBER);

	_zmqwrap.addBindNode("tcp://*:5555");

	_zmqwrap.run();
}
