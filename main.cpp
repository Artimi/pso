#include <iostream>
#include "MathVector.hpp"

int main(void)
{
	MathVector v{3.0, 3.2};
	MathVector v1{6.0, 6.4};
	std::cout << v + v1 << std::endl;
	std::cout << v * v1 << std::endl;
	std::cout << v * 10.0 << " = " << 10.0 * v << std::endl;
	return 0;
}