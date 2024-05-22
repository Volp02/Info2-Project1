#pragma once

#include "readFile.h" // Include the header file for the Passenger struct
#include <vector>

using namespace std;

// Forward declaration of Passenger struct
struct Passenger;
struct calcMin
{
    float gini = 1;
    int attribute;
    std::vector<Passenger> linkeSeite;
    std::vector<Passenger> rechteSeite;
};

// Function declaration for splitting a vector of Passengers based on an attribute
calcMin splitVector(const std::vector<Passenger> &data, int attribute);
calcMin minGiniAttribute(const std::vector<Passenger> &data, int placement);

