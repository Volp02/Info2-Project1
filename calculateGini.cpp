#include <vector>
#include "calculateGini.h"
#include <iostream>

//#include <iostream>
using namespace std;

float calcSurvProp(const std::vector<Passenger>& dataSet) {
    int survived = 0;
    if (dataSet.size() == 0)
    {
        return 0.5;
    }

    for (int i = 0; i < dataSet.size(); ++i) {
        if (dataSet[i].Surv) survived++;
        //cout << "debug: SurvCount:" << survived << " and added: " << dataSet[i].Surv << endl;
    }
    return float (survived / dataSet.size());
}

float calcBinaryGini(float P){

    return (2*P*(1-P));

}


float calcWeigtedGini(const std::vector<Passenger> &leftSide, const std::vector<Passenger> &rightSide)
{

    if (leftSide.size() == 0 || rightSide.size() == 0)
    {
        cout << "------------ empty data in calcWeightedGini ----------" << endl;
    }


    int CombinedSize = leftSide.size() + rightSide.size();

    if (calcBinaryGini(calcSurvProp(rightSide)) + calcBinaryGini(calcSurvProp(leftSide)) == 0) {
        return 1.0;
    }

    return (leftSide.size() / CombinedSize) * calcBinaryGini(calcSurvProp(leftSide)) + (rightSide.size() / CombinedSize) * calcBinaryGini(calcSurvProp(rightSide));
}
