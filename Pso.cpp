#include "Pso.hpp"

void PSO::generatePopulation()
{
	Particle::ParticlePtr p;
	for(int i = 0; i < dimension; i++)
	{
		Particle::ParticlePtr p(new Particle(i, dimensionLimits, func, parameters));
		population.push_back(p);
	}
}
void PSO::addSampleNeighbours()
{
	for(auto particle: population)
	{
		particle->addSampleNeighbours(population, parameters.dynamic_neighbours);
	}
}

void PSO::addLbestNeighbours()
{
	for(int i = 0; i < pop_size; i++)
	{
		int down = (i - parameters.lbest) % pop_size;
		int up = (i + parameters.lbest + 1) % pop_size;
		Particle::Particles n;
		if (down < up)
		{
			n.insert(n.begin(), population.begin() + down, population.begin() + up);
		}
		else
		{
			n.insert(n.begin(), population.begin(), population.begin() + up);
			n.insert(n.end(), population.begin() + down, population.end());
		}
		population[i]-> neighbours = n;
		std::cout << i << ": " << "down: " << down << "up: " << up << std::endl;
	}
}

void PSO::addGbestNeighbours()
{
	for(auto particle: population)
	{
		particle->neighbours = population;
	}
}

Result fmin()
{
	Result result;
	return result;
}