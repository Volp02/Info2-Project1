#pragma once

#include "readFile.h" // Include the header file for the Passenger struct
#include <vector>

using namespace std;

// Function declaration for splitting a vector of Passengers based on an attribute
vector<std::vector<Passenger>> splitVector(const std::vector<Passenger> &data, int attribute);
