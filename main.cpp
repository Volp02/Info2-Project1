/*
Projektarbeit 1 – Titanic
Gruppe:
[Andreas Manuel Runge #1]
[Matthias Friedl  #2]
[Lajos Billes #3]

Wir stimmen der Veröffentlichung unseres Source Code mit Namensnennung zu.

Copyright (C) [2024] [authors #1-#3]
SPDX-License-Identifier: MIT

Github link: https://github.com/Volp02/Info2-Project1.git 
*/

#include <iostream>
#include <vector>

using namespace std;

//import header files
#include "readFile.h"
#include "calculateGini.h"
#include "CARTalgo.h"
#include "intervals.h"
#include "useTree.h"

int main()
{
    //get desired depth
    cout << "input desired depth: ";
    int desiredDepth;
    cin >> desiredDepth;

    // Create a vector to store the passengers
    vector<Passenger> data;
    cout << "reading file..." << endl;
    if (!importData(data))      //Import data from titanic.csv to vector data
    {
        cerr << "Error reading passenger data!" << endl;
        return 1; // Exit with an error code
    }



    //create first tree node (root)

    TreeNode *FirstTreeNode = new TreeNode();
    FirstTreeNode->depth = 0;
    FirstTreeNode->prev = nullptr;

    calcMin FirstNode = minGiniAttribute(data);
    FirstTreeNode->attribute = FirstNode.attribute;

    //1 = Class, 2 = Sex, 3 = Age, 4 = Sibl, 5 = Parent, 6 = Fare

    switch(FirstTreeNode->attribute){       //get the split value
        case 1:
            FirstTreeNode->SplitValue = static_cast<float>(FirstNode.linkeSeite.back().Pclass);
            break;
        case 2:
            FirstTreeNode->SplitValue = static_cast<float>(FirstNode.linkeSeite.back().Sex);
            break;
        case 3:
            FirstTreeNode->SplitValue = static_cast<float>(FirstNode.linkeSeite.back().Age);
            break;  
        case 4:
            FirstTreeNode->SplitValue = static_cast<float>(FirstNode.linkeSeite.back().Sibl);
            break;  
        case 5:
            FirstTreeNode->SplitValue = static_cast<float>(FirstNode.linkeSeite.back().Paren);
            break;  
        case 6:
            FirstTreeNode->SplitValue = static_cast<float>(FirstNode.linkeSeite.back().Fare);
            break;  
    }

    FirstTreeNode->isLeaf = false;


  //start training the tree with recursion:
    trainCart(FirstTreeNode, desiredDepth, FirstNode.linkeSeite);
    trainCart(FirstTreeNode, desiredDepth, FirstNode.rechteSeite);

    std::cout << "\033[2J\033[1;1H";        //clear Terminal output

    //input loop
    while (getPrediction(usrInputPassenger(), *FirstTreeNode))
    {
        string tmp;
        cout << "type exit to exit or anything else to input another Passenger: ";
        cin >> tmp;
        std::cout << "\033[2J\033[1;1H"; //clear Terminal output
        if (tmp == "exit")
        {
            return 0;
        }
    }

    cout << "an error occured" << endl;
    return 0;
}


