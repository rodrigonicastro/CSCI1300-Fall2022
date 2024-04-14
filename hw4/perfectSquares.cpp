// CSCI 1300 Fall 2022
// Author: Rodrigo Nicastro
// Recitation: 201 – Elise Tate
// Homework 4 - Problem #1

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int number;
    int sum = 0;
    int max_val;
    
    //Takes the user input.
    cout << "Enter a non-negative integer:" << endl;
    cin >> number;
    
    //Makes sure the user inputs a positive integer.
    if (number < 0){ 
        cout << "Invalid input." << endl;
    }

    else{
    //Verifies what is the highest perfect square before the user's input
	max_val = sqrt(number);

        //Computes the sum of the perfect squares smaller then the user's input.
        for (int i = 0; i <= max_val; i++){
            sum += i*i;
        }
        //Prints the sum
        cout << "Sum: " << sum << endl;
    }
    return 0;
}