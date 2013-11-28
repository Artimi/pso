#include <limits>
#include "Pso.hpp"

std::ostream &operator<<(std::ostream &out, Result r)
{
    out << "Success: " << r.success << std::endl
        << "iterations: " << r.iterations << std::endl
        << "Best x: " << r.best->x << std::endl
        << "Best x fitness: " << r.best->x_fitness << std::endl;
    return out;
}


void PSO::generatePopulation()
{
	Particle::ParticlePtr p;
	for(int i = 0; i < pop_size; i++)
	{
		Particle::ParticlePtr p(new Particle(i, dimensionLimits, func, parameters));
		population.push_back(p);
	}
}
void PSO::addSampleNeighbours()
{
	for(auto particle: population)
	{
		particle->addSampleNeighbours(population);
	}
}

void PSO::addLbestNeighbours()
{
	for(int i = 0; i < pop_size; i++)
	{
		int down = (i - parameters.lbest) % pop_size;
		if(down < 0)
			down = pop_size + down;
		int up = (i + parameters.lbest + 1) % pop_size;
		Particle::Particles n;
		if (down < up)
		{
			n.insert(n.end(), population.begin() + down, population.begin() + i);
			n.insert(n.end(), population.begin() + i + 1, population.begin() + up);
		}
		else
		{
			if (i < up)
			{  
				n.insert(n.end(), population.begin(), population.begin() + i);
				n.insert(n.end(), population.begin() + i +1 , population.begin() + up);
				n.insert(n.end(), population.begin() + down, population.end());
			}
			else
			{

				n.insert(n.end(), population.begin(), population.begin() + up);
				n.insert(n.end(), population.begin() + down, population.begin() + i);
				n.insert(n.end(), population.begin() + i + 1, population.end());
			}
		}
		population[i]-> neighbours = n;
	}
}

void PSO::addGbestNeighbours()
{
	for(auto particle: population)
	{
		particle->neighbours = population;
	}
}

Particle::ParticlePtr PSO::getBestParticle()
{
    double min = std::numeric_limits<double>::infinity();
    Particle::ParticlePtr bestParticle;
    for(auto particle: population)
    {
        if (particle->x_fitness < min)
        {
            bestParticle = particle;
            min = particle->x_fitness;
        }
    }
    return bestParticle;
}

Result PSO::fmin()
{
	Result result;
    while(not result.success and result.iterations <= parameters.max_iterations)
    {
        for(auto particle: population)
        {
            particle->updateBest();
        }
        for(auto particle: population)
        {
            particle->updateVelocity();
            particle->updatePosition();
        }
        result.iterations += 1;
        result.best = getBestParticle();
        if(result.best->x_fitness < 1e-10)
            result.success = true;
        if(parameters.dynamic and parameters.dynamic_iterations % result.iterations == 0)
        {
        	addSampleNeighbours();
        }
    }
	return result;
}