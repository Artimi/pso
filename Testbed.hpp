#pragma once
#include <map>
#include "MathVector.hpp"

double sphereFunction(MathVector);
double rosenbrockFunction(MathVector x);
double rastriginFunction(MathVector x);
typedef double (*TestFunction)(MathVector);
extern std::map<std::string, TestFunction> Tests;
