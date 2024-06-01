#include "CARTalgo.h"
//CARTalgo
#include <iostream>
#include <vector>
#include "readFile.h"       //for Passenger struct
#include "intervals.h"      //for struct calcMin
#include "calculateGini.h"       //for minGiniAttribute and CalcProb

using namespace std;


vector<Passenger> sortVectorAttribute(const vector<Passenger> &data, int attribute)
{
    //std::cout << "in function sortVectorAttribute" << std::endl;

    std::vector<Passenger> sortedData;
    //std::vector<Passenger> helperVector;
    //std::vector<Passenger> helperVector2;

    if (size(data) == 0)
    {
        return sortedData;
    }

    sortedData.assign(data.begin(), data.end()); //creates new vector and assigns data to it

    //1 = Class, 2 = Sex, 3 = Age, 4 = Sibl, 5 = Parent, 6 = Fare


    switch (attribute)
    {
    case (1):
    {
        //sort by Pclass

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
        break;
    }
    case (2):
        {
        //sort by Sex

        int temp;
        do
        {
            temp = sortedData[0].Sex;
            for (std::size_t j = 1; j < sortedData.size(); j++)
            {
                if (sortedData[j].Sex < sortedData[j - 1].Sex)
                { // vertauschen
                    temp = sortedData[j - 1].Sex;
                    sortedData[j - 1].Sex = sortedData[j].Sex;
                    sortedData[j].Sex = temp;
                }
            }
        } while (temp != static_cast<int>(sortedData[0].Sex)); // false = keine Vertauschung
        break;
    }

    case (3):
        {
            //sort by Age
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

        break;
    }
    case (4):
        {
            //sort by Sibl
            
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
            

        break;
    }
    case (5):
        {
        //sort by Parent
            
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
            

        break;
    }
    case (6):
        {
        //sort by Fare
             
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
            

        break;
    }
    default:
    {
        std::cout << "Error: Invalid attribute for sorting" << std::endl;
        break;
    };
    }

    return sortedData;
}

float getSplitValue(const calcMin &split, int attribute)
{
    switch (attribute)
    {
    case 1:
        return static_cast<float>(split.linkeSeite.back().Pclass);
    case 2:
        return static_cast<float>(split.linkeSeite.back().Sex);
    case 3:
        return static_cast<float>(split.linkeSeite.back().Age);
    case 4:
        return static_cast<float>(split.linkeSeite.back().Sibl);
    case 5:
        return static_cast<float>(split.linkeSeite.back().Paren);
    case 6:
        return static_cast<float>(split.linkeSeite.back().Fare);
    default:
        throw invalid_argument("Invalid attribute");
    }
}

bool trainCart(TreeNode *prevNode, int desiredDepth,const vector<Passenger> &data){

    std::cout << "\033[2J\033[1;1H";        //clear Terminal


    cout << "Training node at depth " << prevNode->depth << " with " << data.size() << " data points." << endl;
    
    if (data.empty())
    {
        cout << "Empty data set, marking node as leaf." << endl;
        prevNode->isLeaf = true;
        return false;
    }

    float survProp = calcSurvProp(data);
    if (prevNode->depth >= desiredDepth || survProp == 0 || survProp == 1)
    {
        //cout << "Pure node or depth limit reached, marking node as leaf." << endl;
        prevNode->isLeaf = true;
        return false;
    }

    TreeNode *leftNode = new TreeNode();
    TreeNode *rightNode = new TreeNode();
    calcMin split = minGiniAttribute(data);

    leftNode->prev = prevNode;
    rightNode->prev = prevNode;

    prevNode->left = leftNode;
    prevNode->right = rightNode;

    prevNode->attribute = split.attribute;
    prevNode->SplitValue = getSplitValue(split, split.attribute);
    prevNode->predSurvival = calcSurvProp(data);

    leftNode->predSurvival = calcSurvProp(split.linkeSeite);
    rightNode->predSurvival = calcSurvProp(split.rechteSeite);

    leftNode->depth = prevNode->depth + 1;
    rightNode->depth = prevNode->depth + 1;



    trainCart(leftNode, desiredDepth, split.linkeSeite);
    trainCart(rightNode, desiredDepth, split.rechteSeite);


    //cout << "predicted Survival Rate for current node: " << prevNode->predSurvival << endl;
    //cout << "Gini for current node: " << calcBinaryGini(calcSurvProp(data)) << endl;
    //cout << "WeightedGini for current node: " << calcWeigtedGini(split.linkeSeite, split.rechteSeite) << endl;
    return true;

    //std::cout << tempGini<std::cout<<"split value: "<<prevNode->SplitValue<<std::endl;<std::endl;

}
