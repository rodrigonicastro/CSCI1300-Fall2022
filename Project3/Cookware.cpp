// CSCI 1300 Fall 2022
// Author: Graham Toothman and Rodrigo Nicastro
// Recitation: 201 – Elise Tate
// Project 3 - Code Skeleton

#include <iostream>
#include "Cookware.h"
using namespace std;

Cookware::Cookware(){
    numPots = 0;
    numCauldrons = 0;
    numPans = 0;
}

int Cookware::getPot(){
    return numPots;
}

int Cookware::getPan(){
    return numPans;
}

int Cookware::getCauldron(){
    return numCauldrons;
}

void Cookware::setPot(int updatePot){
    numPots = updatePot;
}

void Cookware::setPan(int updatePan){
    numPans = updatePan;
}

void Cookware::setCauldron(int updateCauldron){
    numCauldrons = updateCauldron;
}