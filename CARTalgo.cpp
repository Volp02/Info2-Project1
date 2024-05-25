#include "CARTalgo.h"
//CARTalgo
#include <iostream>
#include <vector>

std::vector<Passenger> sortVectorAttribute(const std::vector<Passenger> &data, int attribute)
{

    std::vector<Passenger> sortedData;
    std::vector<Passenger> helperVector;
    std::vector<Passenger> helperVector2;
    sortedData.assign(data.begin(), data.end()); //creates new vector and assigns data to it

    //1 = Class, 2 = Sex, 3 = Age, 4 = Sibl, 5 = Parent, 6 = Fare


    switch (attribute)
    {
    case (1):
    {
        //sort by Pclass
        {
            int temp;
            do
            {
                temp = sortedData[0].Pclass;
                for (std::size_t j = 1; j < sortedData.size(); j++)
                {
                    if (sortedData[j].Pclass < sortedData[j - 1].Pclass)
                    { // vertauschen
                        temp = sortedData[j - 1].Pclass;
                        sortedData[j - 1].Pclass = sortedData[j].Pclass;
                        sortedData[j].Pclass = temp;
                    }
                }
            } while (temp != sortedData[0].Pclass); // false = keine Vertauschung
        }


    case (2):
    {
        //sort by Sex
        for (int i = sortedData.size() - 1; i >= 0; i--)
        {

            if (sortedData[i].Sex)
            {
                Passenger tmp = sortedData[i];
                helperVector.push_back(tmp);
            }
            if (!sortedData[i].Sex)
            {
                Passenger tmp = sortedData[i];
                helperVector2.push_back(tmp);
            };
        }
        sortedData.clear();

        for (int i = 0; i < helperVector.size(); i++)
        {
            sortedData.push_back(helperVector[i]);
        }

        for (int i = 0; i < helperVector2.size(); i++)
        {
            sortedData.push_back(helperVector2[i]);
        }
    }

    case (3):
    {
        //sort by Age

        {
            int temp;
            do
            {
                temp = sortedData[0].Age;
                for (std::size_t j = 1; j < sortedData.size(); j++)
                {
                    if (sortedData[j].Age < sortedData[j - 1].Age)
                    { // vertauschen
                        temp = sortedData[j - 1].Age;
                        sortedData[j - 1].Age = sortedData[j].Age;
                        sortedData[j].Age = temp;
                    }
                }
            } while (temp != sortedData[0].Age); // false = keine Vertauschung
        }


        break;
    }
    case (4):
    {
        //sort by Sibl
        {
            int temp;
            do
            {
                temp = sortedData[0].Sibl;
                for (std::size_t j = 1; j < sortedData.size(); j++)
                {
                    if (sortedData[j].Sibl < sortedData[j - 1].Sibl)
                    { // vertauschen
                        temp = sortedData[j - 1].Sibl;
                        sortedData[j - 1].Sibl = sortedData[j].Sibl;
                        sortedData[j].Sibl = temp;
                    }
                }
            } while (temp != sortedData[0].Sibl); // false = keine Vertauschung
        }

        break;
    }
    case (5):
    {
        //sort by Parent
        {
            int temp;
            do
            {
                temp = sortedData[0].Paren;
                for (std::size_t j = 1; j < sortedData.size(); j++)
                {
                    if (sortedData[j].Paren < sortedData[j - 1].Paren)
                    { // vertauschen
                        temp = sortedData[j - 1].Paren;
                        sortedData[j - 1].Paren = sortedData[j].Paren;
                        sortedData[j].Paren = temp;
                    }
                }
            } while (temp != sortedData[0].Paren); // false = keine Vertauschung
        }

        break;
    }
    case (6):
    {
        //sort by Fare
         {
            float temp;
            do
            {
                temp = sortedData[0].Fare;
                for (std::size_t j = 1; j < sortedData.size(); j++)
                {
                    if (sortedData[j].Fare < sortedData[j - 1].Fare)
                    { // vertauschen
                        temp = sortedData[j - 1].Fare;
                        sortedData[j - 1].Fare = sortedData[j].Fare;
                        sortedData[j].Fare = temp;
                    }
                }
            } while (temp != sortedData[0].Fare); // false = keine Vertauschung
        }

        break;
    }
    default:
    {
        std::cout << "Error: Invalid attribute for sorting" << std::endl;
        break;
    };
    }

        
    }

    return sortedData;
}
