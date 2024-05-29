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


calcMin splitVector(const std::vector<Passenger> &data, int attribute); // Function declaration for the splitVector function
//SplitVector returns split vector with smalles gini value

calcMin minGiniAttribute(const std::vector<Passenger> &data);
//minGiniAttribute returns the vector sorted by attribute and split with the smallest resulting gini value
//with placement returns the 1, 2 or 3 best option (to be implemented)

