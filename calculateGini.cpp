#include <vector>
#include "calculateGini.h"
#include <iostream>

//#include <iostream>
using namespace std;

//calculate the survival probability of the passengers in the dataset
float calcSurvProp(const std::vector<Passenger>& dataSet) {
    float survived = 0;

    for (int i = 0; i < dataSet.size(); ++i) {
        if (dataSet[i].Surv) survived++;
    }
    return survived / static_cast<float>(dataSet.size());
}

//calculate the Gini index of the dataset
float calcBinaryGini(float P){

    return (2*P*(1-P));

}

//calculate the weighted Gini index two datasets
float calcWeigtedGini(const vector<Passenger> &leftSide, const vector<Passenger> &rightSide)
{
    int combinedSize = leftSide.size() + rightSide.size();
    float giniLeft = calcBinaryGini(calcSurvProp(leftSide));
    float giniRight = calcBinaryGini(calcSurvProp(rightSide));
    return (leftSide.size() * giniLeft + rightSide.size() * giniRight) / combinedSize;
}
