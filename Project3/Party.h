// CSCI 1300 Fall 2022
// Author: Graham Toothman and Rodrigo Nicastro
// Recitation: 201 – Elise Tate
// Project 3 - Code Skeleton

#include <iostream>
#include "Player.h"
#include "Cookware.h"
#include "Weapons.h"
#include "Treasures.h"
#include "monster.h"
using namespace std;

class Party{
    private:
        int partySize;
        int numRoomsCleared;
        int numSpacesExplored;
        int numTurns;
        int numKeysFound;
        int numWeapons;
        int gold;
        int armor;
        int ingredients;
        int monstersDefeated;
        char lastAction;
        Player teammates[4];
        Player player;
        Cookware cookware;
        Weapons weapons;
        Treasures treasures;
        Monster monsters[21];

    public:
        Party(Player, Player[], Cookware, Weapons, Treasures, string);
        int getNumRoomsCleared();
        int getKeysFound();
        int getGold();
        int getArmor();
        int getIngredients();
        int getPartySize();
        int getNumWeapons();
        int getNumSpacesExplored();
        int getNumTurns();
        int getMonstersDefeated();
        char getLastAction();
        void setNumRoomsCleared(int);
        void setKeysFound(int);
        void setGold(int);
        void setArmor(int);
        void setIngredients(int);
        void setPartySize(int);
        void setNumWeapons(int);
        void setNumSpacesExplored(int);
        void setNumTurns(int);
        void setMonstersDefeated(int);
        void setLastAction(char);
        void misfortune();
        int fight(bool);
        void cook();
};