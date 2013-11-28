#include <iostream>
#include "Pso.hpp"
#include "Testbed.hpp"
#include "MathVector.hpp"
#include "Parameters.hpp"

int main(int argc, char * argv[])
{
	Parameters parameters = parse(argc, argv);
	std::cout << parameters;
	return 0;
	std::vector<double> dmin{-1.0, -1.0};
	std::vector<double> dmax{1.0, 1.0};
	DimensionLimits dims;
	dims.min = dmin;
	dims.max = dmax;

	Parameters p;
	PSO pso(&sphereFunction, dims, p);
	Result r = pso.fmin();
	std::cout << r << std::endl;
}