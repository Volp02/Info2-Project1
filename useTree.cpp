#include "useTree.h"

#include <iostream>

using namespace std;

Passenger *usrInputPassenger()
{
    //1 = Class, 2 = Sex, 3 = Age, 4 = Sibl, 5 = Parent, 6 = Fare
    std::cout << "Enter passenger attributes:\n";

    int int_input;
    std::string str_input;
    float fare_input;

    Passenger *inputPassenger = new Passenger;

    // 1. Class
    std::cout << "1. Class: ";
    while (!(std::cin >> int_input))
    {
        std::cout << "Invalid input. Please enter an integer: ";
        // Clear input error state and discard any remaining invalid characters
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    inputPassenger->Pclass = int_input;

    // 2. Sex (male/female)
    std::cout << "2. Sex (male/female): ";
    std::cin >> str_input;
    inputPassenger->Sex = (str_input == "female"); // false for male, true for female

    // 3. Age
    std::cout << "3. Age: ";
    while (!(std::cin >> int_input))
    {
        std::cout << "Invalid input. Please enter an integer: ";
        // Clear input error state and discard any remaining invalid characters
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    inputPassenger->Age = int_input;

    // 4. Number of Siblings/Spouses Aboard
    std::cout << "4. Number of siblings / spouses aboard: ";
    while (!(std::cin >> int_input))
    {
        std::cout << "Invalid input. Please enter an integer: ";
        // Clear input error state and discard any remaining invalid characters
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    inputPassenger->Sibl = int_input;

    // 5. Number of Parents/Children Aboard
    std::cout << "5. Number of parents / children aboard: ";
    while (!(std::cin >> int_input))
    {
        std::cout << "Invalid input. Please enter an integer: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    inputPassenger->Paren = int_input;

    // 6. Fare
    std::cout << "6. Fare: ";
    while (!(std::cin >> fare_input))
    {
        std::cout << "Invalid input. Please enter a number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    inputPassenger->Fare = fare_input;
    cout << endl;
    return inputPassenger;

}

bool getPrediction(Passenger* passenger, TreeNode &root)
{

    TreeNode *current = &root; // Point to the root node


    while (current != nullptr && !current->isLeaf)
    {
        int attribute = current->attribute;

        //1 = Class, 2 = Sex, 3 = Age, 4 = Sibl, 5 = Parent, 6 = Fare

        switch (attribute)
        {
        case 1:
            if (static_cast<float>(passenger->Pclass) <= current->SplitValue)
            {
                current = current->left;
            }
            else current = current->right;
            break;

        case 2:
            if (static_cast<float>(passenger->Sex) <= current->SplitValue)
            {
                current = current->left;
            }
            else current = current->right;
            break;

        case 3:
            if (static_cast<float>(passenger->Age) <= current->SplitValue)
            {
                current = current->left;
            }
            else current = current->right;
            break;

        case 4:
            if (static_cast<float>(passenger->Sibl) <= current->SplitValue)
            {
                current = current->left;
            }
            else current = current->right;
            break;

        case 5:
            if (static_cast<float>(passenger->Paren) <= current->SplitValue)
            {
                current = current->left;
            }
            else current = current->right;
            break;

        case 6:
            if (static_cast<float>(passenger->Fare) <= current->SplitValue)
            {
                current = current->left;
            }
            else current = current->right;
            break;

        default:
            std::cerr << "Error: Invalid attribute value\n";
            return false; 
        }   
        
    }

    cout << "The predicted outcome of the provided Passenger is:";

    if (current != nullptr && current->predSurvival)
    {
        cout << " surviving !" << endl;
        cout << "confidence: " << current->confidence * 100.0 << "%" << endl;
    }
    else if (current != nullptr && !current->predSurvival)
    {
        cout << " not surviving!" << endl;
        cout << "confidence: " << current->confidence * 100.0 << "%" << endl;
        
    }
    else
    {
        cout << "The trainingmodel is undecided, no prediction possible" << endl;
    }


    delete passenger;
    return true;
}



