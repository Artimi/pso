#pragma once
#include <vector>
#include <initializer_list>
#include <iostream>
#include <stdexcept> 

double randDouble(double min, double max);

struct DimensionLimits
{
    std::vector<double> min;
    std::vector<double> max;

    DimensionLimits(int dimension, double minvalue, double maxvalue)
    {
        for(int i = 0; i < dimension; i++)
        {
            min.push_back(minvalue);
            max.push_back(maxvalue);
        }
    };
};

struct MathVector
{
    std::vector<double> vector;
    MathVector() {};
    MathVector(const MathVector& other)
    {
        vector = other.vector;    
    };
    MathVector(std::initializer_list<double> l):vector(l){};

    void randomVector(DimensionLimits);
    int size() const
    {
        return vector.size();
    };
};

std::ostream &operator<<(std::ostream &out, MathVector m);

MathVector operator+(const MathVector m1, const MathVector m2);
MathVector operator-(const MathVector m1, const MathVector m2);
MathVector operator*(const MathVector m1, const MathVector m2);

MathVector operator+(const MathVector m, const double d);
MathVector operator+(const double d, const MathVector m);
MathVector operator*(const MathVector m, const double d);
MathVector operator*(const double d ,const MathVector m);
