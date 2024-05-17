#pragma once
#pragma once

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

Passenger* readFile(int line);