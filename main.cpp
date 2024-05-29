#include <iostream>
#include <vector>
#include <tuple>
#include <fstream>

using namespace std;

#include "readFile.h"
#include "calculateGini.h"
#include "CARTalgo.h"
#include "intervals.h"
#include "addToTree.h"
#include "useTree.h"

int main()
{
    int desiredDepth = 5;
    // Create a vector to store the passengers
    vector<Passenger> data;

    if (!importData(data))      //Import data from titanic.csv to vector data
    {
        cerr << "Error reading passenger data!" << endl;
        return 1; // Exit with an error code
    }

    //create first tree node (root)


    //-----------------------------------------------------------FIRST_TREE_NODE

    TreeNode *FirstTreeNode = new TreeNode();
    FirstTreeNode->depth = 0;
    FirstTreeNode->prev = nullptr;

    calcMin FirstNode = minGiniAttribute(data);
    FirstTreeNode->attribute = FirstNode.attribute;

    //1 = Class, 2 = Sex, 3 = Age, 4 = Sibl, 5 = Parent, 6 = Fare

    switch(FirstTreeNode->attribute){       //get the split value
        case 1:
            FirstTreeNode->SplitValue = FirstNode.linkeSeite.back().Pclass;
            break;
        case 2:
            FirstTreeNode->SplitValue = FirstNode.linkeSeite.back().Sex;
            break;
        case 3:
            FirstTreeNode->SplitValue = FirstNode.linkeSeite.back().Age;
            break;  
        case 4:
            FirstTreeNode->SplitValue = FirstNode.linkeSeite.back().Sibl;
            break;  
        case 5:
            FirstTreeNode->SplitValue = FirstNode.linkeSeite.back().Paren;
            break;  
        case 6:
            FirstTreeNode->SplitValue = FirstNode.linkeSeite.back().Fare;
            break;  
    }

    FirstTreeNode->predSurvival = calcSurvProp(data);
    FirstTreeNode->isLeaf = false;

     //-----------------------------------------------------------

  
    trainCart(FirstTreeNode, desiredDepth, FirstNode.linkeSeite);

    trainCart(FirstTreeNode, desiredDepth, FirstNode.rechteSeite);


    return 0;
}



