// CSCI 1300 Fall 2022
// Author: Rodrigo Nicastro
// Recitation: 201 – Elise Tate
// Homework 3 - Problem #2

#include <iostream>
using namespace std;

double userBudget;
char modeTransportation;

int main(){
    cout << "What is your budget?" << endl;
    cin >> userBudget;
    
    while(userBudget < 0){
        cout << "Please enter a valid input." << endl;
        cin >> userBudget;
    }
       cout << "What mode of transportation would you like to take (Bus, Train or Airplane)?" << endl;
       cin >> modeTransportation;

        while(modeTransportation != 'B' && modeTransportation != 'T' && modeTransportation != 'A'){
            cout << "Please enter a valid input." << endl;
            cin >> modeTransportation;
        }


       switch (modeTransportation){
        case 'B':
            if (userBudget >= 175.25){
                cout << "Yes, this vacation is within your budget!" << endl;
            }
            else {
                cout << "Sorry, this vacation is outside your budget." << endl;
            }
            break;

        case 'T':
            if (userBudget >= 240.66){
                cout << "Yes, this vacation is within your budget!" << endl;
            }
            else{
                cout << "Sorry, this vacation is outside your budget." << endl;
            }
            break;
            
        case 'A':
            if (userBudget >= 350.93){
                cout << "Yes, this vacation is within your budget!" << endl;
            }
            else{
                cout << "Sorry, this vacation is outside your budget." << endl;
            }
            break;
     } 
}