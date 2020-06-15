#include "pch.h"
#include <iostream>
//using namespace std;

class A
{
public:
	A()
	{
		std::cout << "default ctor of A\n";
	}
	~A()
	{
		std::cout << "dtor of A\n";
	}
	A(const A& other)
	{
		std::cout << "copy ctor of A\n";
	}
	A& operator = (const A& rhs)
	{
		std::cout << "operator = of A\n";
		return *this;
	}
};
class B
{
	A a;
	B& operator = (const B&) = delete;
};

void f(A a)
{
	std::cout << "f is called\n";
}

class Fraction
{
public:
	Fraction(int num = 0, int denom = 1)
		:numerator_(num), denominator_(denom)
	{
		//...
	}
	Fraction operator - (const Fraction& f) const
	{
		Fraction result;
		//...
		return result;
	}
private:
	int numerator_;
	int denominator_;


};

Fraction operator + (const Fraction& f1, const Fraction& f2)
{
	Fraction result;
	//...
	return result;
}


int main()
{
	/*char ch, peekCh;
	cout << "Enter a string: ";

	cin.get(ch);
	cout << "After first cin.get(ch): ";
	cout << "ch = " << ch << endl;

	cin.get(ch);
	cout << "After second cin.get(ch): ";
	cout << "ch = " << ch << endl;
	
	//put the character back in the stream
	cin.putback(ch);
	cin.get(ch);
	cout << "After putback, the third cin.get(ch): ";
	cout << "ch = " << ch << endl;
	
	//get next character in stream
	//without removing it
	peekCh = cin.peek();
	cin.get(ch);
	
	cout << "After peek, the fourth cin.get(ch): ";
	cout << "ch = " << ch << endl;
	cout << "And peekCh = " << peekCh << endl;
	A a;
	A b(a);
	A c = a;
	f(b);
	b = c;
	B b1;
	B b2 = b1;
	*/

	return 0;
}