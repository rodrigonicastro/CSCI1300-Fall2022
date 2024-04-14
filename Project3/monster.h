// CSCI 1300 Fall 2022
// Author: Graham Toothman and Rodrigo Nicastro
// Recitation: 201 – Elise Tate
// Project 3 - Code Skeleton

#include <iostream>
using namespace std;

class Monster{
private:
    string name_;
    int pwrLVL_;
    bool dead_;
public:
    Monster();
    Monster(string name, int power);
    string getName();
    void setName(string name);
    int getPower();
    void setPower(int power);
    bool getDead();
    void setDead(bool dead);
};