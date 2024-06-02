#include <vector>
#include "calculateGini.h"
#include <iostream>

//#include <iostream>
using namespace std;

float calcSurvProp(const std::vector<Passenger>& dataSet) {
    int survived = 0;

    for (int i = 0; i < dataSet.size(); ++i) {
        if (dataSet[i].Surv) survived++;
    }
    return static_cast<float>(survived) / static_cast<float>(dataSet.size());
}

float calcBinaryGini(float P){

    return (2*P*(1-P));

}


float calcWeigtedGini(const vector<Passenger> &leftSide, const vector<Passenger> &rightSide)
{
    int combinedSize = leftSide.size() + rightSide.size();
    float giniLeft = calcBinaryGini(calcSurvProp(leftSide));
    float giniRight = calcBinaryGini(calcSurvProp(rightSide));
    return (leftSide.size() * giniLeft + rightSide.size() * giniRight) / combinedSize;
}
