// CSCI 1300 Fall 2022
// Author: Graham Toothman and Rodrigo Nicastro
// Recitation: 201 – Elise Tate
// Project 3 - Code Skeleton

#include <iostream>
#include "Treasures.h"
using namespace std;

Treasures::Treasures(){
    numBracelets = 0;
    numCirclets = 0;
    numGoblets = 0;
    numNecklaces = 0;
    numRings = 0;
}

int Treasures::getRings(){
    return numRings;
}

int Treasures::getNecklaces(){
    return numNecklaces;
}

int Treasures::getBracelets(){
    return numBracelets;
}

int Treasures::getCirclets(){
    return numCirclets;
}

int Treasures::getGoblets(){
    return numGoblets;
}

void Treasures::setRings(int updateRings){
    numRings = updateRings;
}

void Treasures::setNecklaces(int updateNecklaces){
    numNecklaces = updateNecklaces;
}

void Treasures::setBracelets(int updateBracelets){
    numBracelets = updateBracelets;
}

void Treasures::setCirclets(int updateCirclets){
    numCirclets = updateCirclets;
}

void Treasures::setGoblets(int updateGoblets){
    numGoblets = updateGoblets;
}