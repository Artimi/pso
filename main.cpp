#include <iostream>
#include "Pso.hpp"
#include "Testbed.hpp"
#include "MathVector.hpp"
#include "Parameters.hpp"

void test(Parameters parameters)
{
	int success = 0;
	int runs = 0;
	int problem_success = 0;
	int problem_run = 0;
	Result r;
	for(auto it=Tests.begin(); it!=Tests.end(); it++)
	{
		problem_run = 0;
		problem_success = 0;
		for(int dimension = 2; dimension <= 10; dimension++)
		{
			DimensionLimits dims(dimension, -2.048, 2.048);
			PSO pso(it->second, dims, parameters);
			r = pso.fmin();
			if(r.success)
				problem_success += 1;
			problem_run += 1;
		}
		std::cout << it->first << " succeed: " << problem_success
				 << "/" << problem_run <<  " = " 
				 << (double) problem_success / problem_run << std::endl;
		success += problem_success;
		runs += problem_run;
	}
	std::cout << "Total succeed: " << success
			 << "/" << runs <<  " = " 
			 << (double) success / runs << std::endl;
}

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
	else if(parameters.problem == "test")
	{
		test(parameters);
	}
}