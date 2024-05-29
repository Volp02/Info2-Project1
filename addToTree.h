#pragma once


#include "readFile.h" // Include the header file for the Passenger struct
#include <vector>

// Forward declaration of Passenger struct and tree 
struct Passenger;
struct TreeNode
{
    bool isLeaf = false;
    int attribute;          //Attribute by what the Node Splits
    float SplitValue;       //Value by what the data is split
    bool predSurvival;      //Tree class (True = Survives; False = does not Survive)
    float confidence;       //SurvProp of dataset (calcSurvProp())
    float gini;             //Gini of dataset (calcGini())


    TreeNode *prev;             //anchor Node
    TreeNode *left = nullptr;   //Next tree with preSurvuval = false    defaults to nullptr
    TreeNode *right = nullptr;  //Next tree with preSurvuval = true     defaults to nullptr
};


// declare Function to create a Tree node
bool createTreeNode(int attribute, float SplitValue, TreeNode *prevNode);
