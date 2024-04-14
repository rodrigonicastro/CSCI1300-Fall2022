// CSCI 1300 Fall 2022
// Author: Graham Toothman and Rodrigo Nicastro
// Recitation: 201 – Elise Tate
// Project 3 - Code Skeleton

#include <iostream>
using namespace std;

class Cookware{
    private:
        int numPots;
        int numPans;
        int numCauldrons;

    public:
        Cookware();
        int getPot();
        int getPan();
        int getCauldron();
        void setPot(int);
        void setPan(int);
        void setCauldron(int);
};