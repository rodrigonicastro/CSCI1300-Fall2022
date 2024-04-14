// CSCI 1300 Fall 2022
// Author: Rodrigo Nicastro
// Recitation: 201 – Elise Tate
// Homework 4 - Problem #2

#include <iostream>
using namespace std;

int main(){
    //Takes the user's input.
    cout << "Enter  a value between 1 and 1000:" << endl;
    int userInput;
    cin >> userInput;
    
    //Makes sure the user's input is between 1 and 1000.
    while(!(userInput > 1 && userInput < 1000)){
        cout << "Invalid input." << endl << "Enter  a value between 1 and 1000:" << endl;
        cin >> userInput;
    }
    
    cout << userInput << endl;
    
    while(userInput != 1){
        //Computes the next number if the sequence if the current number is even.
        if(userInput % 2 == 0){
            userInput = (userInput/2);
            cout << userInput << endl;
        }
        
        //Computes the next number in the sequence if the current number is odd.
        else{
            userInput = userInput*3 + 1;
            cout << userInput << endl;
        }
    }
}