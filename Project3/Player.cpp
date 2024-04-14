// CSCI 1300 Fall 2022
// Author: Graham Toothman and Rodrigo Nicastro
// Recitation: 201 – Elise Tate
// Project 3 - Code Skeleton

#include <iostream>
#include "Player.h"
using namespace std;

Player::Player(){
    name = "";
    fullness = 50;
    hasArmor = false;
    hasWeapon = false;
    isAlive = true;
    weapon = "";
}

int Player::getFullness(){
    return fullness;
}

string Player::getName(){
    return name;
}

bool Player::getArmor(){
    return hasArmor;
}

bool Player::getHasWeapon(){
    return hasWeapon;
}

bool Player::getIsAlive(){
    return isAlive;
}

string Player::getWeapon(){
    return weapon;
}

void Player::setFullness(int updateFullness){
    fullness = updateFullness;
}

void Player::setName(string inputName){
    name = inputName;
}

void Player::setArmor(bool inputArmor){
    hasArmor = inputArmor;
}

void Player::setHasWeapon(bool inputHasWeapon){
    hasWeapon = inputHasWeapon;
}

void Player::setIsAlive(bool inputIsAlive){
    isAlive = inputIsAlive;
}

void Player::setWeapon(string inputWeapon){
    weapon = inputWeapon;
}