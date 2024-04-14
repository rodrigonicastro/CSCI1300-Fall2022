// CSCI 1300 Fall 2022
// Author: Rodrigo Nicastro
// Recitation: 201 – Elise Tate
// Homework 4 - Problem #5

#include <iostream>
#include <array>
using namespace std;

void fullClass(bool classroom[][4], int rows, int waitlist){
    int n = 0;

    for(int x = 0; x < rows; x++){
        for(int i = 0; i < 4; i++){
            if(classroom[x][i] == 0 && n < waitlist){
                classroom[x][i] = 1;
                n++;
            }
        }
    } 

    for(int x = 0; x < rows; x++){
        for (int i = 0; i < 4; i++){
            cout << classroom[x][i];
        }
        cout << endl;
    }
    cout << "Remaining students: " << waitlist - n << endl;
}

int main(){
    bool classroom[3][4]{{0, 0, 0, 0},
                         {1, 1, 1, 1},
                         {0, 0, 0, 0}};

    int waitlist = 9;
    fullClass(classroom, 3, waitlist);
}