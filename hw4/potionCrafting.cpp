// CSCI 1300 Fall 2022
// Author: Rodrigo Nicastro
// Recitation: 201 – Elise Tate
// Homework 4 - Problem #3

#include <iostream>
using namespace std;

int userPriority;
int honeycombs;
int dandelions;
int coal;
int toadstools;
int manaPotions = 0;
int healthPotions = 0;

int main(){
    //Takes the user's input for the crafting priority.
    cout << "Select a potion crafting priority:" << endl << "1. Minor Mana" << endl << "2. Minor Healing" << endl;
    cin >> userPriority;

    //Makes sure the user inputs a valid priority.
    while(userPriority != 1 && userPriority != 2){
        cout << "Invalid input." << endl <<  "Select a potion crafting priority:" << endl << "1. Minor Mana" << endl << "2. Minor Healing" << endl;
        cin >> userPriority;
    }

    //Takes the user's input for the amount of Honeycombs.
    cout << "How many Honeycombs do you have?" << endl;
    cin >> honeycombs;
    //Makes sure the user inputs a valid number of Honeycombs
    while(honeycombs < 0){
        cout << "Invalid input. How many Honeycombs do you have?" << endl;
        cin >> honeycombs;
    }

    //Takes the user's input for the amount of Dandelions.
    cout << "How many Dandelions do you have?" << endl;
    cin >> dandelions;
    //Makes sure the user inputs a valid number of Dandelions.
    while(dandelions < 0){
        cout << "Invalid input. How many Dandelions do you have?" << endl;
        cin >> dandelions;
    }

    //Takes the user's input for the amount of Coal.
    cout << "How many Coal do you have?" << endl;
    cin >> coal;
    //Makes sure the user inputs a valid number of Coal.
    while(coal < 0){
        cout << "Invalid input. How many Coal do you have?" << endl;
        cin >> coal;
    }

    //Takes the user's input for the amount of Toadstools.
    cout << "How many Toadstools do you have?" << endl;
    cin >> toadstools;
    //Makes sure the user inputs a valid number of Toadstools.
    while(toadstools < 0){
        cout << "Invalid input. How many Toadstools do you have?" << endl;
        cin >> toadstools;
    }

    
    switch(userPriority){
        case 1:
            //Computes how many Mana Potions the user can make if the priority is Mana.
            while(honeycombs >= 5 && dandelions >= 3 && coal >= 1 && toadstools >= 0){
                honeycombs -= 5;
                coal -= 1;
                dandelions -= 3;
                manaPotions++;
            }

            //Computes how many Healing Potions the user can make if the priority is Mana.
            while(honeycombs >= 5 && dandelions >= 0 && coal >= 2 && toadstools >= 3){
                honeycombs -= 5;
                coal -= 2;
                toadstools -= 3;
                healthPotions++;
            }
            
            //Prints how many potions of each type the user can make.
            cout << "You can make " << manaPotions << " Mana potion(s) and " << healthPotions << " Healing potion(s)." << endl;
            //Prints how many Honeycombs, Dandelions, Coal and Toadstools the user has left.
            cout << "You still have " << honeycombs << " Honeycomb(s), " << dandelions << " Dandelion(s), " << coal << " Coal and " << toadstools << " Toadstoll(s) left." << endl;
            break;
        case 2:
            //Computes how many Healing Potions the user can make if the priority is Healing.
            while(honeycombs >= 5 && dandelions >= 0 && coal >= 2 && toadstools >= 3){
                honeycombs -= 5;
                coal -= 2;
                toadstools -= 3;
                healthPotions++;
            }

            //Computes how many Mana Potions the user can make if the priority is Healing.
            while(honeycombs >= 5 && dandelions >= 3 && coal >= 1 && toadstools >= 0){
                honeycombs -= 5;
                coal -= 2;
                dandelions -= 3;
                manaPotions++;
            }

            //Prints how many potions of each type the user can make.
            cout << "You can make " << healthPotions << " Healing potion(s) and " << manaPotions << " Mana potion(s)." << endl;
            //Prints how many Honeycombs, Dandelions, Coal and Toadstools the user has left.
            cout << "You still have " << honeycombs << " Honeycomb(s), " << dandelions << " Dandelion(s), " << coal << " Coal and " << toadstools << " Toadstoll(s) left." << endl;
            break;
    }
}