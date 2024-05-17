#include <vector>
#include "calculateSurvivalProp.h"


float calcSurvProp(const std::vector<Passenger>& dataSet) {
    int survived = 0;

    for (int i = 0; i < dataSet.size(); ++i) {
        survived += dataSet[i].Surv;
    // Process the passenger data here
    } 
    return survived / dataSet.size();
}
