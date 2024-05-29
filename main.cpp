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
    // Create a vector to store the passengers
    vector<Passenger> data;

    if (!importData(data))      //Import data from titanic.csv to vector data
    {
        cerr << "Error reading passenger data!" << endl;
        return 1; // Exit with an error code
    }

    //create first tree node (root)

    TreeNode *FirstTreeNode = new TreeNode();
    FirstTreeNode->depth = 0;
    FirstTreeNode->prev = nullptr;

    calcMin FirstNode = minGiniAttribute(data, 1);
    FirstTreeNode->attribute = FirstNode.attribute;

    //1 = Class, 2 = Sex, 3 = Age, 4 = Sibl, 5 = Parent, 6 = Fare

    switch(FirstTreeNode->attribute){       //get the split value
        case 1:
            FirstTreeNode->SplitValue = FirstNode.linkeSeite[sizeof(FirstNode.linkeSeite) - 1].Pclass;
            break;
        case 2:
            FirstTreeNode->SplitValue = FirstNode.linkeSeite[sizeof(FirstNode.linkeSeite) - 1].Sex;
            break;
        case 3:
            FirstTreeNode->SplitValue = FirstNode.linkeSeite[sizeof(FirstNode.linkeSeite) - 1].Age;
            break;  
        case 4:
            FirstTreeNode->SplitValue = FirstNode.linkeSeite[sizeof(FirstNode.linkeSeite) - 1].Sibl;
            break;  
        case 5:
            FirstTreeNode->SplitValue = FirstNode.linkeSeite[sizeof(FirstNode.linkeSeite) - 1].Paren;
            break;  
        case 6:
            FirstTreeNode->SplitValue = FirstNode.linkeSeite[sizeof(FirstNode.linkeSeite) - 1].Fare;
            break;  
    }

    FirstTreeNode->predSurvival = calcSurvProp(data);


    








    //ONLY FOR DEBUGGING \/:


    //Testing: print all passengers

    for (int i = 0; i < data.size() ; i++) {
        cout << "Num: "<< data[i].Num << endl;
        cout << "age: " << data[i].Age << endl;
        cout << "Class: "  << data[i].Pclass << endl;
        cout << "Survived: " << data[i].Surv << endl;
        cout << "Sex: " << data[i].Sex << endl;
        cout << "Sibsp: " << data[i].Sibl << endl;
        cout << "Parch: " << data[i].Paren << endl;
        cout << "Fare: " << data[i].Fare << endl;
        cout << endl;
    }
    

    cout << "CalculateSurvivalProp:" << calcSurvProp(data) << endl;
    //implement CART Algorithm

    cout << "GiniImpurity:" << calcBinaryGini(calcSurvProp(data)) << endl;

    //Testing Sorting:

    /*
    vector<Passenger> data2 = sortVectorAttribute(data, 1);
    cout << "Sort dataset by Attruibute 1 (Pclass)"<< endl;



    
    for (int i = 0; i < data2.size(); i++) {
        //cout << "age of: " << i << ": " << data2[i].Age << endl;
        cout << "Num of: " << i << ": " << data2[i].Num << endl;
        cout << "Class of: " << i << ": " << data2[i].Pclass << endl;
        //cout << "Survived of: " << i << ": " << data2[i].Surv << endl;
        //cout << "Sex of: " << i << ": " << data2[i].Sex << endl;
        //cout << "Sibsp of: " << i << ": " << data2[i].Sibl << endl;
        //cout << "Parch of: " << i << ": " << data2[i].Paren << endl;
        //cout << "Fare of: " << i << ": " << data2[i].Fare << endl;
        cout << endl;

    }
    
    data2 = sortVectorAttribute(data2, 3);
    cout << "Sort dataset by Attruibute 3 (Age)"<< endl;

    for (int i = 0; i < data2.size() - 1; i++) {
        cout << "age of: " << i << ": " << data2[i].Age << endl;
        cout << "Num of: " << i << ": " << data2[i].Num << endl;
        //cout << "Class of: " << i << ": " << data2[i].Pclass << endl;
        //cout << "Survived of: " << i << ": " << data2[i].Surv << endl;
        //cout << "Sex of: " << i << ": " << data2[i].Sex << endl;
        //cout << "Sibsp of: " << i << ": " << data2[i].Sibl << endl;
        //cout << "Parch of: " << i << ": " << data2[i].Paren << endl;
        //cout << "Fare of: " << i << ": " << data2[i].Fare << endl;
        cout << endl;

    }
    
    */

    //Testing Splitting
    vector<Passenger> data2 = splitVector(data, 1).rechteSeite;
    vector<Passenger> data3 = splitVector(data, 1).linkeSeite;
    minGiniAttribute(data, 1);
    cout << "Gini afer Sort and Split: " << minGiniAttribute(data2, 1).gini << endl;

   
    calcMin tmp;
    tmp = minGiniAttribute(data,1);
    cout<<"gini 2 Ebene 1:" <<(minGiniAttribute(tmp.linkeSeite,1)).gini <<endl;
    cout<<"gini 2 Ebene 2:" <<(minGiniAttribute(tmp.rechteSeite,1)).gini <<endl;

    for (int i = 0; i < tmp.linkeSeite.size(); i++)
    {
        cout << "Num: " << tmp.linkeSeite[i].Num << endl;
        cout << "age: " << tmp.linkeSeite[i].Age << endl;
        cout << "Class: " << tmp.linkeSeite[i].Pclass << endl;
        cout << "Survived: " << tmp.linkeSeite[i].Surv << endl;
        cout << "Sex: " << tmp.linkeSeite[i].Sex << endl;
        cout << "Sibsp: " << tmp.linkeSeite[i].Sibl << endl;
        cout << "Parch: " << tmp.linkeSeite[i].Paren << endl;
        cout << "Fare: " << tmp.linkeSeite[i].Fare << endl;
        cout << endl;
    }



    return 0;
}



