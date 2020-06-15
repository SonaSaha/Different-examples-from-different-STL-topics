#include "pch.h"
#include <iostream>

template <class T>
class shared_ptr
{
public:
	shared_ptr(T* p = nullptr) :ptr(p),pcount(new int(1))
	{

	}
	template <class U>
	friend class shared_ptr;

	template <class U>
	shared_ptr(shared_ptr<U> const& other):ptr(other.ptr),pcount(other.pcount)
	{
		++*pcount;
	}
	shared_ptr(shared_ptr<T> const& other):ptr(other.ptr),pcount(other.pcount)
	{
		++*pcount;
	}
	shared_ptr& operator =(shared_ptr const& other) = delete;
	shared_ptr& operator=(T* p)
	{
		delete ptr;
		ptr = p;
		return *this;
	}
	~shared_ptr()
	{
		if (--*pcount ==0)	
 
		{
			delete ptr;
			delete pcount;
		}
	}
	T& operator*() const
	{
		return *ptr;
	}
	T* operator->() const
	{
		return ptr;
	}
	int get_count() const
	{
		return *pcount;
	}
	T get_value() const
	{
		return *ptr;
	}
private:
	int* pcount;
	T* ptr;
};
int main()
{
	shared_ptr<int> p(new int(10));
	{
		shared_ptr<int> p1 = p;
	}
	std::cout << p.get_count(); //1
}