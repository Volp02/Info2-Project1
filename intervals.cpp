#include "intervals.h"
#include "CARTalgo.h"
#include "calculateGini.h"
#include "readFile.h" // Include the header file for the Passenger struct
#include <iostream>
#include <vector>

#define dimensions 3

using namespace std;

calcMin splitVector(const std::vector<Passenger> &data, int attribute)
{

    calcMin minGini;
    minGini.attribute = attribute;
    minGini.gini = 1.0;

    for (int i = 1; i < data.size(); ++i)
    {
        vector<Passenger> left(data.begin(), data.begin() + i);
        vector<Passenger> right(data.begin() + i, data.end());
        float weightedGini = calcWeigtedGini(left, right);

        if (weightedGini < minGini.gini)
        {
            minGini.linkeSeite = left;
            minGini.rechteSeite = right;
            minGini.gini = weightedGini;
        }
    }

    return minGini;
    

}

calcMin minGiniAttribute(const std::vector<Passenger> &data)
{
    calcMin bestSplit;
    bestSplit.gini = 1.0;

    for (int attr = 1; attr <= 6; ++attr)
    {
        vector<Passenger> sortedData = sortVectorAttribute(data, attr);
        calcMin split = splitVector(sortedData, attr);

        if (split.gini < bestSplit.gini)
        {
            bestSplit = split;
        }
    }

    return bestSplit;
}

