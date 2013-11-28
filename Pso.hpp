#pragma once
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

	PSO(double (*f)(MathVector), DimensionLimits dims,
	 Parameters params): func(f), dimensionLimits(dims),
	 parameters(params)
	{
		dimension = dims.min.size();
		// pop_size = 20 + 2 *  dimension; //should be sqrt
		pop_size =4;
        generatePopulation();
        if(parameters.gbest)
            addGbestNeighbours();
        else if (parameters.lbest > 0)
            addLbestNeighbours();
        else if (parameters.dynamic)
            addSampleNeighbours();
	};	

	void generatePopulation();
	void addSampleNeighbours();
	void addLbestNeighbours();
	void addGbestNeighbours();
	Particle::ParticlePtr getBestParticle();
	Result fmin();
};