#include "MathVector.hpp"

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
