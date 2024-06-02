#include <iostream>
#include <string>
#include <fstream>
#include "readFile.h"
#include <vector>
#include <tuple>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// Funktion zum Finden des ersten Kommas in einem String
int findComma(string Input);

string readBetween(string Input, int x1, int x2);

// Hauptfunktion f�r Aufgabe 2
//reads the csv file and returns a vector of passengers
Passenger* readFile(int line)
{   
    std::ifstream data("titanic.csv"); // Dateipfad zur CSV-Datei

    string textFromFile; // Zeile aus der Datei


    if (!data.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return nullptr;
    }
    
    for (int i = 0; i <= line; i++)     // skip unwanted lines
    {
        std::getline(data, textFromFile);
    }

    if (!data) {                                                                    //check if end of file is reached and return nullptr if so
        std::cerr << "End of file reached before line " << line << std::endl;
        return nullptr;
    }

    int Kommastelle = 0; // Position des Kommas im aktuellen Text

    Passenger* passenger = new Passenger;

    passenger->Num = line;

    // Kopie der Zeile f�r die Bearbeitung
    string tempText = textFromFile;

    // Startposition f�r die Suche nach Kommas
    int beforeKommastelle = 0;

    // Array zur Speicherung der sicheren Positionen der Kommas
    int KommastelleSafe[9];
    KommastelleSafe[0] = 0;

    // Schleife zur Suche nach Kommas
    for (int i = 1; i <= 8; i++)
    {
        // Finden der Position des n�chsten Kommas und Aktualisieren der sicheren Position
        Kommastelle = findComma(tempText);
        KommastelleSafe[i] = Kommastelle + beforeKommastelle + 1;

        // L�schen des Teils des Textes vor dem gefundenen Komma
        tempText.erase(0, Kommastelle + 1);

        // Aktualisieren der Startposition f�r die n�chste Iteration
        beforeKommastelle = KommastelleSafe[i];

        std::stringstream tempSafe;
        string tempString;

        switch (i)
        {
        case 1:
            tempSafe << readBetween(textFromFile, KommastelleSafe[0], KommastelleSafe[1]);
            tempSafe >> passenger->Surv;
            passenger->Surv = static_cast<bool>(passenger->Surv);
            break;
        case 2:
            tempSafe << readBetween(textFromFile, KommastelleSafe[1], KommastelleSafe[2]);
            tempSafe >> passenger->Pclass;
            break;
        case 4:
            tempString = readBetween(textFromFile, KommastelleSafe[3], KommastelleSafe[4]);
            if (tempString.find("male"))
            {
                passenger->Sex = true;
            }
            else if (tempString.find("female"))
            {
                passenger->Sex = false;
            }

            break;
        case 5:
            tempSafe << readBetween(textFromFile, KommastelleSafe[4], KommastelleSafe[5]);
            tempSafe >> passenger->Age;

            break;
        case 6:
            tempSafe << readBetween(textFromFile, KommastelleSafe[5], KommastelleSafe[6]);
            tempSafe >> passenger->Sibl;
            
            break;
        case 7:
            tempSafe << readBetween(textFromFile, KommastelleSafe[6], KommastelleSafe[7]);
            tempSafe >> passenger->Paren;
          
            break;
        case 8:

            tempSafe << readBetween(textFromFile, KommastelleSafe[7], (textFromFile.back() - 1));
            tempSafe >> passenger->Fare;
            break;
        }
    }
    
    return passenger; //return passenger pointer

}
// Funktion zum Finden des ersten Kommas in einem String
int findComma(string Input)
{
    int Limit1 = Input.find(',');
    return Limit1;
}

string readBetween(string Input, int x1, int x2)
{
    return Input.substr(x1, x2 - x1);
}

bool importData(std::vector<Passenger> &data)
{
    data.clear();

    Passenger *currentPassenger = readFile(1); // Read the first passenger
    if (currentPassenger->Num < 0)
    {
        cout << "An error occurred: " << currentPassenger->Num; // Error message if reading fails
        return false;                                           // Signal an error occurred
    }

    while (currentPassenger != nullptr)
    {
        data.push_back(*currentPassenger); // Add passenger to the vector

        int nextPassengerNum = currentPassenger->Num + 1; // Calculate the number of the next passenger
        delete currentPassenger;                          // Deallocate memory before reading the next
       
        currentPassenger = readFile(nextPassengerNum); // Read the next passenger

        // Check for errors after reading, before potentially adding another invalid passenger
        if (currentPassenger != nullptr && currentPassenger->Num < 0)
        {
            cout << "An error occurred: " << currentPassenger->Num;
            delete currentPassenger;
            return false;
        }
    }

    return true; // Signal successful read
}
