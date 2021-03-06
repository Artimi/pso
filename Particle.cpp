#include <limits>
#include <algorithm>
#include "Particle.hpp"


void Particle::addSampleNeighbours(Particles particles)
{
	neighbours = particles;
    std::random_shuffle(neighbours.begin(), neighbours.end());
    neighbours.erase(neighbours.begin() + parameters.dynamic_neighbours, neighbours.end());
}
	
void Particle::updateVelocity()
{
	if (parameters.fips)
	{
		MathVector influence;
		influence.fillValues(v.size(), 0.0);
		for(auto n: neighbours)
			influence = influence + randDouble(0.0, parameters.c) * (n->p - x);
		influence = (1.0 / neighbours.size()) * influence;
		v = parameters.w * v + influence;
	}
	else
	{
		v = parameters.w * v + randDouble(0.0, parameters.c) * (p - x) + randDouble(0.0, parameters.c) * (best->p - x);
	}
}

void Particle::updatePosition()
{
	x = x + v;
	checkBoundary();
	x_fitness = func(x);
	if (x_fitness < p_fitness)
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
		if(particle->p_fitness < min)
		{
			best = particle;
			min = particle->p_fitness;
		}
	}
}

std::ostream &operator<<(std::ostream &out, Particle p)
{
    out << p.id << "#\tx = " << p.x << ",\tv = " << p.v << ",\tbest = " << p.best->id << std::endl;
    return out;
}