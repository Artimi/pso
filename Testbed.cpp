#include "Testbed.hpp"

double sphereFunction(MathVector x)
{
	double result = 0.0;
	for(auto elem: x.vector)
		result += elem * elem;
	return result;
}