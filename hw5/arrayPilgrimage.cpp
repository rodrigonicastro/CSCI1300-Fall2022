// CSCI 1300 Fall 2022
// Author: Rodrigo Nicastro
// Recitation: 201 – Elise Tate
// Homework 4 - Problem #1

#include <iostream>
using namespace std;

int numbers[10];
string cities[5] = {"Boulder", "NYC", "LA", "Chicago", "Houston"};
int sequence[100];
char letters[52];

int main(){
    for(int i = 0; i < 10; i++){
        numbers[i] = i + 5;
        cout << numbers[i] << endl;
    }

    for(int i = 0; i < 5; i++){
        cout << cities[i] << endl;
    }

    for(int i = 0, n = 6; i < 100; i++, n += 6){
        sequence[i] = n;
        cout << sequence[i] << endl;
    }

    for(int i = 0, n = 65; i <= 50; i += 2, n ++){
            letters[i] = int(n);
            letters[i+1] = int(n + 32);

        cout << letters[i] << endl;
        cout << letters[i+1] << endl;   
    }

}
