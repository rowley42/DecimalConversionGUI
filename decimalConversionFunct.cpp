/*

Christopher Rowley

Semester Project

5/22

Programming Environment Used ( Windows 10, Visual Studio 2019 )

*/
#include "pch.h"
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include "decimalConvertInit.h"
using namespace std;

int convertToBinary(int num) {
	int binary = 0;
	int remainder = 1;
	int temp = 1;

	while (num > 0) {          // divide the given number by 2 until equaling zero, and take 
		remainder = (num % 2); // remainder of each division. each remainder equals a part of the binary conversion
		binary += remainder * temp; //adding each remainder to binary variable and increasing the place of remainder with temp each time
		num /= 2;
		temp *= 10;

	}


	cout << "Converted to binary is : " << binary << endl;

	return binary;
}

int convertToOctal(int num) {  // same algorithm as binary conversion
	int octal = 0;             // except dividing by 8 and taking remainder
	int remainder = 0;
	int temp = 1;

	while (num > 0) {
		remainder = (num % 8);
		num /= 8;
		octal += remainder * temp;
		temp *= 10;
	}

	cout << "Converted to octal is : " << octal << endl;

	return octal;
}


int binaryToDecimal(int num) {  //similar algorithm as decimal -> binary
	int decimal0 = 0;           //instead dividing binary by 10 and taking remainder
	int temp = 1;                  //increasing temp by 2 each interation
	int remainder = 0;

	while (num > 0) {
		remainder = (num % 10);
		decimal0 += remainder * temp;
		num /= 10;
		temp *= 2;
	}

	cout <<"Converted to decimal is : " << decimal0 << endl;

	return decimal0;
}



string decimalToRomanNum(int num) {
	int temp = 0;
	string decimalConverted = "";

	vector<int> decimalValues = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 }; //vector displaying the order and values of Roman Numerals in decending order

	vector<string> romanNumerals = { "M" ,"CM" ,"D" ,"CD" ,"C" , "XC" ,"L" ,"XL" ,"X" ,"IX" ,"V" ,"IV" ,"I" }; //vector of Roman Numerals

	while (num > 0) {                                          //keep loop running as long as given number is still > than zero
		for (int i = 0; i <= decimalValues.size() - 1; ++i) {  //for loop that will iterate through the amount of elements in the vectors
			if ((num / decimalValues[i]) != 0) {               //if quotient of given number isn't 0
				temp = num / decimalValues[i];                 //assign a variable that keeps quotient
				num -= (decimalValues[i] * temp);              //if quotient isnt 0, multiply i by the quotient and subtract from given number
				for (int a = 0; a <= temp - 1; ++a) {          //for loop that will add the a Roman Numeral and repeat it for quotient amount (temp)
					decimalConverted += romanNumerals[i];      //adding Roman Numeral to variable
				}
			}
		}

	}
	cout << "Converted to Roman Numerals is : " << decimalConverted << endl;
	return decimalConverted;
}