#pragma once

#include <vector>
#include "readFile.h" // Include the header file for the Passenger struct

// Forward declaration of Passenger struct
struct Passenger;

// Function declaration for sorting a vector of Passengers based on an attribute
std::vector<Passenger> sortVectorAttribute(const std::vector<Passenger>& data, int attribute);       //returns a vector of Passengers sorted based on an attribute: 1 = Class, 2 = Sex, 3 = Age, 4 = Sibl, 5 = Parent, 6 = Fare

