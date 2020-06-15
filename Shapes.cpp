#include "pch.h"
#include <iostream>
#include <sstream>
#include <boost/math/constants/constants.hpp>

class Shape
{
public:
	typedef int param_type;
public:
	virtual param_type Area() const = 0;
	virtual param_type Permiter() const = 0;
	virtual bool ContainsPoint(param_type x, param_type y) = 0;
	virtual void Move(param_type dx, param_type dy) = 0;
	virtual void PrintInfo(std::ostream& out) const = 0;
	virtual Shape* Clone() const = 0;
	virtual ~Shape()
	{

	}

};
class Rectangle :public Shape
{
public:
	Rectangle(param_type l, param_type r,param_type t,param_type b) :left_(l), right_(r),top_(t),bottom_(b)
	{

	}
	~Rectangle()
	{

	}
	param_type Area() const override
	{
		return (right_ - left_) * (bottom_ - top_);
	}
	param_type Permiter() const override
	{
		return 2 * ((right_ - left_) + (bottom_ - top_));
	}
	void PrintInfo(std::ostream& out) const override
	{
		out << "Rectange at topleft (" << left_ << "," << top_ << ")\n";
	}
	bool ContainsPoint(param_type x, param_type y) override
	{
		return x >= left_ && x <= right_ && y >= top_ && y <= bottom_;
	}
	void Move(param_type dx, param_type dy) override
	{
		left_ += dx;
		right_ += dx;
		top_ += dy;
		bottom_ += dy;
	}
	Rectangle* Clone() const
	{
		return new Rectangle(*this);
	}
private:
	param_type top_;
	param_type bottom_;
	param_type left_;
	param_type right_;
};
class Circle :public Shape
{
public:
	Circle(param_type x, param_type y, param_type r) :x_(x), y_(y), radius_(r)
	{

	}
	~Circle()
	{

	}
	param_type Area() const override
	{
		return  boost::math::constants::pi<double>() * radius_ * radius_;
	}
	param_type Permiter() const override
	{
		return 2 * boost::math::constants::pi<double>() * radius_;
	}
	void PrintInfo(std::ostream& out) const
	{
		out << "Circle at (" << x_ << "," << y_ << ") with radius " << radius_ << "\n";
	}
	bool ContainsPoint(param_type x, param_type y) override
	{
		const double dx = x - x_;
		const double dy = y - y_;
		return dx * dx + dy * dy <= radius_ * radius_;
	}
	void Move(param_type dx, param_type dy) override
	{
		x_ += dx;
		y_ += dy;

	}
	Circle* Clone() const
	{
		return new Circle(*this);
	}
private:
	param_type x_;
	param_type y_;
	param_type radius_;
};
class Trinagle :public Shape
{
public:
	param_type Area() const override
	{
		return 0;
	}
	~Trinagle()
	{

	}
	param_type Permiter() const override
	{
		return 0;
	}
	void PrintInfo() const
	{

	}
	bool ContainsPoint(param_type x, param_type y) override
	{
		return false;
	}
private:
	param_type x1_;
	param_type y1_;
	param_type x2_;
	param_type y2_;
	param_type x2_;
	param_type y2_;
};
class Process
{
public:
	Process() :selected_shape(nullptr)
	{

	}
	void ProcessCommand(std::istream& in)
	{
		std::string keyword;
		std::cin >> keyword;
		if (keyword == "Add")
		{

		}
		else if (keyword == "Select")
		{

		}
		else if (keyword == "Move")
		{

		}
		else if (keyword == "Print")
		{

		}
		else if (keyword == "Clone")
		{

		}
		else
		{
			throw std::invalid_argument("Unknown Command");
		}
	}
	void ProcessAddShape(std::istream& in)
	{

	}
private:
	std::vector<Shape*> shapes;
	Shape* selected_shape;

};
int main()
{

}