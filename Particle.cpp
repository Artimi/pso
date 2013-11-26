#include <limits>
#include "Particle.hpp"


void Particle::addSampleNeighbours(Particles particles, int count)
{
	return;
}
	
void Particle::updateVelocity()
{
	if (best->p_fitness > p_fitness)
		v = w * v + randDouble(0.0, c) * (p - x) + randDouble(0.0, c) * (best->p - x);
	else
		v = w * v + randDouble(0.0, c) * (p - x);
}

void Particle::updatePosition()
{
	x = x + v;
	checkBoundary();
	x_fitness = func(x);
	if (x_fitness > p_fitness)
	{
		p = x;
		p_fitness = x_fitness;
	}
}

void Particle::checkBoundary()
{
	for(int i = 0; i < x.size(); i++)
	{
		if(x.vector[i] < dimension.min[i])
		{
			x.vector[i] = dimension.min[i];
			v.vector[i] = 0.0;
		}
		if(x.vector[i] > dimension.max[i])
		{
			x.vector[i] = dimension.max[i];
			v.vector[i] = 0.0;
		}
	}
}
void Particle::updateBest()
{
	double min = std::numeric_limits<double>::infinity();
	for(auto particle: neighbours)
	{
		if(particle->x_fitness < min)
			best = particle;
	}
}