#pragma once

#include <vector>
#include "readFile.h" // Include the header file for the Passenger struct

// Forward declaration of Passenger struct and TreeNode struct
struct Passenger;
struct calcMin;
struct TreeNode
{
    bool isLeaf = false;
    int attribute = 0;      //Attribute by what the Node Splits
    float SplitValue = 0.0; //Value by what the data is split
    int depth = 0;          //Depth of the node

    bool predSurvival = 0;  //Tree class (True = Survives; False = does not Survive)
    float confidence = 0.0; //SurvProp of dataset (calcSurvProp())
    //float gini;             //Gini of dataset (calcGini())


    TreeNode *prev = nullptr;  //anchor Node
    TreeNode *left = nullptr;  //Next tree with preSurvuval = false    defaults to nullptr
    TreeNode *right = nullptr; //Next tree with preSurvuval = true     defaults to nullptr
};

// Function declaration for sorting a vector of Passengers based on an attribute
std::vector<Passenger> sortVectorAttribute(const std::vector<Passenger>& data, int attribute);       //returns a vector of Passengers sorted based on an attribute: 1 = Class, 2 = Sex, 3 = Age, 4 = Sibl, 5 = Parent, 6 = Fare

float getSplitValue(const calcMin &split, int attribute);


// Function declaration for calculating the entropy of a vector of Passengers
bool trainCart(TreeNode *prevNode, int desiredDepth, const std::vector<Passenger> &data);
