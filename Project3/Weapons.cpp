// CSCI 1300 Fall 2022
// Author: Graham Toothman and Rodrigo Nicastro
// Recitation: 201 – Elise Tate
// Project 3 - Code Skeleton

#include <iostream>
#include "Weapons.h"
using namespace std;

Weapons::Weapons(){
    numAxes = 0;
    numClubs = 0;
    numRapiers = 0;
    numSpears = 0;
    numSwords = 0;
}

int Weapons::getClubs(){
    return numClubs;
}

int Weapons::getSpears(){
    return numSpears;
}

int Weapons::getRapiers(){
    return numRapiers;
}

int Weapons::getAxes(){
    return numAxes;
}

int Weapons::getSwords(){
    return numSwords;
}

void Weapons::setClubs(int updateClubs){
    numClubs = updateClubs;
}

void Weapons::setSpears(int updateSpears){
    numSpears = updateSpears;
}

void Weapons::setRapiers(int updateRapiers){
    numRapiers = updateRapiers;
}

void Weapons::setAxes(int updateAxes){
    numAxes = updateAxes;
}

void Weapons::setSwords(int updateSwords){
    numSwords = updateSwords;
}