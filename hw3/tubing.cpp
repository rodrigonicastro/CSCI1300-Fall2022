// CSCI 1300 Fall 2022
// Author: Rodrigo Nicastro
// Recitation: 201 – Elise Tate
// Homework 3 - Problem #1

#include <iostream>
using namespace std;

int flowrate;

int main(){
    cout << "What is the flowrate of Boulder Creek?" << endl;
    cin >> flowrate;

    if (flowrate <= 0){
        while (flowrate <=0){
            cout << "Please enter a valid input." << endl;
            cin >> flowrate;
        }       
}
    if (flowrate > 0 && flowrate <= 250){
        cout << "It is safe to go tubing. Have fun!" << endl;
}
    else{
        cout << "The river is flowing too fast to go tubing." << endl;
}
    return 0;
}