#include "intervals.h"
#include "CARTalgo.h"
#include "calculateGini.h"
#include "readFile.h" // Include the header file for the Passenger struct
#include <iostream>
#include <vector>

#define dimensions 3

using namespace std;

calcMin splitVector(const std::vector<Passenger> &data, int attribute)
{
    //std::cout << "in function splitVector" << std::endl;
    
    std::vector<Passenger> sortedData;
    std::vector<Passenger> linkeSeite;
    std::vector<Passenger> rechteSeite;

    calcMin minGini;                    //create struct to store min gini
    minGini.attribute = attribute;      //store attribute in struct
    if(sizeof(data) == 0){
        std::cout << "empty data to split -> invalid: " << std::endl;
        return minGini;
    }

    minGini.gini = 1; // Initialize with Gini of the unsplit data
    //std::cout << "Gini unsplit: " << minGini.gini << std::endl;

    for (int i = 1; i < size(data); i++)
    {
        linkeSeite.clear();
        rechteSeite.clear();
        linkeSeite.insert(linkeSeite.end(), data.begin(), data.begin() + i);
        rechteSeite.insert(rechteSeite.end(), data.begin() + i, data.end());

        if (!linkeSeite.empty() || !rechteSeite.empty())
        {
            float tmp_weighted_gini = calcWeigtedGini(linkeSeite, rechteSeite);
            //std::cout << "new weighted Gini: " << tmp_weighted_gini << std::endl;
            //std::cout << "Gini split by: " << i << ": " << minGini.gini << std::endl;
            if (tmp_weighted_gini < minGini.gini)
            {
                minGini.linkeSeite = linkeSeite;
                minGini.rechteSeite = rechteSeite;
                minGini.gini = tmp_weighted_gini;
                std::cout << "new Lowes Gini: " << minGini.gini << std::endl;
                /* if (minGini.gini == 0)
                {
                    std::cout << "leaf found: " << minGini.attribute << std::endl;
                }
                */
            }
        }
        //std::cout << "tmpgini: " << tmp_gini << std::endl;
    }
    //cout << endl << endl << "min gini: " << minGini.gini;
    //cout << endl << "--------------------" << endl;


    return minGini;

}

calcMin minGiniAttribute(const std::vector<Passenger> &data, int placement)
{
    //std::cout << "in function minGiniAttribute" << std::endl;

    std::vector<Passenger> helperVector;

    calcMin tempGini;
    calcMin returnGini1; //,returnGini2, returnGini3;


    for (int attr = 1; attr <= 6; attr++)
    {
        std::cout << "Split by attribute " << attr << std::endl;

        helperVector = sortVectorAttribute(data, attr);
        tempGini = splitVector(helperVector, attr);

        if (tempGini.gini < returnGini1.gini)
        {
            returnGini1 = tempGini;
        }
    }

    /*
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
    */
    return returnGini1;
}
