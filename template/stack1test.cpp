#include "stack1test.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include "stack1.hpp"

void test_stack1()
{
	try {
		Stack<int> intStack;
		Stack<std::string> stringStack;

		intStack.push(7);
		std::cout << intStack.top() << std::endl;

		stringStack.push("hello");
		std::cout << stringStack.top() << std::endl;
		stringStack.pop();
		stringStack.pop();
	}
	catch (std::exception const& ex) {
		std::cerr << "Exception: " << ex.what() << std::endl;
		return ;
	}
}