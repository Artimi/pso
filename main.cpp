#include <iostream>
#include "Pso.hpp"
#include "Testbed.hpp"
#include "MathVector.hpp"
#include "Parameters.hpp"


int main(int argc, char * argv[])
{
	Parameters parameters = parse(argc, argv);
	auto it = Tests.find(parameters.problem);
	if(it != Tests.end())	
	{
		DimensionLimits dims(parameters.dimension, -2.048, 2.048);
		PSO pso(it->second, dims, parameters);
		Result r = pso.fmin();
		std::cout << it->first << ":" << std::endl
				  << r;
	}
}