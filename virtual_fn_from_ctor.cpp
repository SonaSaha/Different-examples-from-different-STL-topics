#include "pch.h"
#include <iostream>

class Robot
{
public:
	Robot()
	{
		std::cout << "ctor of Robot\n";
		init();
	}
	virtual void init()
	{
		x = y = 0;
	}
	virtual void PrintCoordinates() const
	{
		std::cout << x << " " << y << "\n";
	}
	virtual ~Robot()
	{
		std::cout << "goodbye,cruel world\n";
	}
private:
	int x;
	int y;
};
class AdvancedRobot :public Robot
{
public:
	virtual void init() override
	{
		std::cout << "hello w";
		Robot::init();
		std::cout << "hello";
		z = 0;
	}
	virtual void PrintCoordinates() const
	{
		Robot::PrintCoordinates();
		std::cout << z << "\n";
	}
	virtual ~AdvancedRobot()
	{
		std::cout << "Hello world\n";
	}
private:
	int z;
};
struct A
{
	void f()
	{
		g();
	}
	virtual void g() const
	{
		std::cout << "A::g";
	}
	virtual ~A() //required
	{

	}
};
struct B :A
{
	virtual void g() const override
	{
		std::cout << "B::g\n";
	}
};
#include <typeinfo>
int main()
{
	Robot* r = new AdvancedRobot;
	std::cout << typeid(*r).name() << "\n";
	r->PrintCoordinates();
	delete r;
	std::cout << "\n\n\n";
	A* p = new A; 
	p->f(); //A::g
	std::cout << "\n";
	A a;
	B b;
	A* p1 = &b; //upcast
	p1->f(); //B::g
	B* p2 = static_cast<B*>(&a); //downcast
	std::cout << typeid(p2).name() << "\n";
	p2->f();//A::g///?????
}