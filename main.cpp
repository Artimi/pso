#include <iostream>
#include "Pso.hpp"
#include "Testbed.hpp"
#include "MathVector.hpp"
#include "Parameters.hpp"

void iterationTest(Parameters parameters)
{
	int success = 0;
	int runs = 0;
	int iterations = 0;
	int problem_success = 0;
	int problem_runs = 0;
	int problem_iterations = 0;
	Result r;
	DimensionLimits dims(2, -2.048, 2.048);
	std::cout << "Iteration test:" << std::endl;
	for(auto it=Tests.begin(); it!=Tests.end(); it++)
	{
		problem_runs = 0;
		problem_success = 0;
		problem_iterations = 0;
		for(int i = 0; i < 20; i++)
		{
			PSO pso(it->second, dims, parameters);
			r = pso.fmin();
			if(r.success)
			{
				problem_success += 1;
				problem_iterations += r.iterations;
			}
			problem_runs += 1;
		}
		std::cout << it->first << " success: " << (double) problem_success / problem_runs << std::endl
				<< "iteration: " << (double) problem_iterations / problem_success << std::endl;
		success += problem_success;
		runs += problem_runs;
		iterations += problem_iterations;
	}
		std::cout << "Total success: " << (double) success / runs<< std::endl
				 << "iteration: " << (double) iterations / success
				 << std::endl;
}

void dimensionTest(Parameters parameters)
{
	int success = 0;
	int runs = 0;
	int problem_success = 0;
	int problem_runs = 0;
	Result r;
	std::cout << "Dimension test:" << std::endl;
	for(auto it=Tests.begin(); it!=Tests.end(); it++)
	{
		problem_runs = 0;
		problem_success = 0;
		for(int dimension = 2; dimension <= 10; dimension++)
		{
			DimensionLimits dims(dimension, -2.048, 2.048);
			PSO pso(it->second, dims, parameters);
			r = pso.fmin();
			if(r.success)
				problem_success += 1;
			problem_runs += 1;
		}
		std::cout << it->first << " succeed: " << problem_success
				 << "/" << problem_runs <<  " = " 
				 << (double) problem_success / problem_runs << std::endl;
		success += problem_success;
		runs += problem_runs;
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
	else if(parameters.problem == "dimensionTest")
	{
		dimensionTest(parameters);
	}
	else if(parameters.problem == "iterationTest")
	{
		iterationTest(parameters);
	}
	else
	{
		std::cerr << "Problem function " << parameters.problem << " not found." << std::endl;
		exit(1);
	}
}