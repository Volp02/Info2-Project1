#include <vector>
#include "calculateGini.h"

//#include <iostream>
//using namespace std;

float calcSurvProp(const std::vector<Passenger>& dataSet) {
    int survived = 0;

    for (int i = 0; i < dataSet.size(); ++i) {
        if (dataSet[i].Surv) survived++;
        //cout << "debug: SurvCount:" << survived << " and added: " << dataSet[i].Surv << endl;
    }
    return float(survived) / dataSet.size();
}

float calcBinaryGini(float P){

    return (2*P*(1-P));

}
