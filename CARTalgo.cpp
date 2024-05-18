#include "CARTalgo.h"
//CARTalgo
#include <vector>
#include <iostream>


std::vector<Passenger> swapNext(const std::vector<Passenger>& data, int i) {
    
    std::vector<Passenger> swapedData;
    swapedData.assign(data.begin(), data.end());

    Passenger tmp = swapedData[i];
    std::cout << "swapped Num: " << swapedData[i].Num << " <> " << swapedData[i + 1].Num << std::endl;
    std::cout << "swapped: " << swapedData[i].Pclass << " <> " << swapedData[i + 1].Pclass << std::endl;
    swapedData[i] = swapedData[i + 1];
    swapedData[i + 1] = tmp;
        
    return swapedData;
}


std::vector<Passenger> sortVectorAttribute(const std::vector<Passenger>& data, int attribute) {

    std::vector<Passenger> sortedData;
    std::vector<Passenger> helperVector;
    std::vector<Passenger> helperVector2;
    sortedData.assign(data.begin(), data.end());        //creates new vector and assigns data to it

    //1 = Class, 2 = Sex, 3 = Age, 4 = Sibl, 5 = Parent, 6 = Fare


    switch (attribute) {
    case (1): {
        for (int pass = 0; pass < sortedData.size() - 1; ++pass) {
            bool swapped = false; // Flag to check if any swaps occurred in this pass

            for (int i = 0; i < sortedData.size() - 1 - pass; ++i) { // Use i for inner loop
                if (sortedData[i].Pclass < sortedData[i + 1].Pclass) {
                    swapNext(sortedData, i);
                    swapped = true;
                }
            }

            if (!swapped) break; // If no swaps in this pass, the array is already sorted
        }

        for (int i = 0; i < sortedData.size(); i++) { // Correct loop condition for printing
            std::cout << sortedData[i].Num << ": " << sortedData[i].Pclass << std::endl;
        }


    }
    case (2): {
        //sort by Sex
        for (int i = sortedData.size() - 1; i >= 0; i--) {

            if (sortedData[i].Sex) {
                Passenger tmp = sortedData[i];
                helperVector.push_back(tmp);
            }
            if(!sortedData[i].Sex) {
                Passenger tmp = sortedData[i];
                helperVector2.push_back(tmp);
            };
        }
        sortedData.clear();

        for (int i = 0; i < helperVector.size(); i++){
            sortedData.push_back(helperVector[i]);
        }

        for (int i = 0; i < helperVector2.size(); i++) {
            sortedData.push_back(helperVector2[i]);
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