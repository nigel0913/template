// 类模板的特化
#include <deque>
#include <string>
#include <stdexcept>
#include "stack1.hpp"

template <>
class Stack<std::string> {
private:
	std::deque<std::string> elems;

public:
	void push(std::string const&);
	void pop();
	std::string top() const;
};