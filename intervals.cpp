#include <vector>
#include "CARTalgo.h"
#include "intervals.h"
#include "readFile.h" // Include the header file for the Passenger struct

using namespace std;



vector<std::vector<Passenger>> splitVector(const std::vector<Passenger> &data, int attribute)
{
    std::vector<Passenger> sortedData;
    std::vector<Passenger> linkeSeite;
    std::vector<Passenger> rechteSeite;

    std::vector<Passenger> *linkeSeitePtr = &linkeSeite;
    std::vector<Passenger> *rechhteSeitePtr = &rechteSeite;

    std::vector < std::vector < Passenger>> splitInfo{linkeSeitePtr, rechhteSeitePtr };

    sortedData.assign(data.begin(), data.end()); //creates new vector and assigns data to it


    return splitInfo;

    //vector f�r linke seite
    //vector f�r rechte seite

}
