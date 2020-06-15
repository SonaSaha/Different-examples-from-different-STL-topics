#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

struct Rectangle
{
	int length;
	int width;
	bool is_square()
	{
		return length == width;
	}
};
int main()
{
	std::vector<Rectangle> Rectangles = { {1,2},{2,2},{3,3},{1,1},{6,5} };
	std::cout << std::count_if(Rectangles.begin(), Rectangles.end(), std::bind(&Rectangle::is_square, std::placeholders::_1));
	std::cout << "\n";
	std::cout << std::count_if(Rectangles.begin(), Rectangles.end(), [](Rectangle rec) {return rec.is_square(); });
}