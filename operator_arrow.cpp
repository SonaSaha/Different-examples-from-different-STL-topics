#include "pch.h"
#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <vector>
#include <utility>
class Arrow_operator
{
public:
	typedef int type;
public:
	Arrow_operator() :pointer(new int(5))
	{

	}
	type operator -> ()
	{
		return *pointer;
	}
private:
	type* pointer;
};
struct A
{
	int c;
	char b;
	void f() {};

	int* operator->()
	{
		return p;
	}
	
};
int main()
{
	Arrow_operator op;
	std::cout << op.operator->();
	std::vector<A> a;
	std::vector<A>::iterator it = a.begin();
	A b;
	int a = 1;
	b->a;

}