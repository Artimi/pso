#include <cmath>
#include "Testbed.hpp"
#define _USE_MATH_DEFINES

double sphereFunction(MathVector x)
{
	double result = 0.0;
	for(auto elem: x.vector)
		result += elem * elem;
	return result;
}

double rosenbrockFunction(MathVector x)
{
	double result = 0.0;
	for(int i = 0; i < x.size() - 1; i++)
	{
		result += 100 * pow(x.vector[i+1] - x.vector[i], 2.0) + pow(1 - x.vector[i], 2.0);
	}
	return result;
}

double rastriginFunction(MathVector x)
{
	double result = 10.0 * x.size();
	for(auto elem: x.vector)
	{
		result += elem * elem  - 10 * std::cos(2 * M_PI * elem);
	}
	return result;
}

std::map<std::string, TestFunction> Tests{{"sphere", &sphereFunction},
										  {"rosenbrock", &rosenbrockFunction},
										  {"rastrigin", &rastriginFunction}};