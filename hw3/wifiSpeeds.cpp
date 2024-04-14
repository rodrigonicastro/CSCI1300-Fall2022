// CSCI 1300 Fall 2022
// Author: Rodrigo Nicastro
// Recitation: 201 – Elise Tate
// Homework 3 - Problem #4

#include <iostream>
using namespace std;

double inputWifi1;
double inputWifi2;
double inputWifi3;

int main(){
    cout << "Enter wifi speeds over the last 3 classes:" << endl;
    cin >> inputWifi1;
    cin >> inputWifi2;
    cin >> inputWifi3;

    while(inputWifi1 < 0 || inputWifi2 < 0 || inputWifi3 < 0){
        cout << "Please enter a valid input." << endl;
        cin >> inputWifi1;
        cin >> inputWifi2;
        cin >> inputWifi3;
    }

        if(inputWifi1 < inputWifi2 && inputWifi3 > inputWifi2){
            cout << "The wifi is getting faster!" << endl;
        }

        else if(inputWifi1 > inputWifi2 && inputWifi2 > inputWifi3){
            cout << "The wifi is getting slower!" << endl;
        }
        
        else if(inputWifi1 == inputWifi2 && inputWifi1 == inputWifi3){
            cout << "The wifi is constant!" << endl;
        }
        
        else{
            cout << "The wifi speed is changing unpredictably." << endl;
        }
    }