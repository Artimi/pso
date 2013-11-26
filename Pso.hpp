#pragma once
#include "Parameters.hpp"
#include "Particle.hpp"
#include "MathVector.hpp"

struct Result
{
	int iterations;
	bool success;
	Particle::ParticlePtr best;
};

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
		pop_size = 20 + 2 *  dimension; //should be sqrt
	};	

	void generatePopulation();
	void addSampleNeighbours();
	void addLbestNeighbours();
	void addGbestNeighbours();

	Result fmin();

};