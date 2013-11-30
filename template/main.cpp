#include "stack1test.h"
#include "stack3test.h"
#include "stack4test.h"
#include "stack8test.h"
#include "refnonref.hpp"
#include "tracertest.h"
#include <cstdio>

int main()
{
	//test_stack3();
	//test_stack4();
	//test_stack8();
	//ref("hello");
	//nonref("hello");
	test_tracer();
	getchar();
	return 0;
}