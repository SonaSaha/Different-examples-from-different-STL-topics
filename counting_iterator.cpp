#include "pch.h"
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
class counting_iterator : public std::iterator<std::input_iterator_tag, int>
{
public:
	counting_iterator( int num):i(num)
	{
	}
	int get() const
	{
		return i;
	}
	int operator *() const
	{
		return get();
	}
	counting_iterator operator ++()
	{
		++i;
		return *this;
	}
	counting_iterator operator ++(int)
	{
		counting_iterator old(*this);
		++*this;
		return old;
	}
private:
	int i;
};
bool operator == (counting_iterator i1, counting_iterator i2)
{
	return i1.get() == i2.get();
}
bool operator!=(const counting_iterator& it1,const counting_iterator& it2)
{
	return !(it1.get() == it2.get());
}
int main()
{
	counting_iterator it1(10);
	counting_iterator it2(20);
	std::vector<int> v(it1, it2); //v is {10, 11, … 19, 20};
	std::ostream_iterator<int> out_it(std::cout, ",");
	std::copy(v.begin(), v.end(), out_it);
}