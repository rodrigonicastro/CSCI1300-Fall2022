// CSCI 1300 Fall 2022
// Author: Rodrigo Nicastro
// Recitation: 201 – Elise Tate
// Homework 2 - Problem #5

#include <iostream>
using namespace std;

int inputBolts;
int goldCoins;
int gems;

int main(){
    cout << "Enter the number of Bolts:" << endl;
    cin >> inputBolts;

    goldCoins = inputBolts / 23;
    inputBolts = inputBolts - (23 * goldCoins);
    gems = goldCoins / 13;
    goldCoins = goldCoins - (13 * gems); 

    cout << gems << " Gem(s) " << goldCoins << " Goldcoin(s) " << inputBolts << " Bolt(s)" << endl;

}