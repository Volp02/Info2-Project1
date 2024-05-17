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

// Hauptfunktion für Aufgabe 2

Passenger* readFile(int line)
{   
    std::ifstream data("titanic.csv"); // Dateipfad zur CSV-Datei

    string textFromFile; // Zeile aus der Datei


    if (!data.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return new Passenger{ -1, false, 0, false, 0, 0, 0, 0.0 };
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

    // Ausgabe der Zeile mit Zeilennummer
    // //cout << count << " :" << textFromFile << endl;

    Passenger* passenger = new Passenger;

    passenger->Num = line;

    // Kopie der Zeile für die Bearbeitung
    string tempText = textFromFile;

    // Startposition für die Suche nach Kommas
    int beforeKommastelle = 0;

    // Array zur Speicherung der sicheren Positionen der Kommas
    int KommastelleSafe[9];
    KommastelleSafe[0] = 0;

    // Schleife zur Suche nach Kommas
    for (int i = 1; i <= 8; i++)
    {
        // Finden der Position des nächsten Kommas und Aktualisieren der sicheren Position
        Kommastelle = findComma(tempText);
        KommastelleSafe[i] = Kommastelle + beforeKommastelle + 1;

        // Ausgabe der sicheren Position des Kommas
        // //cout << KommastelleSafe[i] << endl;

        // Löschen des Teils des Textes vor dem gefundenen Komma
        tempText.erase(0, Kommastelle + 1);

        // Aktualisieren der Startposition für die nächste Iteration
        beforeKommastelle = KommastelleSafe[i];

        std::stringstream tempSafe;
        string tempString;
        ////cout << i << endl;
        switch (i)
        {
        case 1:
            tempSafe << readBetween(textFromFile, KommastelleSafe[0], KommastelleSafe[1]);
            tempSafe >> passenger->Surv;
            passenger->Surv = static_cast<bool>(passenger->Surv);
            // //cout << "pSurv: " << Pass.pSurv << endl;
            break;
        case 2:
            tempSafe << readBetween(textFromFile, KommastelleSafe[1], KommastelleSafe[2]);
            tempSafe >> passenger->Pclass;
            // //cout << "pPclass: " << Pass.pPclass << endl;
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

            // //cout << "TempString = " << tempString << "pSex: " << Pass.pSex << endl;
            break;
        case 5:
            tempSafe << readBetween(textFromFile, KommastelleSafe[4], KommastelleSafe[5]);
            tempSafe >> passenger->Age;
            //cout << "pAge: " << Pass.pAge << endl;
            break;
        case 6:
            tempSafe << readBetween(textFromFile, KommastelleSafe[5], KommastelleSafe[6]);
            tempSafe >> passenger->Sibl;
            //cout << "pSibl: " << Pass.pSibl << endl;
            break;
        case 7:
            tempSafe << readBetween(textFromFile, KommastelleSafe[6], KommastelleSafe[7]);
            tempSafe >> passenger->Paren;
            // //cout << "pParen: " << Pass.pParen << endl;
            break;
        case 8:

            tempSafe << readBetween(textFromFile, KommastelleSafe[7], (textFromFile.back() - 1));
            tempSafe >> passenger->Fare;

            // //cout << "pFare: " << Pass.pFare << endl;
            break;
        }
    }
    ////cout << "returning: " << Pass.pAge << Pass.pSurv << Pass.pSibl << endl;
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