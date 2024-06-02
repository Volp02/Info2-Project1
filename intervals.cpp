#include "intervals.h"
#include "CARTalgo.h"
#include "calculateGini.h"
#include "readFile.h" // Include the header file for the Passenger struct
#include <iostream>
#include <vector>


using namespace std;
//splitVector splits the data into two vectors based on the attribute value and returns the resulting vectors with the lowes gini
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

//sortVectorAttribute sorts the data based on the attribute value and returns the sorted vector
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
