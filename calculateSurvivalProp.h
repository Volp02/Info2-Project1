#pragma once
#include <vector>

struct Passenger {
    int Num;
    bool Surv;      //survived == true, died == false
    int Pclass;
    bool Sex;       //male == false, female == true
    int Age;
    int Sibl;       //siblings/spouses
    int Paren;      //parents/children
    float Fare;
}; 

float calcSurvProp(vector<Passenger> data);

Passenger* readFile(int line);