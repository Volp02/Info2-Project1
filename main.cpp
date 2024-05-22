#include <iostream>
#include <vector>
#include <tuple>
#include <fstream>

//Testing Github

using namespace std;


#include "readFile.h"
#include "calculateGini.h"
#include "CARTalgo.h"

//test

int main()
{
    // Create a vector to store the passengers
    vector<Passenger> data;

    // Create an initial Passenger object with Num set to 0 
    Passenger* prevPassenger = new Passenger{ 0, false, 0, false, 0, 0, 0, 0.0 };

    // Loop to add new passengers
    while (prevPassenger != nullptr && prevPassenger->Num >=0)
    { // Stop when Num is negative
        if (prevPassenger->Num == 0) {
            //handle first passenger
            data.clear();
            prevPassenger = readFile(1);
            if (prevPassenger->Num <= 0) {
                cout << "an Error accured: " << prevPassenger->Num; //Num code: -1: Error opening File
                break;
            }
            data.push_back(*prevPassenger);
        }

        Passenger* newPassenger = readFile(prevPassenger->Num + 1); // Pass the next line number
        if (newPassenger == nullptr) {
            break;
        }
        else {
            data.push_back(*newPassenger); // Add the new passenger to the data vector
            //cout << "added to Database: " << newPassenger->Num << endl;
            delete prevPassenger;          // Free memory of the previous passenger
            prevPassenger = newPassenger;  // Update the pointer to the new passenger
        }

    }




    //ONLY FOR DEBUGGING \/:
    //Passenger* lastPassenger = new Passenger{ -1, false, 0, false, 0, 0, 0, 0.0 }; // Add last Passenger (Dummie)
    //data.push_back(*lastPassenger); // Add the last passenger to the data vector

    ////cout<<"age of 23 passemger: " << data[22].Age<< endl;
    ////cout<<"Num of 23 passemger: " << data[22].Num << endl;
    ////cout<<"Class of 5 passemger: " << data[40].Pclass << endl;
    ////cout<<"Num " << data[40].Num << endl;

    //Testing: print all passengers

    /*for (int i = 0; i < data.size() - 1; i++) {
        cout << "age of: " << i << ": " << data[i].Age << endl;
        cout << "Num of: " << i << ": " << data[i].Num << endl;
        cout << "Class of: " << i << ": " << data[i].Pclass << endl;
        cout << "Survived of: " << i << ": " << data[i].Surv << endl;
        cout << "Sex of: " << i << ": " << data[i].Sex << endl;
        cout << "Sibsp of: " << i << ": " << data[i].Sibl << endl;
        cout << "Parch of: " << i << ": " << data[i].Paren << endl;
        cout << "Fare of: " << i << ": " << data[i].Fare << endl;
        cout << endl;

    }
    */

    cout << "CalculateSurvivalProp:" << calcSurvProp(data) << endl;
    //implement CART Algorithm

    cout << "GiniImpurity:" << calcBinaryGini(calcSurvProp(data)) << endl;


    //data = sortVectorAttribute(data, 1);

    for (int i = 0; i < data.size() - 1; i++) {
        //cout << "age of: " << i << ": " << data[i].Age << endl;
        cout << "Num of: " << i << ": " << data[i].Num << endl;
        cout << "Class of: " << i << ": " << data[i].Pclass << endl;
        //cout << "Survived of: " << i << ": " << data[i].Surv << endl;
        //cout << "Sex of: " << i << ": " << data[i].Sex << endl;
        //cout << "Sibsp of: " << i << ": " << data[i].Sibl << endl;
        //cout << "Parch of: " << i << ": " << data[i].Paren << endl;
        //cout << "Fare of: " << i << ": " << data[i].Fare << endl;
        cout << endl;

    }

   /* data = sortVectorAttribute(data, 2);

    for (int i = 0; i < data.size() - 1; i++) {
        //cout << "age of: " << i << ": " << data[i].Age << endl;
        cout << "Num of: " << i << ": " << data[i].Num << endl;
        //cout << "Class of: " << i << ": " << data[i].Pclass << endl;
        //cout << "Survived of: " << i << ": " << data[i].Surv << endl;
        cout << "Sex of: " << i << ": " << data[i].Sex << endl;
        //cout << "Sibsp of: " << i << ": " << data[i].Sibl << endl;
        //cout << "Parch of: " << i << ": " << data[i].Paren << endl;
        //cout << "Fare of: " << i << ": " << data[i].Fare << endl;
        cout << endl;

    }
    */

    std::vector<Passenger> testData;
    testData.assign(data.begin(), data.end()-400);  //testing with smaller dataset

    testData = sortVectorAttribute(testData, 2);

        for (int i = 0; i < testData.size() - 1; i++) {
        //cout << "age of: " << i << ": " << data[i].Age << endl;
        cout << "Num of: " << i << ": " << testData[i].Num << endl;
        //cout << "Class of: " << i << ": " << data[i].Pclass << endl;
        //cout << "Survived of: " << i << ": " << data[i].Surv << endl;
        cout << "Sex of: " << i << ": " << testData[i].Sex << endl;
        //cout << "Sibsp of: " << i << ": " << data[i].Sibl << endl;
        //cout << "Parch of: " << i << ": " << data[i].Paren << endl;
        //cout << "Fare of: " << i << ": " << data[i].Fare << endl;
        cout << endl;
        }


    return 0;
}



