#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
/*
struct A
{
	virtual ~A() {};
};
struct B :A
{

};
struct C
{

};
struct C1 :C
{

};
*/
/*
class Top
{
public:
	virtual Top* clone() const = 0;
	virtual ~Top() = default;
};

class D
{
public:
	D() :answerbase_(50){}

	virtual int answer() const
	{
		return answerbase_;
	}

	virtual  D* clone() const
	{
		return new D(*this);
	}
private:
	int answerbase_;
};
class DD :public D
{
public:
	DD() :answer_(42){}
	int answer() const
	{
		return answer_;
	}
	D* clone() const override
	{
		return new DD(*this);
	}
private:
	int answer_;
};
*/
class Top
{
	virtual Top* clone() const = 0;
	//virtual ~Top() = default;
};
class D :public Top
{
public:

	D* clone() const override
	{
		return new D(*this);
	}
};
class DD :public D
{
public:
	DD() :answer_(42) {}
	DD* clone() const override
	{
		return new DD(*this);
	}
	int answer() const
	{
		return answer_;
	}

private:
	int answer_;
};
#include <typeinfo>
int main()
{
	{
		/*
		B b;
		A* a_p = &b;
		A& a_r = b;
		std::cout << typeid(*a_p).name() << "  " << typeid(a_r).name();
		std::cout << "\n";
		C1 c;
		C* c_p = &c;
		C& c_r = c;
		std::cout << typeid(*c_p).name() << "  " << typeid(c_r).name();
		*/
		std::cout << std::boolalpha;
		DD* p1 = new DD();
		//Top* p2 = p1->clone();//what is p2's dynamic type?
	//	D* p3 = p1->clone();//way we can not spoil object that points p3
	//	std::cout << typeid(*p3).name() << "\n";
		//auto p = p3;
		//std::cout << typeid(*p).name() << "\n";
	//	auto p = static_cast<DD*>(p3);
		//std::cout << typeid(p).name() << "\n";
		//std::cout << p->answer();
	}
	{
		DD d;
		D* p1 = &d;
		std::cout << typeid(*p1).name();
		
	}
}