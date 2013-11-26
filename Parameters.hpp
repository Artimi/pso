#pragma once
#include <string>

struct Parameters
{
	double w;
	double c;
	bool dynamic; 
	int dynamic_iterations;
	int dynamic_neighbours;
	bool fips;
	bool gbest;
	int lbest;
	std::string problem;

	Parameters(): w(0.721), c(1.193), dynamic(false), dynamic_iterations(5), dynamic_neighbours(5), fips(false), gbest(true), lbest(2), 
		problem("test") {};
};