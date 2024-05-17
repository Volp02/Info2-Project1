#pragma once

#include <vector>
#include "readFile.h"

// Forward declaration of Passenger struct
struct Passenger;

/**
 * Calculates the survival proportion from a vector of Passenger data.
 *
 * @param dataSet A vector of Passenger structs containing information about passengers.
 * @return The proportion of passengers who survived (between 0.0 and 1.0).
 */
float calcSurvProp(const std::vector<Passenger>& data);
