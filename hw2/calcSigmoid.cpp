// CSCI 1300 Fall 2022
// Author: Rodrigo Nicastro
// Recitation: 201 – Elise Tate
// Homework 2 - Problem #6

#include <iostream>
#include <cmath>
using namespace std;

double x;
double sigValue;

int main(){
    cout << "Enter a value for x:" << endl;
    cin >> x;

    sigValue = (1/(1+ exp(-x)));

    cout << "The sigmoid for x=" << x << " is " << sigValue << endl;
}