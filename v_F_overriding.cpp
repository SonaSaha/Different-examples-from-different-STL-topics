#include "pch.h"
#include <iostream>

struct A
{
	void f() const
	{
		std::cout << "A::f\n";
	}
	virtual void g() const
	{
		std::cout << "A::g\n";
	}
	virtual void h() const
	{
		std::cout << "A::h\n";
	}
};
struct B :A
{
	virtual void f() const
	{
		std::cout << "B::f\n";
	}
    void h() 
	{
		std::cout << "B::h\n";
	}
};
struct C :B
{
	void f() const override
	{
		std::cout << "C::f\n";
	}
	void g() const override
	{
		std::cout << "C::g\n";
	}
	void h() const override
	{
		std::cout << "C::h\n";
	}
};
#include <typeinfo>
int main()
{
	A* p = new A;
	B b;
	p->f(); //A::f
	p->g(); //A::g
	p->h(); //A::h
	std::cout << "\n\n\n";
	p = new B;
	std::cout << typeid(*p).name();
	std::cout << "\n";
	p = &b;
	std::cout << typeid(*p).name();
	std::cout << "\n";
	p->f(); //A::f
	p->g();//A::g
	p->h();//A::h

	p = new C;
	p->f(); //A::f
	p->g(); //C::g
	p->h();//C::h
	std::cout << "\n\n\n";
	B* pp = new C;
	pp->f();//C::f
	pp->B::f();//B::f
}