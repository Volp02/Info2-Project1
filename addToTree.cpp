#include "addToTree.h";


bool createTreeNode(int attribute, float SplitValue, TreeNode *prevNode)
{   
    if (prevNode->isLeaf){  //If previous Node is a leaf, return false -> return false when leaf
        return false;
    }
    
    TreeNode *newNode = new TreeNode();

    newNode->attribute = attribute;
    newNode->SplitValue = SplitValue;

    newNode->prev = prevNode;
    if (!prevNode->isLeaf)
    {
        // Decide whether to attach newNode as left or right child

    }
    //node was sucessfully created -> return true
    return true;
}
