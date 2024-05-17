#pragma once
#pragma once

/**
 * @file readFile.h
 *
 * This header file defines the `readFile` function and the `Passenger` struct,
 * used to read passenger data from a CSV file.
 *
 * The `readFile` function takes an integer `line` as input, which represents the line number in the input file to read.
 * The function returns a pointer to a `Passenger` struct, or `nullptr` if there is an error or the end of the file is reached.
 * It returns a Pointer to a Passenger struct with Passenger.Num = -1 to indicate that an error occurred while reading the file.
 */


struct Passenger {
    int Num;
    bool Surv;      //survived == true, died == false
    int Pclass;
    bool Sex;       //male == false, female == true
    int Age;
    int Sibl;       //siblings/spouses
    int Paren;      //parents/children
    float Fare;
};

Passenger* readFile(int line);