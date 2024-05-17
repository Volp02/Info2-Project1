#include "CARTalgo.h"
//CARTalgo
#include <vector>
#include <iostream>

std::vector<Passenger> sortVectorAttribute(const std::vector<Passenger>& data, int attribute) {

    std::vector<Passenger> sortedData;
    std::vector<Passenger> helperVector;
    sortedData.assign(data.begin(), data.end());        //creates new vector and assigns data to it

    //1 = Class, 2 = Sex, 3 = Age, 4 = Sibl, 5 = Parent, 6 = Fare


    switch (attribute) {
    case (1): {
        //sort by Class with bubble sort
        int tmp = 0;
        for (int i = 0; i < sortedData.size() - 1; ++i) {
            for (int ii = 0; ii < sortedData.size() - 1 - i; ++ii) {
                if (sortedData[ii].Pclass > sortedData[ii + 1].Pclass) {
                    Passenger tmp = sortedData[ii];
                    sortedData[ii] = sortedData[ii + 1];
                    sortedData[ii + 1] = tmp;
                }
            }
        }
    }
    case (2): {
        //sort by Sex
        for (int i = 0; i < sortedData.size() - 1 ; i++){
            Passenger tmp = sortedData[i];
            if(sortedData[i].Sex == 1){
                std::vector<Passenger>::iterator ii = sortedData.begin() + i; 
                sortedData.erase(ii);
                sortedData.push_back(tmp); 
            }
        }
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
        std::cout << "Error: Invalid attribute for sorting" << std::endl;
        break;
    }

    return sortedData;
};