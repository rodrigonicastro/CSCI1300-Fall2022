// CSCI 1300 Fall 2022
// Author: Graham Toothman and Rodrigo Nicastro
// Recitation: 201 – Elise Tate
// Project 3 - Code Skeleton

#include <iostream>
using namespace std;

class Treasures{
    private:
        int numRings;
        int numNecklaces;
        int numBracelets;
        int numCirclets;
        int numGoblets;
    
    public:
        Treasures();
        int getRings();
        int getNecklaces();
        int getBracelets();
        int getCirclets();
        int getGoblets();
        void setRings(int);
        void setNecklaces(int);
        void setBracelets(int);
        void setCirclets(int);
        void setGoblets(int);
};