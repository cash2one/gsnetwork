#include "head.h"
#include <stdio.h>


void test_static_struct_new()
{
	static TTestStaticStructNew* test_value;

	printf("%x\n",test_value);
	if (test_value == NULL) {
		test_value = new TTestStaticStructNew;
	printf("%x\n",test_value);
	}
	
}

void test_float_int()
{
    float _f = 0.176f;
    int _i = 30 * (40/float(100));
    int _r = _i * _f;
    printf("%d\n",_r);
}
void test_multi_map()
{
    std::multimap<int,int> _map;
    _map.insert(std::make_pair(3,3));
    _map.insert(std::make_pair(3,4));
    _map.insert(std::make_pair(3,5));
    _map.insert(std::make_pair(3,6));
    _map.insert(std::make_pair(3,7));
    _map.insert(std::make_pair(4,7));
    _map.insert(std::make_pair(5,7));
    _map.insert(std::make_pair(6,7));
    _map.insert(std::make_pair(10,7));
    _map.insert(std::make_pair(15,7));
    _map.insert(std::make_pair(20,7));
    _map.insert(std::make_pair(20,7));
    _map.insert(std::make_pair(20,7));
    _map.insert(std::make_pair(20,7));
    _map.insert(std::make_pair(20,7));
    _map.insert(std::make_pair(20,7));

    for (std::multimap<int,int>::iterator _iter = _map.end(); _iter != _map.begin(); _iter--)
    {
        printf("%d,%d\n",_iter->first,_iter->second);
    }

    printf("==========================================================\n");
    for (std::multimap<int,int>::iterator _iter = _map.begin(); _iter != _map.end(); _iter++)
    {
        printf("%d,%d\n",_iter->first,_iter->second);
    }

    std::multimap<int,int>::iterator _iter = _map.find(3);
    int _cnt = _map.count(3);
    for (int _i = 0; _i < _cnt; _i++, _iter++)
    {
      //  printf("%d,%d\n",_iter->first,_iter->second);
    }
}
