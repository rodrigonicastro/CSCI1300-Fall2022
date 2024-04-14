// CSCI 1300 Fall 2022
// Author: Graham Toothman and Rodrigo Nicastro
// Recitation: 201 – Elise Tate
// Project 3 - Code Skeleton

#include <iostream>
#include "monster.h"
using namespace std;

Monster::Monster(){
    name_ = "";
    pwrLVL_ = 0;
    dead_ = true;
}

Monster::Monster(string name, int power){
    name_ = name;
    pwrLVL_ = power;
    dead_ = false;
}
string Monster::getName(){
    return name_;
}
void Monster::setName(string name){
    name_ = name;
}
int Monster::getPower(){
    return pwrLVL_;
}
void Monster::setPower(int power){
    pwrLVL_ = power;
}
bool Monster::getDead(){
    return dead_;
}
void Monster::setDead(bool dead){
    dead_ = dead;
}