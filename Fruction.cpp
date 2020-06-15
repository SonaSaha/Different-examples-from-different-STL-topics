#include "pch.h"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <algorithm>

class Fruction
{
public:
	typedef int IntType;
	typedef double DoubleType;
public:
	Fruction() :Fruction(0, 1)
	{

	}
	Fruction(int num, int denom) :numerator(num), denominator(denom)
	{
		if (denom == 0)
		{
			throw std::invalid_argument("DEnomiantor connot be 0");
		}
		normalize();
	}
	explicit Fruction(const std::string& s):Fruction()
	{
		int whole_parts = 0;
		double num;
		int denom = 1;
		int currnum;
		auto it = std::find(s.cbegin(), s.cend(), '.');
		if (it == s.cend())
		{
			numerator = std::stoi(s);
			denominator = 1;
		}
		else
		{
			if (s[0] != 0)
			{
				whole_parts = std::stoi(s.substr(0, (it - s.cbegin())));
			}
			++it;
			if (*it == '(')
			{
				++it;
				std::string s1 = s.substr((it - s.cbegin()), s.cend() - it - 1);
				num = std::stoi(s1);
				int size = s1.size();
				denom = num;
				while (size)
				{
					num /= 10;
					--size;
				}
				num *= denom;
				while (num * 10 < 1)
				{
					num *= 10;
				}
				currnum = num;
				if (num - currnum < 0.5)
				{
					num = currnum;
				}
				else
				{
					++num;
					currnum = num;
					num = currnum;
				}
			}
			else
			{
				std::string s1 = s.substr((it - s.cbegin()), s.cend() - it);
				num = std::stoi(s1);
				int size = s1.size();
				while (size)
				{
					denom *= 10;
					--size;
				}
			}
			numerator = num + whole_parts * denom;
			denominator = denom;
			normalize();
		}
	}
	int get_numerator() const
	{
		return numerator;
	}
	int get_denominator() const
	{
		return denominator;
	}
	void assign(const int num, const int denom)
	{
		numerator = num;
		denominator = denom;
		normalize();
	}
	Fruction operator+(const Fruction& f1) const
	{
		Fruction f;
		int lcm = LCM();
		f.numerator = ((lcm / denominator)*numerator + (lcm / f1.denominator)*f1.numerator);
		f.denominator = lcm;
		f.normalize();
		return f;
	}
	Fruction operator- (const Fruction& f1) const
	{
		Fruction f;
		int lcm = LCM();
		f.numerator = (lcm / denominator)*numerator - (lcm / f1.denominator)*f1.numerator;
		f.denominator = lcm;
		f.normalize();
		return f;
	}
	Fruction operator*(const Fruction& f1) const
	{
		Fruction f;
		f.numerator = numerator * f1.numerator;
		f.denominator = denominator * f1.denominator;
		f.normalize();
		return f;
	}
	Fruction operator/(const Fruction& f1) const
	{
		Fruction f;
		f.numerator = numerator * f1.denominator;
		f.denominator = denominator * f1.numerator;
		f.normalize();
		return f;
	}
	Fruction Inverse() const
	{
		Fruction f;
		if (numerator == 0)
		{
			throw std::exception("Division by 0");
		}
		f.numerator = denominator;
		f.denominator = numerator;
		return f;
	}
	Fruction Opposite() const
	{
		Fruction f;
		f.numerator = -numerator;
		f.denominator = denominator;
		return f;
	}
	explicit operator double() const
	{
		return (double)numerator / denominator;
	}
	explicit operator bool() const
	{
		return numerator != 0;
	}
	std::string to_decimal_string() const
	{
		int whole_parts;
		int num;
		if (numerator >= denominator)
		{
			whole_parts = numerator / denominator;
			num = numerator - (whole_parts * denominator);
		}
		std::string decimal = std::to_string(whole_parts);
		if (num == 0)
			return decimal;
		decimal.push_back('.');
		std::cout << "test";
		while (num < denominator)
		{
			num *= 10;
			decimal.push_back('0');
		}
		decimal.pop_back();
		if (num%denominator == 0)
		{
			decimal.append(std::to_string(num / denominator));
			return decimal;
		}
		else
		{
			decimal.push_back('(');
			int rem;
			int first = num / denominator;
			decimal.append(std::to_string(first));
			while (1)
			{
				rem = num / denominator;
				num -= (num / denominator)*denominator;
				if (first == rem)
				{
					decimal.push_back(')');
					return decimal;
				}
				decimal.append(std::to_string(rem));
				while (num < denominator)
				{
					num *= 10;
				}
			}
		}
	}

private:
	int numerator;
	int denominator;
	void normalize()
	{
		if (denominator < 0)  //??
		{
			numerator = -numerator;
			denominator = -denominator;
		}
		if (denominator != 1)
		{
			int gcd = GCD();
			numerator /= gcd;
			denominator /= gcd;
		}
	}
	int GCD() const
	{
		int min = std::min(numerator, denominator);
		int max = std::max(numerator, denominator);
		int r;
		while (min != 0)
		{
			r = max % min;
			max = min;
			min = r;
		}
		return max;
	}
	int LCM() const
	{
		return (numerator*denominator) / GCD();
	}
};
std::istream& operator>>(std::istream& in, Fruction& f)
{
	char number;
	std::cin.get(number);
	int numerator = 0;
	int denominator = 0;
	bool t = true;
	char next = std::cin.peek();
	do {
		if (t)
		{
			numerator = (numerator + number) * 10;
		}
		if (!t)
		{
			denominator = (denominator + number) * 10;
		}
		next = std::cin.peek();
		if (next == '/')
		{
			t = false;
		}
		std::cin.get(number);
	} while (number != ' ');
	numerator /= 10;
	denominator /= 10;
	if (denominator == 0)
	{
		throw std::runtime_error("Division by 0");
	}
	f.assign(numerator, denominator);
	return in;
}
std::ostream& operator<<(std::ostream& out, const Fruction& f)
{
	out << f.get_numerator();
	if (f.get_denominator() != 1)
	{
		out << "/" << f.get_denominator();
	}
	return out;
}
void test(const Fruction& f1, const Fruction& f2)
{
	Fruction f;
	std::cout << f1 + f2 << "\n"; //output 1
	std::cout << f1 - f2 << "\n";//output 0
	std::cout << f1 * f2 << "\n";//output 1/4
	std::cout << f1 / f2 << "\n";//output 1
	Fruction f_inverse = f1.Inverse();
	std::cout << f_inverse << "\n";//output 2
	Fruction f_opposite = f1.Opposite();
	std::cout << f_opposite << "\n";//output -1/2

}
int main()
{
	try
	{
		Fruction f1(1, 2);
		Fruction f2(1, 2);
		test(f1, f2);
		//Fruction f;
		//std::sin >> f; 
		//Fruction f(0);
		if (!f1)
		{
			std::cout << "Yes\n";
		}
		std::string s = "0.(3)";
		std::cout << (Fruction)s;
		//std::cout << f1.to_decimal_string();// << " " << f2.to_decimal_string(); //??
		std::cout << "\n";

	}
	catch (std::exception & e)
	{
		std::cout << "std::exception caught " << e.what();
	}

}