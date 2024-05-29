#include "addToTree.h";
#include "calculateGini.h"


bool createTreeNode(int attribute, float SplitValue, TreeNode *prevNode)
{   
    if (prevNode->isLeaf){  //If previous Node is a leaf, return false -> return false when leaf
        return false;
    }
    
    TreeNode *newNode = new TreeNode();


    newNode->attribute = attribute;
    newNode->SplitValue = SplitValue;
    newNode->gini = calcBinaryGini(newNode->confidence);


    return true;
}
