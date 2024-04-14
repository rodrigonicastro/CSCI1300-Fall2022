// CSCI 1300 Fall 2022
// Author: Rodrigo Nicastro
// Recitation: 201 – Elise Tate
// Homework 2 - Problem #4

#include <iostream>
using namespace std;

int main(){
    cout << "How many days in the future would you like a prediction for?" << endl;
    int days;
    cin >> days;

    while (days < 0){
        cout << "The amount of days cannot be negative! Enter a new number: " << endl;
        cin >> days;
    }

    int snowBreckenridge = 25 + (10 * days) - (5 * days);
    int snowVail = 28 + (14 * days) - (2 * days);
    int snowCopperMountain = 40 + (5 * days ) - (3 * days);

    cout << "Breckenridge will have " << snowBreckenridge << " inches, Vail will have " << snowVail << " inches, and Copper Mountain will have " << snowCopperMountain << " inches." << endl;

}