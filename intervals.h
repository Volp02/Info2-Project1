#pragma once

#include "CARTalgo.h"
#include "intervals.cpp" // Include the header file for the Passenger struct
#include <vector>


// Function declaration for splitting a vector of Passengers based on an attribute
vector<std::vector<Passenger>> splitVector(const std::vector<Passenger> &data, int attribute);
