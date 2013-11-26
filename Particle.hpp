#pragma once
#include <memory>
#include <vector>
#include "MathVector.hpp"
#include "Parameters.hpp"


std::vector<double> randVector(DimensionLimits);

struct Particle
{
	typedef std::shared_ptr<Particle> ParticlePtr;
	typedef std::vector<ParticlePtr> Particles;

	int id;
	MathVector x;
	MathVector v;
	MathVector p;
	double x_fitness;
	double p_fitness;
	DimensionLimits dimension;
	ParticlePtr best;
	Particles neighbours;
	double (*func)(MathVector);
	Parameters parameters;
	double w;
	double c;

	Particle(int id, DimensionLimits d, double (*f)(MathVector),
		Parameters params):
	id(id),dimension(d), func(f), parameters(params)
	{
		x.randomVector(d);
		v.randomVector(d);
		p = x;
	};

	void addSampleNeighbours(Particles particles, int count); 
	
	void updateVelocity();
	void updatePosition();
	void checkBoundary();
	void updateBest();
};