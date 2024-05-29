#include "addToTree.h";
#include "calculateGini.h"


bool createTreeNode(const calcMin &data, TreeNode *prevNode)
{   
    if (prevNode->isLeaf){  //If previous Node is a leaf, return false -> return false when leaf
        return false;
    }
    
    //create first tree node (root)

    TreeNode *newNode = new TreeNode();

    newNode->prev = prevNode;

    newNode->attribute = data.attribute;

    //1 = Class, 2 = Sex, 3 = Age, 4 = Sibl, 5 = Parent, 6 = Fare

    switch(newNode->attribute){       //get the split value
        case 1:
            newNode->SplitValue = data.linkeSeite[sizeof(data.linkeSeite) - 1].Pclass;
            break;
        case 2:
            newNode->SplitValue = data.linkeSeite[sizeof(data.linkeSeite) - 1].Sex;
            break;
        case 3:
            newNode->SplitValue = data.linkeSeite[sizeof(data.linkeSeite) - 1].Age;
            break;  
        case 4:
            newNode->SplitValue = data.linkeSeite[sizeof(data.linkeSeite) - 1].Sibl;
            break;  
        case 5:
            newNode->SplitValue = data.linkeSeite[sizeof(data.linkeSeite) - 1].Paren;
            break;  
        case 6:
            newNode->SplitValue = data.linkeSeite[sizeof(data.linkeSeite) - 1].Fare;
            break;  
    }

    newNode->predSurvival = calcSurvProp(data.linkeSeite) + calcSurvProp(data.rechteSeite);
}
