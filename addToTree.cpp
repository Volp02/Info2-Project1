#include "addToTree.h";


bool createTreeNode(int attribute, float SplitValue, TreeNode *prevNode)
{
    //creates Node to tree, retruns if a leaf was created or not (leaf == false)
    TreeNode *newNode = new TreeNode();

    newNode->attribute = attribute;
    newNode->SplitValue = SplitValue;

    newNode->prev = prevNode;
    if (prevNode != nullptr)
    {
        // Decide whether to attach newNode as left or right child
        if (SplitValue < prevNode->SplitValue)
        {
            prevNode->left = newNode;
        }
        else
        {
            prevNode->right = newNode;
        }
    }

    return false;
}
