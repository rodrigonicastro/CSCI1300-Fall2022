// CSCI 1300 Fall 2022
// Author: Graham Toothman and Rodrigo Nicastro
// Recitation: 201 – Elise Tate
// Project 3 - Code Skeleton

#include <iostream>
using namespace std;

class Player{
    private:
        string name;
        int fullness;
        bool hasArmor;
        bool hasWeapon;
        bool isAlive;
        string weapon;

    public:
        Player();
        string getName();
        int getFullness();
        bool getArmor();
        bool getHasWeapon();
        bool getIsAlive();
        string getWeapon();
        void setName(string);
        void setFullness(int);
        void setArmor(bool);
        void setHasWeapon(bool);
        void setIsAlive(bool);
        void setWeapon(string);
};