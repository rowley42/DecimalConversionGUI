/*

Christopher Rowley

Semester Project / Create Your Own Lab

5/22

Programming Environment Used ( Windows 10, Visual Studio 2019 )

*/

#pragma once
using namespace std;

int convertToBinary(int num); //function that convers base 10 decimal integers to binary. [0-1000]
int binaryToDecimal(int num); //function that convers binary to base 10 decimal integers. ["0-1000" in binary]
string decimalToRomanNum(int num); //function that converts normal base 10 integers to roman numerals
int convertToOctal(int num); //function that allows users to enter base 10 numbers (decimal) and convert to base 8 (octal)


void chooseConversion(int num); //add in switch statement that allows user to pick which function to use
