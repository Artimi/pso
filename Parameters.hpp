#pragma once
#include <string>

struct Parameters
{
	double w;
	double c;
	int max_iterations;
	bool dynamic; 
	int dynamic_iterations;
	int dynamic_neighbours;
	bool fips;
	bool gbest;
	int lbest;
	std::string problem;

	Parameters(): w(0.721), c(1.193), max_iterations(1000), dynamic(false), dynamic_iterations(5), dynamic_neighbours(5), fips(false), gbest(true), lbest(0), 
		problem("test") {};
};