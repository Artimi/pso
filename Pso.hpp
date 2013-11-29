#pragma once
#include <fstream>
#include "Parameters.hpp"
#include "Particle.hpp"
#include "MathVector.hpp"

struct Result
{
	int iterations;
	bool success;
	Particle::ParticlePtr best;

    Result(): iterations(0), success(false) {};

};

std::ostream &operator<<(std::ostream &out, Result r);

struct PSO
{
	double (*func)(MathVector);
	DimensionLimits dimensionLimits;
	Parameters parameters;
	Particle::Particles population;
	int pop_size;
	int dimension;
	std::ofstream file;

	PSO(double (*f)(MathVector), DimensionLimits dims,
	 Parameters params): func(f), dimensionLimits(dims),
	 parameters(params)
	{
		dimension = dims.min.size();
		if(parameters.population == 0)
			pop_size = 20 + dimension;
		else
			pop_size = parameters.population;
		if(parameters.file != "")
		{
			file.open(parameters.file);
			headerToFile();
		}
        generatePopulation();
        if(parameters.gbest)
            addGbestNeighbours();
        else if (parameters.lbest > 0)
            addLbestNeighbours();
        else if (parameters.dynamic)
            addSampleNeighbours();
	};	

	~PSO()
	{
		if (parameters.file != "")
		{
			footerToFile();
			file.close();
		}
	}

	void generatePopulation();
	void addSampleNeighbours();
	void addLbestNeighbours();
	void addGbestNeighbours();
	Particle::ParticlePtr getBestParticle();
	void headerToFile();
	void footerToFile();
	void recordState(Result);
	Result fmin();
};