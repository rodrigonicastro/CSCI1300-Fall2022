// CSCI 1300 Fall 2022
// Author: Graham Toothman and Rodrigo Nicastro
// Recitation: 201 – Elise Tate
// Project 3 - Code Skeleton

#include <iostream>
using namespace std;

class Weapons{
    private:
        int numClubs;
        int numSpears;
        int numRapiers;
        int numAxes;
        int numSwords;

    public:
        Weapons();
        int getClubs();
        int getSpears();
        int getRapiers();
        int getAxes();
        int getSwords();
        void setClubs(int);
        void setSpears(int);
        void setRapiers(int);
        void setAxes(int);
        void setSwords(int);
};