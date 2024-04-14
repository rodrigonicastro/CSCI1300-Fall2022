// CSCI 1300 Fall 2022
// Author: Graham Toothman and Rodrigo Nicastro
// Recitation: 201 – Elise Tate
// Project 3 - Code Skeleton

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include "Party.h"
using namespace std;

int splitt(string input_string, char separator, string arr[], int arr_size){
    int x = 0;
    int y = 0;
    string piece;
    int result = 1;
    bool validSeparator = false;
    int input_string_length = input_string.length();
    
    for(int i = 0, n = 0; i < input_string_length; i++, n++){ 
        if(input_string[i] == separator){
            validSeparator = true;
            arr[x] = piece.assign(input_string, y, n);

            x++;
            y = i + 1;
            n = -1;
            result++;

            if(x == arr_size){
                result = -1;
                break;
            }

            else{
             arr[x] = piece.assign(input_string, y + n + 1, input_string_length - n - 1);   
            }
        }
    }

    if(validSeparator == false){
        result = 1;
        arr[0] = input_string;
    }

    if(input_string == ""){
        result = 0;
    }

    return result;
}

Party::Party(Player player, Player teammates[4], Cookware cookware, Weapons weapons, Treasures treasures, string file_name){
    numRoomsCleared = 0;
    numKeysFound = 0;
    ingredients = 0;
    armor = 0;
    numWeapons = 0;
    gold = 100;
    partySize = 5;
    monstersDefeated = 0;
    numSpacesExplored = 0;
    

    teammates[0] = Player();
    teammates[1] = Player();
    teammates[2] = Player();
    teammates[3] = Player();
    player = Player();

    cookware = Cookware();

    weapons = Weapons();

    treasures = Treasures();

    ifstream in_file;
    in_file.open(file_name);
    int i=0, splitReturn, pow=0;
    string line;
    while(getline(in_file, line)){
        string arr[2];
        splitReturn = splitt(line, ',', arr, 2);
        pow = stoi(arr[1]);
        Monster tempMon(arr[0], pow);
        monsters[i] = tempMon;
        i++;
    }

}

int Party::getNumRoomsCleared(){
    return numRoomsCleared;
}

int Party::getKeysFound(){
    return numKeysFound;
}

int Party::getGold(){
    return gold;
}

int Party::getArmor(){
    return armor;
}

int Party::getIngredients(){
    return ingredients;
}

int Party::getPartySize(){
    return partySize;
}

int Party::getNumWeapons(){
    return numWeapons;
}

int Party::getNumSpacesExplored(){
    return numSpacesExplored;
}

int Party::getNumTurns(){
    return numTurns;
}

int Party::getMonstersDefeated(){
    return monstersDefeated;
}

char Party::getLastAction(){
    return lastAction;
}

void Party::setNumRoomsCleared(int updateRoomsCleared){
    numRoomsCleared = updateRoomsCleared;
}

void Party::setKeysFound(int updateKeysFound){
    numKeysFound = updateKeysFound;
}

void Party::setGold(int updateGold){
    gold = updateGold;
}

void Party::setArmor(int updateArmor){
    armor = updateArmor;
}

void Party::setIngredients(int updateIngredients){
    ingredients = updateIngredients;
}

void Party::setPartySize(int inputSize){
    partySize = inputSize;
}

void Party::setNumWeapons(int inputWeapons){
    numWeapons = inputWeapons;
}

void Party::setNumSpacesExplored(int inputExploredSpaces){
    numSpacesExplored = inputExploredSpaces;
}

void Party::setNumTurns(int inputTurns){
    numTurns = inputTurns;
}

void Party::setMonstersDefeated(int inputMonstersDefeated){
    monstersDefeated = inputMonstersDefeated;
}

void Party::setLastAction(char inputAction){
    lastAction = inputAction;
}

void Party::misfortune(){
    srand(time(NULL));

    if(rand() % 10 <= 3){
        int misfortune = rand() % 10;
        
        if(misfortune <= 2){
            cout << "OH NO! Your team was robbed by dungeon bandits!" << endl;
            int robbedItem = rand() % 3;

            switch(robbedItem){
                case 0:{
                    if(ingredients >= 10){
                        setIngredients(ingredients - 10);
                        cout << "You lost 10 kg of ingredients!" << endl;
                    }

                    else if(ingredients == 5){
                        setIngredients(0);
                        cout << "You lost 5 kg of ingredients!" << endl;
                    }
                    
                    else{
                        cout << "They tried to take your ingredients, but you didn't have any." << endl;
                    }
                    break;
                }
                
                case 1:{
                    int robbedCookware = rand() % 3;

                    switch(robbedCookware){
                        case 0:
                            if(cookware.getPot() >= 1){
                                cout << "You lost 1 Ceramic Pot!" << endl;
                                cookware.setPot(cookware.getPot() - 1);
                            }

                            else{
                                cout << "They tried to take your Ceramic Pot, but you didn't have any." << endl;
                            }
                            break;
                        
                        case 1:
                            if(cookware.getPan() >= 1){
                                cout << "You lost 1 Frying Pan!" << endl;
                                cookware.setPan(cookware.getPan() - 1);
                            }

                            else{
                                cout << "They tried to take your Frying Pan, but you didn't have any." << endl;
                            }
                            break;

                        case 2:
                            if(cookware.getCauldron() >= 1){
                                cout << "You lost 1 Cauldron!" << endl;
                                cookware.setCauldron(cookware.getCauldron() - 1);
                            }

                            else{
                                cout << "They tried to take your Cauldron, but you didn't have any." << endl;
                            }
                    }
                    break;
                }

                case 2:{
                    if(armor >= 1){
                        switch(rand() % 5){
                            case 0:
                                if(player.getArmor() == true){
                                    player.setArmor(false);
                                    armor -= 1;

                                    cout << "You lost your armor!" << endl;
                                }

                                else{
                                    cout << "They tried to take your armor, but you didn't have any." << endl;
                                }
                                break;

                            case 1:
                                if(teammates[0].getArmor() == true){
                                    teammates[0].setArmor(false);
                                    armor -= 1;

                                    cout << teammates[0].getName() << " lost their armor!" << endl;
                                }

                                else{
                                    cout << "They tried to take " << teammates[0].getName() << "'s armor, but they didn't have any." << endl;
                                }
                                break;

                            case 2:
                                if(teammates[1].getArmor() == true){
                                    teammates[1].setArmor(false);
                                    armor -= 1;

                                    cout << teammates[1].getName() << " lost their armor!" << endl;
                                }

                                else{
                                    cout << "They tried to take " << teammates[1].getName() << "'s armor, but they didn't have any." << endl;
                                }
                                break;

                            case 3:
                                if(teammates[2].getArmor() == true){
                                    teammates[2].setArmor(false);
                                    armor -= 1;

                                    cout << teammates[2].getName() << " lost their armor!" << endl;
                                }

                                else{
                                    cout << "They tried to take " << teammates[2].getName() << "'s armor, but they didn't have any." << endl;
                                }
                                break;                

                            case 4:
                                if(teammates[3].getArmor() == true){
                                    teammates[3].setArmor(false);
                                    armor -= 1;

                                    cout << teammates[3].getName() << " lost their armor!" << endl;
                                }

                                else{
                                    cout << "Theye tried to take " << teammates[3].getName() << "'s armor, but they didn't have any." << endl;
                                }
                                break;                                                
                        }
                    }

                    else{
                        cout << "They tried to take someone's armor, but no one had any." << endl;
                    }
                }
                    
            }
        }

        else if(misfortune == 3){
            int brokenItem = rand() % 2;

            if(brokenItem == 0 && armor > 0){    
                bool teammateWithArmor = false;

                for(int i = 0; i < 4; i++){
                    if(teammates[i].getArmor() == true){
                        teammateWithArmor = true;
                        teammates[i].setArmor(false);
                        armor -= 1;

                        cout << "OH NO! " << teammates[i].getName() << "'s armor broke!" << endl;
                        break;
                    }
                }

                if(teammateWithArmor == false){
                    player.setArmor(false);
                    armor -= 1;

                    cout << "OH NO! Your armor broke!" << endl;
                }
            }

            else if(brokenItem == 1 && numWeapons > 0){
                bool teammateWithWeapon = false;

                for(int i = 0; i < 4; i++){
                    if(teammates[i].getHasWeapon() == true){
                        teammateWithWeapon = true;
                        teammates[i].setHasWeapon(false);
                        numWeapons -= 1;

                        cout << "OH NO! " << teammates[i].getName() << "'s " << teammates[i].getWeapon() << " broke!" << endl;
                        break;
                    }
                }

                if(teammateWithWeapon == false){
                    player.setHasWeapon(false);
                    numWeapons -= 1;

                    cout << "OH NO! Your " << player.getWeapon() << " broke!" << endl;
                }
            }
        }

        else if(misfortune >= 4 && misfortune <= 6){
            int partyMember = rand() % 5;

            switch(partyMember){
                case 0:
                    player.setFullness(player.getFullness() - 10);
                    
                    if(player.getFullness() <= 0){
                        cout << "OH NO! " << player.getName() << " has died of hunger!" << endl;
                        player.setIsAlive(false);
                        //end game
                    }

                    break;

                case 1:
                    teammates[0].setFullness(teammates[0].getFullness() - 10);

                    cout << "OH NO! " << teammates[0].getName() << " was poisoned! They lost 10 points of fullness!" << endl;
                    
                    if(teammates[0].getFullness() <= 0){
                        partySize -= 1;
                        teammates[0].setIsAlive(false);
                        

                        cout << "OH NO! " << teammates[0].getName() << " has died of hunger!" << endl;
                        cout << "Your party was reduced to " << partySize << " members." << endl;

                        if(teammates[0].getHasWeapon() == true){
                            cout << "You can no longer use their " << teammates[0].getWeapon() << "." << endl;
                            numWeapons -= 1;

                            if(teammates[0].getWeapon() == "Stone Club"){
                                weapons.setClubs(weapons.getClubs() - 1);
                            }

                            else if(teammates[0].getWeapon() == "Iron Spear"){
                                weapons.setSpears(weapons.getSpears() - 1);
                            }

                            else if(teammates[0].getWeapon() == "(+1) Mythril Rapier"){
                                weapons.setRapiers(weapons.getRapiers() - 1);
                            }

                            else if(teammates[0].getWeapon() == "(+2) Flaming Battle-Axe"){
                                weapons.setAxes(weapons.getAxes() - 1);
                            }

                            else{
                                weapons.setSwords(weapons.getSwords() - 1);
                            }
                        }
                    }
                    break;

                case 2:
                    teammates[1].setFullness(teammates[1].getFullness() - 10);
                    
                    cout << "OH NO! " << teammates[1].getName() << " was poisoned! They lost 10 points of fullness!" << endl;
                    
                    if(teammates[1].getFullness() <= 0){
                        partySize -= 1;
                        teammates[1].setIsAlive(false);

                        cout << "OH NO! " << teammates[1].getName() << " has died of hunger!" << endl;
                        cout << "Your party was reduced to " << partySize << " members." << endl;                        

                        if(teammates[1].getHasWeapon() == true){
                            cout << "You can no longer use their " << teammates[1].getWeapon() << "." << endl;
                            numWeapons -= 1;

                            if(teammates[1].getWeapon() == "Stone Club"){
                                weapons.setClubs(weapons.getClubs() - 1);
                            }

                            else if(teammates[1].getWeapon() == "Iron Spear"){
                                weapons.setSpears(weapons.getSpears() - 1);
                            }

                            else if(teammates[1].getWeapon() == "(+1) Mythril Rapier"){
                                weapons.setRapiers(weapons.getRapiers() - 1);
                            }

                            else if(teammates[1].getWeapon() == "(+2) Flaming Battle-Axe"){
                                weapons.setAxes(weapons.getAxes() - 1);
                            }

                            else{
                                weapons.setSwords(weapons.getSwords() - 1);
                            }
                        }
                    }
                    break;
                
                case 3:
                    teammates[2].setFullness(teammates[2].getFullness() - 10);
                    
                    cout << "OH NO! " << teammates[2].getName() << " was poisoned! They lost 10 points of fullness!" << endl;
                    
                    if(teammates[2].getFullness() <= 0){
                        partySize -= 1;
                        teammates[2].setIsAlive(false);

                        cout << "OH NO! " << teammates[2].getName() << " has died of hunger!" << endl;
                        cout << "Your party was reduced to " << partySize << " members." << endl;

                        if(teammates[2].getHasWeapon() == true){
                            cout << "You can no longer use their " << teammates[0].getWeapon() << "." << endl;
                            numWeapons -= 1;

                            if(teammates[2].getWeapon() == "Stone Club"){
                                weapons.setClubs(weapons.getClubs() - 1);
                            }

                            else if(teammates[2].getWeapon() == "Iron Spear"){
                                weapons.setSpears(weapons.getSpears() - 1);
                            }

                            else if(teammates[2].getWeapon() == "(+1) Mythril Rapier"){
                                weapons.setRapiers(weapons.getRapiers() - 1);
                            }

                            else if(teammates[2].getWeapon() == "(+2) Flaming Battle-Axe"){
                                weapons.setAxes(weapons.getAxes() - 1);
                            }

                            else{
                                weapons.setSwords(weapons.getSwords() - 1);
                            }
                        }
                    }
                    break;

                case 4:
                    teammates[3].setFullness(teammates[3].getFullness() - 10);
                    
                    cout << "OH NO! " << teammates[3].getName() << " was poisoned! They lost 10 points of fullness!" << endl;
                    
                    if(teammates[3].getFullness() <= 0){
                        partySize -= 1;
                        teammates[3].setIsAlive(false);

                        cout << "OH NO! " << teammates[3].getName() << " has died of hunger!" << endl;
                        cout << "Your party was reduced to " << partySize << " members." << endl;

                        if(teammates[3].getHasWeapon() == true){
                            cout << "You can no longer use their " << teammates[0].getWeapon() << "." << endl;
                            numWeapons -= 1;

                            if(teammates[3].getWeapon() == "Stone Club"){
                                weapons.setClubs(weapons.getClubs() - 1);
                            }

                            else if(teammates[3].getWeapon() == "Iron Spear"){
                                weapons.setSpears(weapons.getSpears() - 1);
                            }

                            else if(teammates[3].getWeapon() == "(+1) Mythril Rapier"){
                                weapons.setRapiers(weapons.getRapiers() - 1);
                            }

                            else if(teammates[3].getWeapon() == "(+2) Flaming Battle-Axe"){
                                weapons.setAxes(weapons.getAxes() - 1);
                            }

                            else{
                                weapons.setSwords(weapons.getSwords() - 1);
                            }
                        }
                    }
                    break;
            }
        }

        else{
            if(lastAction == 'O'){
                int randTeammate = rand() % 4;
                partySize -= 1;
                

                cout << "OH NO! Your teammate <party_member> is trapped in the previous room and is unable to get through. You must continue without them." << endl;
                cout << "Your party size has reduced to " << partySize << " members." << endl;

                switch(randTeammate){
                    case 0:
                        if(teammates[0].getHasWeapon() == true){
                            numWeapons -= 1;
                            teammates[0].setHasWeapon(false);
                            teammates[0].setWeapon("");
                        }

                        if(teammates[0].getArmor() == true){
                            armor -= 1;
                            teammates[0].setArmor(false);
                        }
                        break;

                    case 1:
                        if(teammates[1].getHasWeapon() == true){
                            numWeapons -= 1;
                            teammates[1].setHasWeapon(false);
                            teammates[1].setWeapon("");
                        }

                        if(teammates[1].getArmor() == true){
                            armor -= 1;
                            teammates[1].setArmor(false);
                        }
                        break;

                    case 2:
                        if(teammates[2].getHasWeapon() == true){
                            numWeapons -= 1;
                            teammates[2].setHasWeapon(false);
                            teammates[2].setWeapon("");
                        }

                        if(teammates[2].getArmor() == true){
                            armor -= 2;
                            teammates[2].setArmor(false);
                        }
                        break;

                    case 3:
                        if(teammates[3].getHasWeapon() == true){
                            numWeapons -= 1;
                            teammates[3].setHasWeapon(false);
                            teammates[3].setWeapon("");
                        }

                        if(teammates[3].getArmor() == true){
                            armor -= 1;
                            teammates[3].setArmor(false);
                        }
                        break;
                }
            }
                
        }
    }
}

int Party::fight(bool room){
    int result = 0;
    switch(room){
        case true:{
            int d=4;
            int randomInt = (rand() % 4);
            Monster activeMon = monsters[randomInt + numRoomsCleared + 1];
            while (activeMon.getDead() == true){
                randomInt = (rand() % 4);
                activeMon = monsters[randomInt + numRoomsCleared + 1];
            }
            for (int i=0; i < 3; i++){
                if (player.getName() == teammates[i].getName()){
                    d=0;
                }
                for (int j=(i+1); j < 4; j++){
                    if (teammates[i].getName() == teammates[j].getName()){
                        d=0;
                    }
                }
            }
            cout << "Inside the room is the " << activeMon.getName() << endl;
            int w = numWeapons;
            if(player.getWeapon() == "(+1) Mythril Rapier"){
                w++;
            }

            else if(player.getWeapon() == "(+2) Flaming Battle-Axe"){
                w+=2;
            }

            else if(player.getWeapon() == "(+3) Vorpal Longsword"){
                w+=3;
            }
            for (int i=0; i < (partySize-1); i++){
                if(teammates[i].getWeapon() == "(+1) Mythril Rapier"){
                    w++;
                }

                else if(teammates[i].getWeapon() == "(+2) Flaming Battle-Axe"){
                    w+=2;
                }

                else if(teammates[i].getWeapon() == "(+3) Vorpal Longsword"){
                    w+=3;
                }
            }
            for (int i=0; i < partySize-3; i++){
                if (teammates[i].getWeapon() == player.getWeapon() || teammates[i].getWeapon() == teammates[partySize-(i+2)].getWeapon()){
                    d=0;
                } 
            }
            result = ((rand() % 6+1)*w + d - (((rand() % 6+1)*activeMon.getPower())/armor));
            if (result > 0){
                gold = gold + (10*activeMon.getPower());
                ingredients = ingredients + (5*activeMon.getPower());
                if (rand() % 10+1 == 1){
                    numKeysFound++;
                }
                monsters[randomInt + numRoomsCleared + 1].setDead(true);
                numRoomsCleared++;
                cout << "Congratulations you defeated the " << activeMon.getName() << endl;
                monstersDefeated++;
            }
            else {
                gold = gold - (gold/4);
                if (ingredients >= 30){
                    ingredients-=30;
                }
                else {
                    ingredients = 0;
                }
                for (int i=0; i < (partySize-1); i++){
                    if (rand() % 10+1 == 1 && teammates[i].getArmor() == false){
                        cout << "Sadly " << teammates[i].getName() << " was slain in combat." << endl;
                        teammates[i].setIsAlive(false);
                        teammates[i] = teammates[partySize-2];
                        partySize--;
                    }
                    else if (rand() % 20+1 == 1){
                        cout << "Sadly " << teammates[i].getName() << " was slain in combat." << endl;
                        teammates[i].setIsAlive(false);
                        teammates[i] = teammates[partySize-2];
                        partySize--;
                    }
                }
            }
            for (int i=0; i < (partySize-1); i++){
                if(rand() % 2+1 == 1){
                    teammates[i].setFullness((teammates[i].getFullness()-1));
                }
            }
            if(rand() % 2+1 == 1){
                player.setFullness((player.getFullness()-1));
            }
            break;
        }
        case false:{
            int d=4;
            int randomInt = (rand() % 4);
            Monster activeMon = monsters[randomInt + numRoomsCleared];
            while (activeMon.getDead() == true){
                randomInt = (rand() % 4);
                activeMon = monsters[randomInt + numRoomsCleared];
            }
            for (int i=0; i < 3; i++){
                if (player.getName() == teammates[i].getName()){
                    d=0;
                }
                for (int j=(i+1); j < 4; j++){
                    if (teammates[i].getName() == teammates[j].getName()){
                        d=0;
                    }
                }
            }
            cout << "You encountered the " << activeMon.getName() << endl;
            int w = numWeapons;
            if(player.getWeapon() == "(+1) Mythril Rapier"){
                w++;
            }

            else if(player.getWeapon() == "(+2) Flaming Battle-Axe"){
                w+=2;
            }

            else if(player.getWeapon() == "(+3) Vorpal Longsword"){
                w+=3;
            }
            for (int i=0; i < (partySize-1); i++){
                if(teammates[i].getWeapon() == "(+1) Mythril Rapier"){
                    w++;
                }

                else if(teammates[i].getWeapon() == "(+2) Flaming Battle-Axe"){
                    w+=2;
                }

                else if(teammates[i].getWeapon() == "(+3) Vorpal Longsword"){
                    w+=3;
                }
            }
            result = ((rand() % 6+1)*w + d - (((rand() % 6+1)*activeMon.getPower())/armor));
            if (result > 0){
                gold = gold + (10*activeMon.getPower());
                ingredients = ingredients + (5*activeMon.getPower());
                if (rand() % 10+1 == 1){
                    numKeysFound++;
                }
                monsters[randomInt + numRoomsCleared].setDead(true);
                cout << "Congratulations you defeated the " << activeMon.getName() << endl;
                numRoomsCleared++;
                monstersDefeated++;
            }
            else {
                gold = gold - (gold/4);
                if (ingredients >= 30){
                    ingredients-=30;
                }
                else {
                    ingredients = 0;
                }
                for (int i=0; i < (partySize-1); i++){
                    if (rand() % 10+1 == 1 && teammates[i].getArmor() == false){
                        cout << "Sadly " << teammates[i].getName() << " was slain in combat." << endl;
                        teammates[i].setIsAlive(false);
                        teammates[i] = teammates[partySize-2];
                        partySize--;
                    }
                    else if (rand() % 20+1 == 1){
                        cout << "Sadly " << teammates[i].getName() << " was slain in combat." << endl;
                        teammates[i].setIsAlive(false);
                        teammates[i] = teammates[partySize-2];
                        partySize--;
                    }
                }
            }
            for (int i=0; i < (partySize-1); i++){
                if(rand() % 2+1 == 1){
                    teammates[i].setFullness((teammates[i].getFullness()-1));
                }
            }
            if(rand() % 2+1 == 1){
                player.setFullness((player.getFullness()-1));
            }
            break;
        }
    }
    return result;
}


void Party::cook(){
    int cookwareChoice;
    int ingredientAmount;
    int fullnessIncrease;

    cout << "Which cookware item would you like to use? Remember that each type has a different probability of breaking when used, marked with (XX%)." << endl;
    cout << "1. Ceramic Pot (25%)" << endl;
    cout << "2. Frying Pan (10%)" << endl;
    cout << "3. Cauldron (02%)" << endl;
    cout << "4. Cancel" << endl;
    cin >> cookwareChoice;

    while(cookwareChoice > 4 || cookwareChoice < 1){
        cout << "That's not a valid option. Choose a number between 1-4:" << endl;
        cout << "1. Ceramic Pot (25%)" << endl;
        cout << "2. Frying Pan (10%)" << endl;
        cout << "3. Cauldron (02%)" << endl;
        cout << "4. Cancel" << endl;
        cin >> cookwareChoice;
    }

    if(cookwareChoice != 4){
        cout << "How many ingredients would you like to use? (Enter a positive multiple of 5, or 0 to cancel)" << endl;
        cin >> ingredientAmount;

        while(ingredientAmount % 5 != 0 || ingredientAmount < 0){
            cout << "That's not a valid number. Enter a positive multiple of 5, or 0 to cancel." << endl;
            cin >> ingredientAmount;
            
        }

        while(ingredients - ingredientAmount < 0){
            if(ingredientAmount % 5 != 0 || ingredientAmount < 0){
                cout << "That's not a valid number. Enter a positive multiple of 5, or 0 to cancel." << endl;
            }
            
            else{
                cout << "You don't have that many ingredients! Enter a positive multiple of 5, or 0 to cancel." << endl;
            }            

            cin >> ingredientAmount;
        }

        if(ingredientAmount != 0){
            srand(time(NULL));

            switch(cookwareChoice){
                case 1:                    
                    if((rand() % 100) < 25){
                        cout << "OH NO! Your Cermaic Pot broke! You also lost " << ingredientAmount << " ingredients!" << endl;
                    }

                    else{
                        ingredients -= ingredientAmount;
                        fullnessIncrease = ingredientAmount / 5;

                        player.setFullness(player.getFullness() + fullnessIncrease);

                        for(int i = 0; i < 4; i++){
                            teammates[i].setFullness(teammates[i].getFullness() + fullnessIncrease);
                        }
                    }
                    break;

                case 2:
                    if((rand() % 10) == 0){
                        cout << "OH NO! Your Frying Pan broke! You also lost " << ingredientAmount << " ingredients!" << endl;                         
                    }

                    else{
                        ingredients -= ingredientAmount;
                        fullnessIncrease = ingredientAmount / 5;

                        player.setFullness(player.getFullness() + fullnessIncrease);

                        for(int i = 0; i < 4; i++){
                            teammates[i].setFullness(teammates[i].getFullness() + fullnessIncrease);
                        }
                    }
                    break;

                case 3:
                    if(rand() % 100 <= 1){
                        cout << "OH NO! Your Cauldron broke! You also lost " << ingredientAmount << " ingredients!" << endl;                         
                    }

                    else{
                        ingredients -= ingredientAmount;
                        fullnessIncrease = ingredientAmount / 5;
                        
                        player.setFullness(player.getFullness() + fullnessIncrease);

                        for(int i = 0; i < 4; i++){
                            teammates[i].setFullness(teammates[i].getFullness() + fullnessIncrease);
                        }                        
                    }
                    break;
            }

            cout << "+----------------------------------------+" << endl;
            cout << "|                Fullness                |" << endl;
            cout << "+----------------------------------------+" << endl;
            cout << "| " << player.getName() << ": " << player.getFullness();
            
            if(player.getFullness() > 9){
                for(int i = 0; i < 40 - player.getName().length() - 5; i++){cout << " ";}cout << "|" << endl;
            }

            else{
                for(int i = 0; i < 40 - player.getName().length() - 4; i++){cout << " ";}cout << "|" << endl;                            
            }

            cout << "| " << teammates[0].getName() << ": " << teammates[0].getFullness();
            
            if(teammates[0].getFullness() > 9){
                for(int i = 0; i < 40 - teammates[0].getName().length() - 5; i++){cout << " ";}cout << "|" << endl;
            }

            else{
                for(int i = 0; i < 40 - teammates[0].getName().length() - 4; i++){cout << " ";}cout << "|" << endl;                            
            }

            cout << "| " << teammates[1].getName() << ": " << teammates[1].getFullness();

            if(teammates[1].getFullness() > 9){
                for(int i = 0; i < 40 - teammates[1].getName().length() - 5; i++){cout << " ";}cout << "|" << endl;
            }

            else{
                for(int i = 0; i < 40 - teammates[1].getName().length() - 4; i++){cout << " ";}cout << "|" << endl;                            
            }

            cout << "| " << teammates[2].getName() << ": " << teammates[2].getFullness();

            if(teammates[2].getFullness() > 9){
                for(int i = 0; i < 40 - teammates[2].getName().length() - 5; i++){cout << " ";}cout << "|" << endl;
            }

            else{
                for(int i = 0; i < 40 - teammates[2].getName().length() - 4; i++){cout << " ";}cout << "|" << endl;                            
            }

            cout << "| " << teammates[3].getName() << ": " << teammates[3].getFullness();

            if(teammates[3].getFullness() > 9){
                for(int i = 0; i < 40 - teammates[3].getName().length() - 5; i++){cout << " ";}cout << "|" << endl;
            }

            else{
                for(int i = 0; i < 40 - teammates[3].getName().length() - 4; i++){cout << " ";}cout << "|" << endl;                            
            }

            cout << "+----------------------------------------+" << endl;
            cout << "| Ingredients left: " << ingredients; for(int i = 0; i < 40 - (trunc(log10(ingredients)) + 1) - 19; i++){cout << " ";}cout << "|" << endl;
            cout << "+----------------------------------------+" << endl;
        }
    }
} 