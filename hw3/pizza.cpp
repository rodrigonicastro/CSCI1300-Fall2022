// CSCI 1300 Fall 2022
// Author: Rodrigo Nicastro
// Recitation: 201 – Elise Tate
// Homework 3 - Problem #3

#include <iostream>
#include <iomanip>
using namespace std;

char inputSize;
double inputToppings;
double totalCost;

int main(){
    cout << "What size pizza would you like to order?" << endl;
    cin >> inputSize;

    while(inputSize != 'S' && inputSize != 'M' && inputSize != 'L'){
            cout << "Please enter a valid input." << endl;
            cin >> inputSize;
        }

    switch (inputSize){
    case 'S':
        cout << "How many toppings do you want?" << endl;
        cin >> inputToppings;

        while(inputToppings < 0){
            cout << "Please enter a valid input" << endl;
            cin >> inputToppings;
        }

        totalCost = 4.99 + (0.75 * inputToppings);
        cout << "Your total is $" << fixed << setprecision(2) << totalCost << endl;
        
        break;

    case 'M':
        cout << "How many toppings do you want?" << endl;
        cin >> inputToppings;

        while(inputToppings < 0){
            cout << "Please enter a valid input" << endl;
            cin >> inputToppings;
        }

        totalCost = 5.99 + (1.5 * inputToppings);
        cout << "Your total is $" << fixed << setprecision(2) << totalCost << endl;

        break;
    
    case 'L':
        cout << "How many toppings do you want?" << endl;
        cin >> inputToppings;

        while(inputToppings < 0){
            cout << "Please enter a valid input" << endl;
            cin >> inputToppings;
        }

        totalCost = 6.99 + (2.25 * inputToppings);
        cout << "Your total is $" << fixed << setprecision(2) << totalCost << endl;
        break;
    }
}