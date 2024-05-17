#include "CARTalgo.h"
//CARTalgo
#include <vector>
#include <iostream>

using namespace std;


vector<Passenger> sortVectorAttribute(const vector<Passenger>& data, int attribute) {

    vector<Passenger> sortedData;
    sortedData.assign(data.begin(), data.end());        //creates new vector and assigns data to it

    //1 = Class, 2 = Sex, 3 = Age, 4 = Sibl, 5 = Parent, 6 = Fare


    switch (attribute) {
    case (1): {
        //sort by Class

    }
    case (2): {
        //sort by Sex

    }
    case (3): {
        //sort by Age

        break;
    }
    case (4): {
        //sort by Sibl

        break;
    }
    case (5): {
        //sort by Parent

        break;
    }
    case (6): {
        //sort by Fare

        break;
    }
    default:
        std::cout << "Error: Invalid attribute for sorting" << endl;
        break;
    }

    return sortedData;
};