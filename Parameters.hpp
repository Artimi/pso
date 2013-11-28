#pragma once
#include <string>

struct Parameters
{
	double w;
	double c;
	int max_iterations;
	int dimension; 
	bool dynamic; 
	int dynamic_iterations;
	int dynamic_neighbours;
	bool fips;
	bool gbest;
	int lbest;
	std::string problem;

	Parameters(): w(0.721), c(1.193), max_iterations(1000), dimension(2), dynamic(false), dynamic_iterations(5), dynamic_neighbours(5), fips(false), gbest(false), lbest(0), 
		problem("test") {};
};

Parameters parse(int argc, char * argv[]);

std::ostream &operator<<(std::ostream &out, Parameters p);