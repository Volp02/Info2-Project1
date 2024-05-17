#pragma once
//CARTalgo
#include <vector>
#include "readFile.h" // Include the header file for the Passenger struct

// Forward declaration of Passenger struct
struct Passenger;

/**
 * Calculates the survival proportion from a vector of Passenger data.
 *
 * @param dataSet A vector of Passenger structs containing information about passengers.
 * @return The proportion of passengers who survived (between 0.0 and 1.0).
 * 
 * calculates Gini index for binary classification
 */
float calcSurvProp(const std::vector<Passenger>& data);

float calcBinaryGini(float P);