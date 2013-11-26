#pragma once
#include <vector>
#include <initializer_list>
#include <iostream>
#include <stdexcept> 

struct MathVector
{
    std::vector<double> vector;
    MathVector();
    MathVector(std::initializer_list<double> l):vector(l){};

    int size() const
    {
        return vector.size();
    }
};

std::ostream &operator<<(std::ostream &out, MathVector m);

MathVector operator+(const MathVector m1, const MathVector m2);
MathVector operator*(const MathVector m1, const MathVector m2);

MathVector operator+(const MathVector m, const double d);
MathVector operator+(const double d, const MathVector m);
MathVector operator*(const MathVector m, const double d);
MathVector operator*(const double d ,const MathVector m);