// CSCI 1300 Fall 2022
// Author: Graham Toothman and Rodrigo Nicastro
// Recitation: 201 – Elise Tate
// Project 3 - Code Skeleton

#include <iostream>
#include <cassert>
#include "Treasures.h"
#include "Weapons.h"
#include "monster.h"
#include "Party.h"
using namespace std;

int main(){
    //Testing Player class
    Player player = Player();
    player.setName("Rodrigo");
    player.setArmor(true);
    player.setFullness(25);

    cout << "player.getName returned: " << player.getName() << endl;
    cout << "player.getArmor returned: " << player.getArmor() << endl;
    cout << "player.getFullness returned: " << player.getFullness() << endl;

    //Testing Party class
    Party party = Party();
    party.setArmor(5);
    party.setGold(75);
    party.setIngredients(50);
    party.setKeysFound(2);
    party.setPartySize(3);
    party.setRoomsCleared(1);

    cout << "party.getArmor returned: " << party.getArmor() << endl;
    cout << "party.getGold returned: " << party.getGold() << endl;
    cout << "party.getIngredients returned: " << party.getIngredients() << endl;
    cout << "party.getKeysFound returned: " << party.getKeysFound() << endl;
    cout << "party.getPartySize returned: " << party.getPartySize() << endl;
    cout << "party.getRoomsCleared returned: " << party.getRoomsCleared() << endl;

    //Testing Cookware class
    Cookware cookware = Cookware();
    cookware.setCauldron(2);
    cookware.setPan(2);
    cookware.setPot(2);

    cout << "cookware.getCauldron returned: " << cookware.getCauldron() << endl;
    cout << "cookware.getPan returned: " << cookware.getPan() << endl;
    cout << "cookware.getPot returned: " << cookware.getPot() << endl;

    Treasures testTreasures;
    //Test Rings
    testTreasures.setRings(3);
    assert(testTreasures.getRings() == 3);

    //Test Necklaces
    testTreasures.setNecklaces(2);
    assert(testTreasures.getNecklaces() == 2);

    //Test Bracelets
    testTreasures.setBracelets(5);
    assert(testTreasures.getBracelets() == 5);

    //Test Circlets
    testTreasures.setCirclets(1);
    assert(testTreasures.getCirclets() == 1);

    //Test Goblets
    testTreasures.setGoblets(3);
    assert(testTreasures.getGoblets() == 3);

    Weapons weaponstest;
    //Test Clubs
    weaponstest.setClubs(2);
    assert(weaponstest.getClubs() == 2);

    //Test Spears
    weaponstest.setSpears(1);
    assert(weaponstest.getSpears() == 1);
    
    //Test Rapiers
    weaponstest.setRapiers(4);
    assert(weaponstest.getRapiers() == 4);
    
    //Test Axes
    weaponstest.setAxes(5);
    assert(weaponstest.getAxes() == 5);
    
    //Test Swords
    weaponstest.setSwords(2);
    assert(weaponstest.getSwords() == 2);
   
    Monster testMonster("Bob", 1);
    //Test Name
    testMonster.setName("Joe");
    assert(testMonster.getName() == "Joe");

    //Test Power
    testMonster.setPower(3);
    assert(testMonster.getPower() == 3);

    //Test Dead
    testMonster.setDead(true);
    assert(testMonster.getDead() == true);
}

