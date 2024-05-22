#include <vector>
#include <iostream>
#include "calculateGini.h"
#include "CARTalgo.h"
#include "intervals.h"
#include "readFile.h" // Include the header file for the Passenger struct

#define dimensions 3

using namespace std;

calcMin splitVector(const std::vector<Passenger> &data, int attribute)
{
    std::vector<Passenger> sortedData;
    std::vector<Passenger> linkeSeite;
    std::vector<Passenger> rechteSeite;

    std::vector<Passenger> *linkeSeitePtr = &linkeSeite;
    std::vector<Passenger> *rechteSeitePtr = &rechteSeite;

    std::vector < std::vector < Passenger>> splitInfo{linkeSeitePtr, rechteSeitePtr };

    calcMin minGini;
    minGini.attribute = attribute;

    for (int i = 1; i < sizeof(data); i++)
    {
        linkeSeite.assign(data.begin(), data.end() - sizeof(data) - i);
        rechteSeite.assign(data.begin()+i, data.end());

        float tmp_gini = calcBinaryGini(calcSurvProp(linkeSeite));

        if (tmp_gini < minGini.gini)
        {
            minGini.linkeSeite = linkeSeite;
            minGini.rechteSeite = rechteSeite;
            minGini.gini = tmp_gini;
        }
        std::cout << "tmpgini: " << tmp_gini << std::endl;

    }
    cout << endl << endl << "min gini: " << minGini.gini;
    cout << endl << "--------------------" << endl;
    return minGini;

    //vector f�r linke seite
    //vector f�r rechte seite

}

calcMin minGiniAttribute(const std::vector<Passenger> &data,int placement)
{
    std::vector<Passenger> helperVector;

    calcMin tempGini;
    calcMin returnGini1, returnGini2, returnGini3;


    for (int attr = 1; attr <= 6; attr++)
    {
        helperVector = sortVectorAttribute(data, attr);  
        tempGini =  splitVector(helperVector, attr);

          if (tempGini.gini < returnGini1.gini)
          {
              returnGini1 = tempGini;
          }
     }

    switch (placement)
  
{
    case 1:
    {
        return returnGini1;
    }
    case 2:
    {
        return returnGini2;
    }

    case 3:
    {
        return returnGini3;
    }
    }


}
