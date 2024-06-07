#include "CARTalgo.h"
//CARTalgo
#include <iostream>
#include <vector>
#include "readFile.h"       //for Passenger struct
#include "intervals.h"      //for struct calcMin
#include "calculateGini.h"       //for minGiniAttribute and CalcProb

using namespace std;

//sortVectorAttribute sorts the data by attribute
vector<Passenger> sortVectorAttribute(const vector<Passenger> &data, int attribute)
{
  
    std::vector<Passenger> sortedData;

    if (sizeof(data) == 0)
    {
        return sortedData;
    }

    sortedData.assign(data.begin(), data.end()); //creates new vector and assigns data to it

    //switch case for bubble sorting by attribute
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

//getSplitValue returns the value of the split attribute (value at which the data is split)
float getSplitValue(const calcMin &split, int attribute)
{
    //1 = Class, 2 = Sex, 3 = Age, 4 = Sibl, 5 = Parent, 6 = Fare

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

//trainCart trains the decision tree
bool trainCart(TreeNode *prevNode, int desiredDepth,const vector<Passenger> &data){

    std::cout << "\033[2J\033[1;1H";        //clear Terminal


    cout << "Training node at depth " << prevNode->depth << " with " << data.size() << " data points." << endl << endl;
    //set class of previous node
    prevNode->predSurvival = calcSurvProp(data) >= 0.5;

    if (data.empty())
    {
        cout << "Empty data set, marking node as leaf." << endl;
        prevNode->isLeaf = true;
        return false;
    }

    float survProp = calcSurvProp(data);
    
    if (prevNode->depth >= desiredDepth || survProp == 0 || survProp == 1)
    {
        cout << "Pure node or depth limit reached, marking node as leaf." << endl;
        prevNode->isLeaf = true;
        return false;
    }

    //create new nodes for left and right child
    TreeNode *leftNode = new TreeNode();
    TreeNode *rightNode = new TreeNode();
    //get split dataset
    calcMin split = minGiniAttribute(data);

    //link new nodes to previous node
    leftNode->prev = prevNode;
    rightNode->prev = prevNode;

    //link parrent node to new nodes
    prevNode->left = leftNode;
    prevNode->right = rightNode;

    //set attribute and split value for previous node
    prevNode->attribute = split.attribute;
    prevNode->SplitValue = getSplitValue(split, split.attribute);
    prevNode->predSurvival = calcSurvProp(data) >= 0.5;
    
    // Calculate survival probabilities for previous node
    if(prevNode->predSurvival){
        prevNode->confidence = calcSurvProp(data);
    }
    else{
        prevNode->confidence = 1.0 -calcSurvProp(data);
    }

    // Calculate survival probabilities for child nodes
    float leftSurvProp = calcSurvProp(split.linkeSeite);
    float rightSurvProp = calcSurvProp(split.rechteSeite);

    // Assign survival prediction and confidence for left node
    leftNode->predSurvival = (leftSurvProp >= 0.5);
    if(leftNode->predSurvival){
        leftNode->confidence = leftSurvProp;
    }
    else{
        leftNode->confidence = 1.0 - leftSurvProp;
    }


    // Assign survival prediction and confidence for right node
    rightNode->predSurvival = (rightSurvProp >= 0.5);
    if(rightNode->predSurvival){
        rightNode->confidence = rightSurvProp;
    }
    else{
        rightNode->confidence = 1.0 - rightSurvProp;
    }

    // Calculate depth for left and right nodes

    leftNode->depth = prevNode->depth + 1;
    rightNode->depth = prevNode->depth + 1;


    //recursive call for left and right nodes
    trainCart(leftNode, desiredDepth, split.linkeSeite);
    trainCart(rightNode, desiredDepth, split.rechteSeite);

    return true;

}
