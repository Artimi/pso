#include <random>
#include <chrono>
#include "MathVector.hpp"

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine generator(seed);
std::uniform_real_distribution<double> distribution(0,1);

double randDouble(double min, double max)
{
	return (max - min) * distribution(generator) + min;
}

void MathVector::randomVector(DimensionLimits d)
{
	vector.clear();
	for(unsigned int i = 0; i < d.min.size(); i++)
		vector.push_back(randDouble(d.min[i], d.max[i]));
}

void MathVector::fillValues(unsigned dimension, double value)
{
	vector.clear();
	for (unsigned i = 0; i < dimension; i++)
		vector.push_back(value);
}

std::ostream &operator<<(std::ostream &out, MathVector m)
{
    out << "[ ";
    for(auto elem: m.vector)
        out << elem << " ";
    out << "]";
    return out;
}

MathVector operator+(const MathVector m1, const MathVector m2)
{
	if(m1.size() != m2.size())
		throw std::length_error("Vectors size must match");
	MathVector result = m1;
	for(int i = 0; i < result.size(); i++)
		result.vector[i] += m2.vector[i];
	return result;
}

MathVector operator-(const MathVector m1, const MathVector m2)
{
	if(m1.size() != m2.size())
		throw std::length_error("Vectors size must match");
	MathVector result = m1;
	for(int i = 0; i < result.size(); i++)
		result.vector[i] -= m2.vector[i];
	return result;
}

MathVector operator*(const MathVector m1, const MathVector m2)
{
	if(m1.size() != m2.size())
		throw std::length_error("Vectors size must match");
	MathVector result = m1;
	for(int i = 0; i < result.size(); i++)
		result.vector[i] *= m2.vector[i];
	return result;
}

MathVector operator+(const MathVector m, const double d)
{
	MathVector result = m;
	for(int i = 0; i < result.size(); i++)
		result.vector[i] += d;
	return result;
}

MathVector operator+(const double d, const MathVector m)
{
	return m + d;
}

MathVector operator*(const MathVector m, const double d)
{
	MathVector result = m;
	for(int i = 0; i < result.size(); i++)
		result.vector[i] *= d;
	return result;
}

MathVector operator*(const double d ,const MathVector m)
{
	return m * d;
}

