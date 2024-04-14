// CSCI 1300 Fall 2022
// Author: Rodrigo Nicastro
// Recitation: 201 – Elise Tate
// Homework 2 - Problem #3

#include <iostream>
#include <iomanip> 
using namespace std;

int main(){
    cout << "What is the side length of the base of the carton in inches?" << endl; //asks for the user's input
    double baseInput; //defines the double "baseInput"
    cin >> baseInput; //updates the double ""baseInput" with the user's input

    cout << "What is the height of the carton in inches?" << endl; //asks for the user's input
    double heightInput; //defines the double "heightInput"
    cin >> heightInput; //updates the double ""heightInput" with the user's input

    double volumeCbInches = baseInput * baseInput * heightInput; //calculates the volume of the carton in cubic inches
    double volumeOunces = volumeCbInches * 0.55; //converts the volume of the carton from cubic inches to ounces

    cout << "The carton has a volume of " << fixed << setprecision(1) << volumeOunces << " ounces." << endl;
}