#pragma once
#include <string>

struct Parameters
{
	double w;
	double c;
	int max_iterations;
	int dimension;
	int population;
	bool dynamic; 
	int dynamic_iterations;
	int dynamic_neighbours;
	bool fips;
	bool gbest;
	int lbest;
	std::string problem;
	std::string file;

	Parameters(): w(0.7298), c(1.49618), max_iterations(1000), dimension(2), population(20 + 2 * dimension), dynamic(false), dynamic_iterations(5), dynamic_neighbours(5), fips(false), gbest(false), lbest(0), 
		problem("rosenbrock"), file("") {};
};

Parameters parse(int argc, char * argv[]);

std::ostream &operator<<(std::ostream &out, Parameters p);