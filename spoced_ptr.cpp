#include "pch.h"
#include <iostream>

template <class T>
class scoped_ptr
{
public:
	explicit scoped_ptr(T* ptr = nullptr) :p(ptr)
	{

	}
	~scoped_ptr()
	{
		delete p;
	}
	T& operator*() const
	{
		return *ptr;
	}
	T* operator ->() cosnt
	{
		return p;
	}
	scoped_ptr& operator =(scoped_ptr const& other) = delete;
	scoped_ptr(scoped_ptr const& other) = delete;
	scoped_ptr& operator =(T* ptr)
	{
		delete p;
		p = ptr;
		return *this;
	}
private:
	T* p;
};
int main()
{

}