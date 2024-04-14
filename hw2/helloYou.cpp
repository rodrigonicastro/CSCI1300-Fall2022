// CSCI 1300 Fall 2022
// Author: Rodrigo Nicastro
// Recitation: 201 – Elise Tate
// Homework 2 - Problem #2

#include <iostream>
#include <string>
using namespace std;

int main(){
    cout << "Please enter your name below:" << endl;

    string name; //defines the string "name"
    getline(cin, name); //updates the string "name" with the user's input

    cout <<"Hello, " + name + "!" << endl;
    return 0;
}