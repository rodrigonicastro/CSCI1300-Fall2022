#include <iostream>
#include <fstream>
#include <vector>
#include "Map.h"
#include "Party.h"
using namespace std;

int split(string input_string, char separator, string arr[], int arr_size){
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

void printInventory(Party party, Weapons weapons, Treasures treasures, Cookware cookware){
    cout << "+-------------+" << endl;
    cout << "| INVENTORY   |" << endl;
    cout << "+-------------+" << endl;
    cout << "| Gold        | " << party.getGold() << endl;
    cout << "| Ingredients | " << party.getIngredients() << " kg" << endl;
    cout << "| Cookware    | P: " << cookware.getPot() << " | F: " << cookware.getPan() << " | C: " << cookware.getCauldron() << endl;
    cout << "| Weapons     | C: " << weapons.getClubs() << " | S: " << weapons.getSpears() << " | R: " << weapons.getRapiers() << " | B: " << weapons.getAxes() << "| L: " << weapons.getSwords() << endl;
    cout << "| Armor       | " << party.getArmor() << endl;
    cout << "| Treasures   | R: " << treasures.getRings() << " | N: " << treasures.getNecklaces() << " | B: " << treasures.getBracelets() << " | C: " << treasures.getCirclets() << " | G: " << treasures.getGoblets() << endl;
    cout << "+-------------+" << endl;
    cout << endl;
}

void printMerchantChoices(){ 
    cout << "Choose one of the following:" << endl;
    cout << " 1. Ingredients: To make food, you have to cook raw ingredients." << endl;
    cout << " 2. Cookware: You will need something to cook those ingredients." << endl;
    cout << " 3. Weapons: It's dangerous to go alone, take this!" << endl;
    cout << " 4. Armor: If you want to survive monster attacks, you will need some armor." << endl;
    cout << " 5. Sell treasures: If you find anything shiny, I would be happy to take it off your hands." << endl;
    cout << " 6. Leave: Make sure you get everything you need, I'm leaving after this sale!" << endl; 
}

int checkChoice(){
    int menuChoice;
    cin >> menuChoice;

    while(menuChoice > 6 || menuChoice < 1){
        cout << endl << "That's not an option. Choose a number between 1-6." << endl;
        printMerchantChoices();
        cin >> menuChoice;
    }

    return menuChoice;
}

void merchantMenu(Party &party, Weapons &weapons, Treasures &treasures, Cookware &cookware, Player &player, Player teammates[4]){
    cout << "If you're looking to get supplies, you've come to the right place." << endl;
    cout << "I would be happy to part with some of my wares...for the proper price!" << endl;
    printInventory(party, weapons, treasures, cookware);
    printMerchantChoices();
    int menuChoice = checkChoice();
    char exitConfirmation = 'n';

    while(exitConfirmation != 'y' && exitConfirmation != 'Y'){
        switch(menuChoice){
            case 1:{
                int ingredientPrice = 1*(1 + 0.25*party.getNumRoomsCleared());
                int updateIngredients;
                char confirmation;
                int updateGold;
                int numKgs;
                
                cout << "How many kg of ingredients do you need [" << ingredientPrice << " Gold/kg]? (Enter a positive mulitple of 5, or 0 to cancel)" << endl;
                cin >> numKgs;

                while(numKgs < 0 || numKgs % 5 != 0){
                    cout << "That's not a valid number. Enter a positive mulitple of 5, or 0 to cancel." << endl;
                    cin >> numKgs;
                }                

                if(numKgs == 0){
                    cout << "That's fine. What else can I get for you?" << endl;
                }

                else if(numKgs > 0 && numKgs % 5 == 0){
                    if(party.getGold() - (numKgs*ingredientPrice) >= 0){
                        
                        cout << "You want to buy " << numKgs << " kg of ingredients for " << numKgs*ingredientPrice << " gold? (y/n)" << endl;
                        cin >> confirmation;

                        while(confirmation != 'y' && confirmation != 'Y' && confirmation != 'n' && confirmation != 'N'){
                            cout << "I didn't understand. Do you want to buy " << numKgs << " kg of ingredients for " << numKgs*ingredientPrice << "gold? (y/n)" << endl;
                            cin >> confirmation;
                        }                        

                        if(confirmation == 'y' || confirmation == 'Y'){
                            updateGold = party.getGold() - numKgs*ingredientPrice;
                            party.setGold(updateGold);

                            updateIngredients = party.getIngredients() + numKgs;
                            party.setIngredients(updateIngredients);

                            cout << "Thank you for your patronage! What else can I get for you?" << endl;
                            printInventory(party, weapons, treasures, cookware);
                        }

                        else{
                            cout << "That's fine. What else can I get for you?" << endl;
                        }
                    }

                    else{
                        cout << "You don't have enough gold to buy that." << endl;
                    }
                }

                printMerchantChoices();
                menuChoice = checkChoice();
                break;
            }

            case 2:{
                int potPrice = 2*(1 + 0.25*party.getNumRoomsCleared());
                int panPrice = 10*(1 + 0.25*party.getNumRoomsCleared());
                int cauldronPrice = 20*(1 + 0.25*party.getNumRoomsCleared());
                int cookwareChoice;
                int cookwareAmount;
                int updateCookware;
                int updateGold;
                char confirmation;

                cout << "I have a several types of cookware, which one would you like?" << endl;
                cout << "Each type has a different probability of breaking when used, marked with (XX%)." << endl;
                cout << endl << "Choose one of the following:" << endl;
                cout << " 1. (25%) Ceramic Pot [2 Gold]" << endl;
                cout << " 2. (10%) Frying Pan [10 Gold]" << endl;
                cout << " 3. (02%) Cauldron [20 Gold]" << endl;
                cout << " 4. Cancel" << endl;
                cin >> cookwareChoice;

                while(cookwareChoice < 0 || cookwareChoice > 4){
                    cout << "That's not an option. Choose a number between 1-4." << endl;
                    cin >> cookwareChoice;
                }

                if(cookwareChoice != 4){
                    cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                    cin >> cookwareAmount;

                    while(cookwareAmount < 0){
                        cout << "That's not a valid amount. Enter a positive integer, or 0 to cancel." << endl;
                        cin >> cookwareAmount;
                    }

                    if(cookwareAmount == 0){
                        cout << "That's fine. What else can I do for you?" << endl;
                    }

                    else{
                        if(cookwareChoice == 1){
                            if(party.getGold() - (cookwareAmount * potPrice) >= 0){
                                cout << "You want to buy " << cookwareAmount << " Ceramic Pot(s) for " << cookwareAmount*potPrice << " gold? (y/n)" << endl;
                                cin >> confirmation;

                                while(confirmation != 'y' && confirmation != 'Y' && confirmation != 'n' && confirmation != 'N'){
                                    cout << "I didn't understand. Do you want to buy " << cookwareAmount << " Ceramic Pot(s) for " << cookwareAmount*potPrice << " gold? (y/n)" << endl;
                                    cin >> confirmation;
                                }

                                if(confirmation == 'y' || confirmation == 'Y'){
                                    updateCookware = cookware.getPot() + cookwareAmount;
                                    cookware.setPot(updateCookware);

                                    updateGold = party.getGold() - (cookwareAmount*potPrice);
                                    party.setGold(updateGold);

                                    cout << "Thank you for your patronage! What else can I get for you?" << endl;
                                    printInventory(party, weapons, treasures, cookware);
                                }

                                else{
                                    cout << "That's fine. What else can I get for you?" << endl;
                                }
                            }

                            else{
                                cout << "You don't have enough gold to buy that." << endl;
                            }
                        }

                        else if(cookwareChoice == 2){
                            if(party.getGold() - (cookwareAmount*panPrice) >= 0){
                                cout << "You want to buy " << cookwareAmount << " Frying Pan(s) for " << cookwareAmount*panPrice << " gold? (y/n)" << endl;
                                cin >> confirmation;

                                while(confirmation != 'y' && confirmation != 'Y' && confirmation != 'n' && confirmation != 'N'){
                                    cout << "I didn't understand. Do you want to buy " << cookwareAmount << " Frying Pan(s) for " << cookwareAmount*panPrice << " gold? (y/n)" << endl;
                                    cin >> confirmation;
                                }

                                if(confirmation == 'y' || confirmation == 'Y'){
                                    updateCookware = cookware.getPan() + cookwareAmount;
                                    cookware.setPan(updateCookware);

                                    updateGold = party.getGold() - (cookwareAmount*panPrice);
                                    party.setGold(updateGold);

                                    cout << "Thank you for your patronage! What else can I get for you?" << endl;
                                    printInventory(party, weapons, treasures, cookware);
                                }

                                else{
                                    cout << "That's fine. What else can I get for you?" << endl;
                                }
                            }

                            else{
                                cout << "You don't have enough gold to buy that." << endl;
                            }
                        }

                        else if(cookwareChoice == 3){
                            if(party.getGold() - (cookwareAmount*cauldronPrice) >= 0){
                                cout << "You want to buy " << cookwareAmount << " Cauldron(s) for " << cookwareAmount*cauldronPrice << " gold? (y/n)" << endl;
                                cin >> confirmation;

                                while(confirmation != 'y' && confirmation != 'Y' && confirmation != 'n' && confirmation != 'N'){
                                    cout << "I didn't understand. Do you want to buy " << cookwareAmount << " Cauldron(s) for " << cookwareAmount*cauldronPrice << " gold? (y/n)" << endl;
                                    cin >> confirmation;
                                }

                                if(confirmation == 'y' || confirmation == 'Y'){
                                    updateCookware = cookware.getCauldron() + cookwareAmount;
                                    cookware.setCauldron(updateCookware);

                                    updateGold = party.getGold() - (cookwareAmount*cauldronPrice);
                                    party.setGold(updateGold);

                                    cout << "Thank you for your patronage! What else can I get for you?" << endl;
                                    printInventory(party, weapons, treasures, cookware);
                                }

                                else{
                                    cout << "That's fine. What else can I get for you?" << endl;
                                }                        
                            }   

                            else{
                                cout << "You don't have enough gold to buy that." << endl;
                            }                    
                        }                    
                    }
                }
            
                else{
                    cout << "That's fine. What else can I get for you?" << endl;
                }

                printMerchantChoices();
                menuChoice = checkChoice();
                break;
            }

            case 3:{
                int clubPrice = 2*(1 + 0.25*party.getNumRoomsCleared());
                int spearPrice = 2*(1 + 0.25*party.getNumRoomsCleared());
                int rapierPrice = 5*(1 + 0.25*party.getNumRoomsCleared());
                int axePrice = 15*(1 + 0.25*party.getNumRoomsCleared());
                int swordPrice = 50*(1 + 0.25*party.getNumRoomsCleared());
                char confirmation;
                int weaponChoice;
                int weaponAmount;
                int remainingAmount;
                int updateWeapons;
                int updateGold;

                cout << "I have a plentiful collection of weapons to choose from, what would you like?" << endl;
                cout << "Note that some of them provide you a special bonus in combat, marked by a (+X)." << endl;

                cout << "Choose one of the following:" << endl;
                cout << " 1. Stone Club [2 Gold]" << endl;
                cout << " 2. Iron Spear [2 Gold]" << endl;
                cout << " 3. (+1) Mythril Rapier [5 Gold]" << endl;
                cout << " 4. (+2) Flaming Battle-Axe [15 Gold]" << endl;
                cout << " 5. (+3) Vorpal Longsword [50 Gold]" << endl;
                cout << " 6. Cancel" << endl;
                cin >> weaponChoice;

                while(weaponChoice < 1 || weaponChoice > 6){
                    cout << "That's not an option. Choose a number between 1-6" << endl;
                    cin >> weaponChoice;
                }

                if(weaponChoice != 6){
                    cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                    cin >> weaponAmount;

                    while(weaponAmount < 0){
                        cout << "That's not a valid amount. Enter a positive integer, or 0 to cancel." << endl;
                        cin >> weaponAmount;
                    }
                }

                if(weaponAmount == 0){
                    cout << "That's fine. What else can I do for you?" << endl;
                }

                else{
                    remainingAmount = weaponAmount;                    
                    if(weaponChoice == 1){
                        if(party.getGold() - clubPrice*weaponAmount >= 0){
                            cout << "You want to buy " << weaponAmount << " Stone Club(s) for " << clubPrice*weaponAmount << " gold? (y/n)" << endl;
                            cin >> confirmation;

                            while(confirmation != 'y' && confirmation != 'Y' && confirmation != 'n' && confirmation != 'N'){
                                cout << "I didn't understand. Do you want to buy " << weaponAmount << " Stone Club(s) for " << clubPrice*weaponAmount << " gold? (y/n)" << endl;
                                cin >> confirmation;
                            }

                            if(confirmation == 'y' || confirmation == 'Y'){                            
                                while(remainingAmount > 0){
                                    bool validBuy = false;

                                    if(player.getHasWeapon() == false){
                                        player.setHasWeapon(true);
                                        player.setWeapon("Stone Club");
                                        validBuy = true;
                                    }

                                    else{
                                        for(int i = 0; i < 4; i++){
                                            if(teammates[i].getHasWeapon() == false){
                                                teammates[i].setHasWeapon(true);
                                                teammates[i].setWeapon("Stone Club");
                                                validBuy = true;
                                                break;                                                                                                
                                            }
                                        }
                                    }

                                    if(validBuy == true){
                                        updateGold = party.getGold() - clubPrice;
                                        party.setGold(updateGold);

                                        remainingAmount -= 1;

                                        updateWeapons = weapons.getClubs() + 1;
                                        weapons.setClubs(updateWeapons);
                                        party.setNumWeapons(party.getNumWeapons() + 1);

                                        cout << "Thank you for your patronage! What else can I get for you?" << endl;
                                        printInventory(party, weapons, treasures, cookware);                                     
                                    }

                                    else{
                                        char subConfirmation;
                                        int subChoice;

                                        cout << "Every player on the party already has a weapon. Would you like to substitute one of your weapons for a Stone Club? (y/n)" << endl;
                                        cin >> subConfirmation;

                                        while(subConfirmation != 'y' && subConfirmation != 'Y' && subConfirmation != 'n' && subConfirmation != 'N'){
                                            cout << "I didn't understand. Do you want to substitute one of your weapons for a Stone Club? (y/n)" << endl;
                                            cin >> subConfirmation;
                                        }

                                        if(subConfirmation == 'y' || subConfirmation == 'Y'){
                                            cout << "Which weapon would you like to remove? Choose a number from 1-5, or 0 to cancel." << endl;
                                            cout << "1. " << player.getName() << ": " << player.getWeapon() << endl;
                                            cout << "2. " << teammates[0].getName() << ": " << teammates[0].getWeapon() << endl;
                                            cout << "3. " << teammates[1].getName() << ": " << teammates[1].getWeapon() << endl;
                                            cout << "4. " << teammates[2].getName() << ": " << teammates[2].getWeapon() << endl;
                                            cout << "5. " << teammates[3].getName() << ": " << teammates[3].getWeapon() << endl;
                                            cin >> subChoice;

                                            while(subChoice < 0 || subChoice > 5){
                                                cout << "That's not a valid choice. Choose a number from 1-5." << endl;
                                                cin >> subChoice;
                                            }

                                            if(subChoice == 0){
                                                cout << "That's fine. What else can I do for you?" << endl;
                                                break;
                                            }

                                            else{
                                                switch(subChoice){
                                                    case 1:
                                                        if(player.getWeapon() == "Stone Club"){
                                                            weapons.setClubs(weapons.getClubs() - 1);
                                                        }

                                                        else if(player.getWeapon() == "Iron Spear"){
                                                            weapons.setSpears(weapons.getSpears() - 1);
                                                        }

                                                        else if(player.getWeapon() == "(+1) Mythril Rapier"){
                                                            weapons.setRapiers(weapons.getRapiers() - 1);
                                                        }

                                                        else if(player.getWeapon() == "(+2) Flaming Battle-Axe"){
                                                            weapons.setAxes(weapons.getAxes() - 1);
                                                        }

                                                        else if(player.getWeapon() == "(+3) Vorpal Longsword"){
                                                            weapons.setSwords(weapons.getSwords() - 1);
                                                        }

                                                        player.setWeapon("Stone Club");
                                                        
                                                        weapons.setClubs(weapons.getClubs() + 1);
                                                        party.setGold(party.getGold() - clubPrice);
                                                        remainingAmount -= 1;
                                                        break;

                                                    case 2:
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

                                                        else if(teammates[0].getWeapon() == "(+3) Vorpal Longsword"){
                                                            weapons.setSwords(weapons.getSwords() - 1);
                                                        }

                                                        teammates[0].setWeapon("Stone Club");
                                                        party.setNumWeapons(party.getNumWeapons() + 1);
                                                        weapons.setClubs(weapons.getClubs() + 1);
                                                        party.setGold(party.getGold() - clubPrice);
                                                        remainingAmount -= 1;
                                                        break;

                                                    case 3:
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

                                                        else if(teammates[1].getWeapon() == "(+3) Vorpal Longsword"){
                                                            weapons.setSwords(weapons.getSwords() - 1);
                                                        }

                                                        teammates[1].setWeapon("Stone Club");
                                                        party.setNumWeapons(party.getNumWeapons() + 1);
                                                        weapons.setClubs(weapons.getClubs() + 1);
                                                        party.setGold(party.getGold() - clubPrice);
                                                        remainingAmount -= 1;
                                                        break;

                                                    case 4:
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

                                                        else if(teammates[2].getWeapon() == "(+3) Vorpal Longsword"){
                                                            weapons.setSwords(weapons.getSwords() - 1);
                                                        }

                                                        teammates[2].setWeapon("Stone Club");
                                                        party.setNumWeapons(party.getNumWeapons() + 1);
                                                        weapons.setClubs(weapons.getClubs() + 1);
                                                        party.setGold(party.getGold() - clubPrice);
                                                        remainingAmount -= 1;
                                                        break;

                                                    case 5:
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

                                                        else if(teammates[3].getWeapon() == "(+3) Vorpal Longsword"){
                                                            weapons.setSwords(weapons.getSwords() - 1);
                                                        }
                                                        
                                                        teammates[3].setWeapon("Stone Club");
                                                        party.setNumWeapons(party.getNumWeapons() + 1);
                                                        weapons.setClubs(weapons.getClubs() + 1);
                                                        party.setGold(party.getGold() - clubPrice);
                                                        remainingAmount -= 1;
                                                        break;

                                                    default:
                                                        cout << "That's fine. What else can I do for you?" << endl;
                                                        break;
                                                }
                                                cout << "Thank you for your patronage! What else can I get for you?" << endl;
                                                printInventory(party, weapons, treasures, cookware);                                                
                                            }
                                        }

                                        else{
                                            cout << "That's fine. What else can I do for you?" << endl;
                                            break;
                                        }
                                    }
                                }                                
                            }

                            else{
                                cout << "That's fine. What else can I do for you?" << endl;
                            }                        
                        }

                        else{
                            cout << "You don't have enough gold to buy that." << endl;
                        }
                    }

                    else if(weaponChoice == 2){
                        if(party.getGold() - spearPrice*weaponAmount >= 0){
                            cout << "You want to buy " << weaponAmount << " Iron Spear(s) for " << spearPrice*weaponAmount << " gold? (y/n)" << endl;
                            cin >> confirmation;

                            while(confirmation != 'n' && confirmation != 'N' && confirmation != 'y' && confirmation != 'Y'){
                                cout << "I didn't understand. Do you want to buy " << weaponAmount << " Iron Spear(s) for " << spearPrice*weaponAmount << " gold? (y/n)" << endl;
                                cin >> confirmation;
                            }   

                            if(confirmation == 'y' || confirmation == 'Y'){
                                while(remainingAmount > 0){
                                    bool validBuy = false;

                                    if(player.getHasWeapon() == false){
                                        player.setHasWeapon(true);
                                        player.setWeapon("Iron Spear");
                                        validBuy = true;
                                    }

                                    else{
                                        for(int i = 0; i < 4; i++){
                                            if(teammates[i].getHasWeapon() == false){
                                                teammates[i].setHasWeapon(true);
                                                teammates[i].setWeapon("Iron Spear");
                                                validBuy = true;
                                                break;                                                                                                
                                            }
                                        }
                                    }

                                    if(validBuy == true){
                                        updateGold = party.getGold() - spearPrice;
                                        party.setGold(updateGold);

                                        remainingAmount -= 1;

                                        updateWeapons = weapons.getSpears() + 1;
                                        weapons.setSpears(updateWeapons);
                                        party.setNumWeapons(party.getNumWeapons() + 1);

                                        cout << "Thank you for your patronage! What else can I do for you?" << endl;
                                        printInventory(party, weapons, treasures, cookware);                                     
                                    }

                                    else{
                                        char subConfirmation;
                                        int subChoice;

                                        cout << "Every player on the party already has a weapon. Would you like to substitute one of your weapons for an Iron Spear? (y/n)" << endl;
                                        cin >> subConfirmation;

                                        while(subConfirmation != 'y' && subConfirmation != 'Y' && subConfirmation != 'n' && subConfirmation != 'N'){
                                            cout << "I didn't understand. Do you want to substitute one of your weapons for an Iron Spear? (y/n)" << endl;
                                            cin >> subConfirmation;
                                        }

                                        if(subConfirmation == 'y' || subConfirmation == 'Y'){
                                            cout << "Which weapon would you like to remove? Choose a number from 1-5, or 0 to cancel." << endl;
                                            cout << "1. " << player.getName() << ": " << player.getWeapon() << endl;
                                            cout << "2. " << teammates[0].getName() << ": " << teammates[0].getWeapon() << endl;
                                            cout << "3. " << teammates[1].getName() << ": " << teammates[1].getWeapon() << endl;
                                            cout << "4. " << teammates[2].getName() << ": " << teammates[2].getWeapon() << endl;
                                            cout << "5. " << teammates[3].getName() << ": " << teammates[3].getWeapon() << endl;
                                            cin >> subChoice;

                                            while(subChoice < 0 || subChoice > 5){
                                                cout << "That's not a valid choice. Choose a number from 1-5, or 0 to cancel." << endl;
                                                cin >> subChoice;
                                            }

                                            if(subChoice == 0){
                                                cout << "That's fine. What else can I do for you?" << endl;
                                                break;
                                            }

                                            else{
                                                switch(subChoice){
                                                    case 1:
                                                        if(player.getWeapon() == "Stone Club"){
                                                            weapons.setClubs(weapons.getClubs() - 1);
                                                        }

                                                        else if(player.getWeapon() == "Iron Spear"){
                                                            weapons.setSpears(weapons.getSpears() - 1);
                                                        }

                                                        else if(player.getWeapon() == "(+1) Mythril Rapier"){
                                                            weapons.setRapiers(weapons.getRapiers() - 1);
                                                        }

                                                        else if(player.getWeapon() == "(+2) Flaming Battle-Axe"){
                                                            weapons.setAxes(weapons.getAxes() - 1);
                                                        }

                                                        else if(player.getWeapon() == "(+3) Vorpal Longsword"){
                                                            weapons.setSwords(weapons.getSwords() - 1);
                                                        }

                                                        player.setWeapon("Iron Spear");
                                                        
                                                        weapons.setSpears(weapons.getSpears() + 1);
                                                        party.setGold(party.getGold() - spearPrice);
                                                        remainingAmount -= 1;
                                                        break;

                                                    case 2:
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

                                                        else if(teammates[0].getWeapon() == "(+3) Vorpal Longsword"){
                                                            weapons.setSwords(weapons.getSwords() - 1);
                                                        }

                                                        teammates[0].setWeapon("Iron Spear");
                                                        party.setNumWeapons(party.getNumWeapons() + 1);
                                                        weapons.setSpears(weapons.getSpears() + 1);
                                                        party.setGold(party.getGold() - spearPrice);
                                                        remainingAmount -= 1;
                                                        break;

                                                    case 3:
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

                                                        else if(teammates[1].getWeapon() == "(+3) Vorpal Longsword"){
                                                            weapons.setSwords(weapons.getSwords() - 1);
                                                        }

                                                        teammates[1].setWeapon("Iron Spear");
                                                        party.setNumWeapons(party.getNumWeapons() + 1);
                                                        weapons.setSpears(weapons.getSpears() + 1);
                                                        party.setGold(party.getGold() - spearPrice);
                                                        remainingAmount -= 1;
                                                        break;

                                                    case 4:
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

                                                        else if(teammates[2].getWeapon() == "(+3) Vorpal Longsword"){
                                                            weapons.setSwords(weapons.getSwords() - 1);
                                                        }

                                                        teammates[2].setWeapon("Iron Spear");
                                                        party.setNumWeapons(party.getNumWeapons() + 1);
                                                        weapons.setSpears(weapons.getSpears() + 1);
                                                        party.setGold(party.getGold() - spearPrice);
                                                        remainingAmount -= 1;
                                                        break;

                                                    case 5:
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

                                                        else if(teammates[3].getWeapon() == "(+3) Vorpal Longsword"){
                                                            weapons.setSwords(weapons.getSwords() - 1);
                                                        }
                                                        
                                                        teammates[3].setWeapon("Iron Spear");
                                                        party.setNumWeapons(party.getNumWeapons() + 1);
                                                        weapons.setSpears(weapons.getSpears() + 1);
                                                        party.setGold(party.getGold() - spearPrice);
                                                        remainingAmount -= 1;
                                                        break;

                                                    default:
                                                        cout << "That's fine. What else can I do for you?" << endl;
                                                        break;
                                                }
                                                cout << "Thank you for your patronage! What else can I get for you?" << endl;
                                                printInventory(party, weapons, treasures, cookware);                                                
                                            }
                                        }

                                        else{
                                            cout << "That's fine. What else can I do for you?" << endl;
                                            break;
                                        }
                                    }
                                }                                
                            }

                            else{
                                cout << "That's fine. What else can I do for you?" << endl;
                            }
                        }

                        else{
                            cout << "You don't have enough gold to buy that." << endl;
                        }
                    }

                    else if(weaponChoice == 3){                    
                        if(party.getGold() - rapierPrice*weaponAmount >= 0){
                            cout << "You want to buy " << weaponAmount << " (+1) Mythril Rapier(s) for " << rapierPrice*weaponAmount << " gold? (y/n)" << endl;
                            cin >> confirmation;

                            while(confirmation != 'n' && confirmation != 'N' && confirmation != 'y' && confirmation != 'Y'){
                                cout << "I didn't understand. Do you want to buy " << weaponAmount << " (+1) Mythril Rapier(s) for " << rapierPrice*weaponAmount << " gold? (y/n)" << endl;
                                cin >> confirmation;
                            }   

                            if(confirmation == 'y' || confirmation == 'Y'){
                                while(remainingAmount > 0){
                                    bool validBuy = false;

                                    if(player.getHasWeapon() == false){
                                        player.setHasWeapon(true);
                                        player.setWeapon("(+1) Mythril Rapier");
                                        validBuy = true;
                                    }

                                    else{
                                        for(int i = 0; i < 4; i++){
                                            if(teammates[i].getHasWeapon() == false){
                                                teammates[i].setHasWeapon(true);
                                                teammates[i].setWeapon("(+1) Mythril Rapier");
                                                validBuy = true;
                                                break;                                                                                                
                                            }
                                        }
                                    }

                                    if(validBuy == true){
                                        updateGold = party.getGold() - rapierPrice;
                                        party.setGold(updateGold);

                                        remainingAmount -= 1;

                                        updateWeapons = weapons.getRapiers() + 1;
                                        weapons.setRapiers(updateWeapons);
                                        party.setNumWeapons(party.getNumWeapons() + 1);

                                        cout << "Thank you for your patronage! What else can I do for you?" << endl;
                                        printInventory(party, weapons, treasures, cookware);                                     
                                    }

                                    else{
                                        char subConfirmation;
                                        int subChoice;

                                        cout << "Every player on the party already has a weapon. Would you like to substitute one of your weapons for a (+1) Mythril Rapier? (y/n)" << endl;
                                        cin >> subConfirmation;

                                        while(subConfirmation != 'y' && subConfirmation != 'Y' && subConfirmation != 'n' && subConfirmation != 'N'){
                                            cout << "I didn't understand. Do you want to substitute one of your weapons for a (+1) Mythril Rapier? (y/n)" << endl;
                                            cin >> subConfirmation;
                                        }

                                        if(subConfirmation == 'y' || subConfirmation == 'Y'){
                                            cout << "Which weapon would you like to remove? Choose a number from 1-5, or 0 to cancel." << endl;
                                            cout << "1. " << player.getName() << ": " << player.getWeapon() << endl;
                                            cout << "2. " << teammates[0].getName() << ": " << teammates[0].getWeapon() << endl;
                                            cout << "3. " << teammates[1].getName() << ": " << teammates[1].getWeapon() << endl;
                                            cout << "4. " << teammates[2].getName() << ": " << teammates[2].getWeapon() << endl;
                                            cout << "5. " << teammates[3].getName() << ": " << teammates[3].getWeapon() << endl;
                                            cin >> subChoice;

                                            while(subChoice < 0 || subChoice > 5){
                                                cout << "That's not a valid choice. Choose a number from 1-5, or 0 to cancel." << endl;
                                                cin >> subChoice;
                                            }

                                            if(subChoice == 0){
                                                cout << "That's fine. What else can I do for you?" << endl;
                                                break;
                                            }

                                            else{
                                                switch(subChoice){
                                                    case 1:
                                                        if(player.getWeapon() == "Stone Club"){
                                                            weapons.setClubs(weapons.getClubs() - 1);
                                                        }

                                                        else if(player.getWeapon() == "Iron Spear"){
                                                            weapons.setSpears(weapons.getSpears() - 1);
                                                        }

                                                        else if(player.getWeapon() == "(+1) Mythril Rapier"){
                                                            weapons.setRapiers(weapons.getRapiers() - 1);
                                                        }

                                                        else if(player.getWeapon() == "(+2) Flaming Battle-Axe"){
                                                            weapons.setAxes(weapons.getAxes() - 1);
                                                        }

                                                        else if(player.getWeapon() == "(+3) Vorpal Longsword"){
                                                            weapons.setSwords(weapons.getSwords() - 1);
                                                        }

                                                        player.setWeapon("(+1) Mythril Rapier");
                                                        
                                                        weapons.setRapiers(weapons.getRapiers() + 1);
                                                        party.setGold(party.getGold() - rapierPrice);
                                                        remainingAmount -= 1;
                                                        break;

                                                    case 2:
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

                                                        else if(teammates[0].getWeapon() == "(+3) Vorpal Longsword"){
                                                            weapons.setSwords(weapons.getSwords() - 1);
                                                        }

                                                        teammates[0].setWeapon("(+1) Mythril Rapier");
                                                        party.setNumWeapons(party.getNumWeapons() + 1);
                                                        weapons.setRapiers(weapons.getRapiers() + 1);
                                                        party.setGold(party.getGold() - rapierPrice);
                                                        remainingAmount -= 1;
                                                        break;

                                                    case 3:
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

                                                        else if(teammates[1].getWeapon() == "(+3) Vorpal Longsword"){
                                                            weapons.setSwords(weapons.getSwords() - 1);
                                                        }

                                                        teammates[1].setWeapon("(+1) Mythril Rapier");
                                                        party.setNumWeapons(party.getNumWeapons() + 1);
                                                        weapons.setRapiers(weapons.getRapiers() + 1);
                                                        party.setGold(party.getGold() - rapierPrice);
                                                        remainingAmount -= 1;
                                                        break;

                                                    case 4:
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

                                                        else if(teammates[2].getWeapon() == "(+3) Vorpal Longsword"){
                                                            weapons.setSwords(weapons.getSwords() - 1);
                                                        }

                                                        teammates[2].setWeapon("(+1) Mythril Rapier");
                                                        party.setNumWeapons(party.getNumWeapons() + 1);
                                                        weapons.setRapiers(weapons.getRapiers() + 1);
                                                        party.setGold(party.getGold() - rapierPrice);
                                                        remainingAmount -= 1;
                                                        break;

                                                    case 5:
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

                                                        else if(teammates[3].getWeapon() == "(+3) Vorpal Longsword"){
                                                            weapons.setSwords(weapons.getSwords() - 1);
                                                        }
                                                        
                                                        teammates[3].setWeapon("(+1) Mythril Rapier");
                                                        party.setNumWeapons(party.getNumWeapons() + 1);
                                                        weapons.setRapiers(weapons.getRapiers() + 1);
                                                        party.setGold(party.getGold() - rapierPrice);
                                                        remainingAmount -= 1;
                                                        break;                                                    
                                                }
                                                cout << "Thank you for your patronage! What else can I get for you?" << endl;
                                                printInventory(party, weapons, treasures, cookware);                                                
                                            }                                            
                                        }

                                        else{
                                            cout << "That's fine. What else can I do for you?" << endl;
                                            break;
                                        }
                                    }
                                }                                
                            }

                            else{
                                cout << "That's fine. What else can I do for you?" << endl;
                            }
                        }

                        else{
                            cout << "You don't have enough gold to buy that." << endl;
                        }
                    }
                    
                    else if(weaponChoice == 4){                    
                        if(party.getGold() - axePrice*weaponAmount >= 0){
                            cout << "You want to buy " << weaponAmount << "  (+2) Flaming Battle-Axe(s) for " << axePrice*weaponAmount << " gold? (y/n)" << endl;
                            cin >> confirmation;

                            while(confirmation != 'n' && confirmation != 'N' && confirmation != 'y' && confirmation != 'Y'){
                                cout << "I didn't understand. Do you want to buy " << weaponAmount << "  (+2) Flaming Battle-Axe(s) for " << axePrice*weaponAmount << " gold? (y/n)" << endl;
                                cin >> confirmation;
                            }

                            if(confirmation == 'y' || confirmation == 'Y'){
                                while(remainingAmount > 0){
                                    bool validBuy = false;

                                    if(player.getHasWeapon() == false){
                                        player.setHasWeapon(true);
                                        player.setWeapon("(+2) Flaming Battle-Axe");
                                        validBuy = true;
                                    }

                                    else{
                                        for(int i = 0; i < 4; i++){
                                            if(teammates[i].getHasWeapon() == false){
                                                teammates[i].setHasWeapon(true);
                                                teammates[i].setWeapon("(+2) Flaming Battle-Axe");
                                                validBuy = true;
                                                break;                                                                                                
                                            }
                                        }
                                    }

                                    if(validBuy == true){
                                        updateGold = party.getGold() - axePrice;
                                        party.setGold(updateGold);

                                        remainingAmount -= 1;

                                        updateWeapons = weapons.getAxes() + 1;
                                        weapons.setAxes(updateWeapons);
                                        party.setNumWeapons(party.getNumWeapons() + 1);

                                        cout << "Thank you for your patronage! What else can I get for you?" << endl;
                                        printInventory(party, weapons, treasures, cookware);                                     
                                    }

                                    else{
                                        char subConfirmation;
                                        int subChoice;

                                        cout << "Every player on the party already has a weapon. Would you like to substitute one of your weapons for a (+2) Flaming Battle-Axe? (y/n)" << endl;
                                        cin >> subConfirmation;

                                        while(subConfirmation != 'y' && subConfirmation != 'Y' && subConfirmation != 'n' && subConfirmation != 'N'){
                                            cout << "I didn't understand. Do you want to substitute one of your weapons for a (+2) Flaming Battle-Axe? (y/n)" << endl;
                                            cin >> subConfirmation;
                                        }

                                        if(subConfirmation == 'y' || subConfirmation == 'Y'){
                                            cout << "Which weapon would you like to remove? Choose a number from 1-5, or 0 to cancel." << endl;
                                            cout << "1. " << player.getName() << ": " << player.getWeapon() << endl;
                                            cout << "2. " << teammates[0].getName() << ": " << teammates[0].getWeapon() << endl;
                                            cout << "3. " << teammates[1].getName() << ": " << teammates[1].getWeapon() << endl;
                                            cout << "4. " << teammates[2].getName() << ": " << teammates[2].getWeapon() << endl;
                                            cout << "5. " << teammates[3].getName() << ": " << teammates[3].getWeapon() << endl;
                                            cin >> subChoice;

                                            while(subChoice < 0 || subChoice > 5){
                                                cout << "That's not a valid choice. Choose a number from 1-5, or 0 to cancel." << endl;
                                                cin >> subChoice;
                                            }

                                            if(subChoice == 0){
                                                cout << "That's fine. What else can I do for you?" << endl;
                                                break;
                                            }

                                            else{
                                                switch(subChoice){
                                                    case 1:
                                                        if(player.getWeapon() == "Stone Club"){
                                                            weapons.setClubs(weapons.getClubs() - 1);
                                                        }

                                                        else if(player.getWeapon() == "Iron Spear"){
                                                            weapons.setSpears(weapons.getSpears() - 1);
                                                        }

                                                        else if(player.getWeapon() == "(+1) Mythril Rapier"){
                                                            weapons.setRapiers(weapons.getRapiers() - 1);
                                                        }

                                                        else if(player.getWeapon() == "(+2) Flaming Battle-Axe"){
                                                            weapons.setAxes(weapons.getAxes() - 1);
                                                        }

                                                        else if(player.getWeapon() == "(+3) Vorpal Longsword"){
                                                            weapons.setSwords(weapons.getSwords() - 1);
                                                        }

                                                        player.setWeapon("(+2) Flaming Battle-Axe");
                                                        
                                                        weapons.setAxes(weapons.getAxes() + 1);
                                                        party.setGold(party.getGold() - axePrice);
                                                        remainingAmount -= 1;
                                                        break;

                                                    case 2:
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

                                                        else if(teammates[0].getWeapon() == "(+3) Vorpal Longsword"){
                                                            weapons.setSwords(weapons.getSwords() - 1);
                                                        }

                                                        teammates[0].setWeapon("(+2) Flaming Battle-Axe");
                                                        party.setNumWeapons(party.getNumWeapons() + 1);
                                                        weapons.setAxes(weapons.getAxes() + 1);
                                                        party.setGold(party.getGold() - axePrice);
                                                        remainingAmount -= 1;
                                                        break;

                                                    case 3:
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

                                                        else if(teammates[1].getWeapon() == "(+3) Vorpal Longsword"){
                                                            weapons.setSwords(weapons.getSwords() - 1);
                                                        }

                                                        teammates[1].setWeapon("(+2) Flaming Battle-Axe");
                                                        party.setNumWeapons(party.getNumWeapons() + 1);
                                                        weapons.setAxes(weapons.getAxes() + 1);
                                                        party.setGold(party.getGold() - axePrice);
                                                        remainingAmount -= 1;
                                                        break;

                                                    case 4:
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

                                                        else if(teammates[2].getWeapon() == "(+3) Vorpal Longsword"){
                                                            weapons.setSwords(weapons.getSwords() - 1);
                                                        }

                                                        teammates[2].setWeapon("(+2) Flaming Battle-Axe");
                                                        party.setNumWeapons(party.getNumWeapons() + 1);
                                                        weapons.setAxes(weapons.getAxes() + 1);
                                                        party.setGold(party.getGold() - axePrice);
                                                        remainingAmount -= 1;
                                                        break;

                                                    case 5:
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

                                                        else if(teammates[3].getWeapon() == "(+3) Vorpal Longsword"){
                                                            weapons.setSwords(weapons.getSwords() - 1);
                                                        }
                                                        
                                                        teammates[3].setWeapon("(+2) Flaming Battle-Axe");
                                                        party.setNumWeapons(party.getNumWeapons() + 1);
                                                        weapons.setAxes(weapons.getAxes() + 1);
                                                        party.setGold(party.getGold() - axePrice);
                                                        remainingAmount -= 1;
                                                        break;

                                                    default:
                                                        cout << "That's fine. What else can I do for you?" << endl;
                                                        break;
                                                }
                                                cout << "Thank you for your patronage! What else can I get for you?" << endl;
                                                printInventory(party, weapons, treasures, cookware);                                                
                                            }
                                        }

                                        else{
                                            cout << "That's fine. What else can I do for you?" << endl;
                                            break;
                                        }
                                    }
                                }                                
                            }

                            else{
                                cout << "That's fine. What else can I do for you?" << endl;
                            }
                        }

                        else{
                            cout << "You don't have enough gold to buy that." << endl;
                        }
                    }

                    else if(weaponChoice == 5){                    
                        if(party.getGold() - swordPrice*weaponAmount >= 0){
                            cout << "You want to buy " << weaponAmount << "  (+3) Vorpal Longsword(s) for " << swordPrice*weaponAmount << " gold? (y/n)" << endl;
                            cin >> confirmation;

                            while(confirmation != 'n' && confirmation != 'N' && confirmation != 'y' && confirmation != 'Y'){
                                cout << "I didn't understand. Do you want to buy " << weaponAmount << "(+3) Vorpal Longsword(s) for " << swordPrice*weaponAmount << " gold? (y/n)" << endl;
                                cin >> confirmation;
                            }

                            if(confirmation == 'y' || confirmation == 'Y'){
                                while(remainingAmount > 0){
                                    bool validBuy = false;

                                    if(player.getHasWeapon() == false){
                                        player.setHasWeapon(true);
                                        player.setWeapon("(+3) Vorpal Longsword");
                                        validBuy = true;
                                    }

                                    else{
                                        for(int i = 0; i < 4; i++){
                                            if(teammates[i].getHasWeapon() == false){
                                                teammates[i].setHasWeapon(true);
                                                teammates[i].setWeapon("(+3) Vorpal Longsword");
                                                validBuy = true;
                                                break;                                                                                                
                                            }
                                        }
                                    }

                                    if(validBuy == true){
                                        updateGold = party.getGold() - swordPrice;
                                        party.setGold(updateGold);

                                        remainingAmount -= 1;

                                        updateWeapons = weapons.getSwords() + 1;
                                        weapons.setSwords(updateWeapons);
                                        party.setNumWeapons(party.getNumWeapons() + 1);

                                        cout << "Thank you for your patronage! What else can I get for you?" << endl;
                                        printInventory(party, weapons, treasures, cookware);                                     
                                    }

                                    else{
                                        char subConfirmation;
                                        int subChoice;

                                        cout << "Every player on the party already has a weapon. Would you like to substitute one of your weapons for a (+3) Vorpal Longsword? (y/n)" << endl;
                                        cin >> subConfirmation;

                                        while(subConfirmation != 'y' && subConfirmation != 'Y' && subConfirmation != 'n' && subConfirmation != 'N'){
                                            cout << "I didn't understand. Do you want to substitute one of your weapons for a (+3) Vorpal Longsword? (y/n)" << endl;
                                            cin >> subConfirmation;
                                        }

                                        if(subConfirmation == 'y' || subConfirmation == 'Y'){
                                            cout << "Which weapon would you like to remove? Choose a number from 1-5, or 0 to cancel." << endl;
                                            cout << "1. " << player.getName() << ": " << player.getWeapon() << endl;
                                            cout << "2. " << teammates[0].getName() << ": " << teammates[0].getWeapon() << endl;
                                            cout << "3. " << teammates[1].getName() << ": " << teammates[1].getWeapon() << endl;
                                            cout << "4. " << teammates[2].getName() << ": " << teammates[2].getWeapon() << endl;
                                            cout << "5. " << teammates[3].getName() << ": " << teammates[3].getWeapon() << endl;
                                            cin >> subChoice;

                                            while(subChoice < 0 || subChoice > 5){
                                                cout << "That's not a valid choice. Choose a number from 1-5, or 0 to cancel." << endl;
                                                cin >> subChoice;
                                            }

                                            if(subChoice == 0){
                                                cout << "That's fine. What else can I do for you?" << endl;
                                                break;
                                            }

                                            else{
                                                switch(subChoice){
                                                    case 1:
                                                        if(player.getWeapon() == "Stone Club"){
                                                            weapons.setClubs(weapons.getClubs() - 1);
                                                        }

                                                        else if(player.getWeapon() == "Iron Spear"){
                                                            weapons.setSpears(weapons.getSpears() - 1);
                                                        }

                                                        else if(player.getWeapon() == "(+1) Mythril Rapier"){
                                                            weapons.setRapiers(weapons.getRapiers() - 1);
                                                        }

                                                        else if(player.getWeapon() == "(+2) Flaming Battle-Axe"){
                                                            weapons.setAxes(weapons.getAxes() - 1);
                                                        }

                                                        else if(player.getWeapon() == "(+3) Vorpal Longsword"){
                                                            weapons.setSwords(weapons.getSwords() - 1);
                                                        }

                                                        player.setWeapon("(+3) Vorpal Longsword");
                                                        
                                                        weapons.setSwords(weapons.getSwords() + 1);
                                                        party.setGold(party.getGold() - swordPrice);
                                                        remainingAmount -= 1;
                                                        break;

                                                    case 2:
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

                                                        else if(teammates[0].getWeapon() == "(+3) Vorpal Longsword"){
                                                            weapons.setSwords(weapons.getSwords() - 1);
                                                        }

                                                        teammates[0].setWeapon("(+3) Vorpal Longsword");
                                                        party.setNumWeapons(party.getNumWeapons() + 1);
                                                        weapons.setSwords(weapons.getSwords() + 1);
                                                        party.setGold(party.getGold() - swordPrice);
                                                        remainingAmount -= 1;
                                                        break;

                                                    case 3:
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

                                                        else if(teammates[1].getWeapon() == "(+3) Vorpal Longsword"){
                                                            weapons.setSwords(weapons.getSwords() - 1);
                                                        }

                                                        teammates[1].setWeapon("(+3) Vorpal Longsword");
                                                        party.setNumWeapons(party.getNumWeapons() + 1);
                                                        weapons.setSwords(weapons.getSwords() + 1);
                                                        party.setGold(party.getGold() - swordPrice);
                                                        remainingAmount -= 1;
                                                        break;

                                                    case 4:
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

                                                        else if(teammates[2].getWeapon() == "(+3) Vorpal Longsword"){
                                                            weapons.setSwords(weapons.getSwords() - 1);
                                                        }

                                                        teammates[2].setWeapon("(+3) Vorpal Longsword");
                                                        party.setNumWeapons(party.getNumWeapons() + 1);
                                                        weapons.setSwords(weapons.getSwords() + 1);
                                                        party.setGold(party.getGold() - swordPrice);
                                                        remainingAmount -= 1;
                                                        break;

                                                    case 5:
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

                                                        else if(teammates[3].getWeapon() == "(+3) Vorpal Longsword"){
                                                            weapons.setSwords(weapons.getSwords() - 1);
                                                        }
                                                        
                                                        teammates[3].setWeapon("(+3) Vorpal Longsword");
                                                        party.setNumWeapons(party.getNumWeapons() + 1);
                                                        weapons.setSwords(weapons.getSwords() + 1);
                                                        party.setGold(party.getGold() - swordPrice);
                                                        remainingAmount -= 1;
                                                        break;

                                                    default:
                                                        cout << "That's fine. What else can I do for you?" << endl;
                                                        break;
                                                }
                                                cout << "Thank you for your patronage! What else can I get for you?" << endl;
                                                printInventory(party, weapons, treasures, cookware);                                                
                                            }
                                        }

                                        else{
                                            cout << "That's fine. What else can I do for you?" << endl;
                                            break;
                                        }
                                    }
                                }
                            }

                            else{
                                cout << "That's fine. What else can I do for you?" << endl;
                            }
                        }

                        else{
                            cout << "You don't have enough gold to buy that." << endl;
                        }
                    }

                    else{
                        cout << "That's fine. What else can I get for you?" << endl;
                    }
                }

                printMerchantChoices();
                menuChoice = checkChoice();
                break;
            }

            case 4:{
                int armorPrice = 5*(1 + 0.25*party.getNumRoomsCleared());
                int updateGold;
                int updateArmor;
                int armorAmount;
                char confirmation;

                cout << "How many suits of armor can I get you? [" << armorPrice << " gold each suit] (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> armorAmount;

                while(armorAmount < 0){
                    cout << "That's not a valid amount. Enter a positive integer, or 0 to cancel." << endl;
                    cin >> armorAmount;
                }

                if(armorAmount == 0){
                    cout << "That's fine. What else can I get for you?" << endl;
                }

                else{
                    if(party.getGold() - armorPrice*armorAmount >= 0){
                        cout << "You want to buy " << armorAmount << " suit(s) of armor for " << armorPrice*armorAmount << " gold? (y/n)" << endl;
                        cin >> confirmation;

                        while(confirmation != 'y' && confirmation != 'Y' && confirmation != 'n' && confirmation != 'N'){
                            cout << "I didn't understand. Do you want to buy " << armorAmount << "suit(s) of armor for " << armorPrice*armorAmount << " gold? (y/n)" << endl;
                            cin >> confirmation;
                        }

                        if(confirmation == 'y' || confirmation == 'Y'){
                            int remainingArmor = armorAmount;

                            while(remainingArmor > 0){
                                bool validBuy = false;

                                if(player.getArmor() == false){
                                    player.setArmor(true);
                                    validBuy = true;
                                }

                                else{
                                    for(int i = 0; i < 4; i++){
                                        if(teammates[i].getArmor() == false){
                                            teammates[i].setArmor(true);
                                            validBuy = true;
                                            break;                                                                                                
                                        }
                                    }
                                }

                                if(validBuy == true){                                        
                                    party.setGold(party.getGold() - armorPrice);

                                        remainingArmor -= 1;
                                    
                                    party.setArmor(party.getArmor() + 1);

                                    cout << "Thank you for your patronage! What else can I get for you?" << endl;
                                    printInventory(party, weapons, treasures, cookware);                                     
                                }

                                else{
                                    cout << "Every party member already has a suit of armor!" << endl;
                                    break;
                                }
                            }
                        }

                        else{
                            cout << "That's fine. What else can I get for your?" << endl;
                        }
                    }
                }
                
                printMerchantChoices();
                menuChoice = checkChoice();
                break;
            }

            case 5:{
                int updateGold;
                int treasureChoice;
                char confirmation;

                cout << "What would you like to sell? (Enter a number between 1-5, or 0 to cancel)" << endl;
                cout << "1) Silver Ring (R) - 10 gold pieces each" << endl;
                cout << "2) Ruby Necklace (N) - 20 gold pieces each" << endl;
                cout << "3) Emerald Bracelet (B) - 30 gold pieces each" << endl;
                cout << "4) Diamond Circlet (C) - 40 gold pieces each" << endl;
                cout << "5) Gem-encrusted Goblet (G) - 50 gold pieces each" << endl;
                cin >> treasureChoice;

                while(treasureChoice < 0 || treasureChoice > 5){
                    cout << "That's not an option. Enter a number between 1-5, or 0 to cancel" << endl;
                    cin >> treasureChoice;
                }
    
                if(treasureChoice == 1){
                    if(treasures.getRings() > 0){
                        cout << "You want to sell your Silver Ring for 10 Gold Pieces? (y/n)" << endl;
                        cin >> confirmation;

                        while(confirmation != 'y' && confirmation != 'Y' && confirmation != 'n' && confirmation != 'N'){
                            cout << "I didn't understand. Do you want to sell your Silver Ring for 10 Gold Pieces? (y/n)" << endl;
                            cin >> confirmation;
                        }

                        if(confirmation == 'y' || confirmation == 'Y'){
                            updateGold = party.getGold() + 10;
                            party.setGold(updateGold);

                            treasures.setRings(treasures.getRings() - 1);
                            printInventory(party, weapons, treasures, cookware);
                        }

                        else{
                            cout << "That's fine. What else can I do for you?" << endl;
                        }
                    }
                    
                    else{
                        cout << "You don't have any Silver Rings." << endl;
                    }
                }

                else if(treasureChoice == 2){
                    if(treasures.getNecklaces() > 0){
                        cout << "You want to sell your Ruby Necklace for 20 Gold Pieces? (y/n)" << endl;
                        cin >> confirmation;

                        while(confirmation != 'y' && confirmation != 'Y' && confirmation != 'n' && confirmation != 'N'){
                            cout << "I didn't understand. Do you want to sell your Ruby Necklace for 20 Gold Pieces? (y/n)" << endl;
                            cin >> confirmation;
                        }

                        if(confirmation == 'y' || confirmation == 'Y'){
                            updateGold = party.getGold() + 20;
                            party.setGold(updateGold);

                            treasures.setNecklaces(treasures.getNecklaces() - 1);
                            printInventory(party, weapons, treasures, cookware);
                        }

                        else{
                            cout << "That's fine. What else can I do for you?" << endl;
                        }
                    }

                    else{
                        cout << "You don't have any Ruby Necklaces." << endl;
                    }
                    
                }

                else if(treasureChoice == 3){
                    if(treasures.getBracelets() > 0){
                        cout << "You want to sell your Emerald Bracelet for 30 Gold Pieces? (y/n)" << endl;
                        cin >> confirmation;

                        while(confirmation != 'y' && confirmation != 'Y' && confirmation != 'n' && confirmation != 'N'){
                            cout << "I didn't understand. Do you want to sell your Emerald Bracelet for 30 Gold Pieces? (y/n)" << endl;
                            cin >> confirmation;
                        }

                        if(confirmation == 'y' || confirmation == 'Y'){
                            updateGold = party.getGold() + 30;
                            party.setGold(updateGold);

                            treasures.setBracelets(treasures.getBracelets() - 1);
                            printInventory(party, weapons, treasures, cookware);
                        }

                        else{
                            cout << "That's fine. What else can I do for you?" << endl;
                        }
                    }

                    else{
                        cout << "You don't have any Emerald Bracelets." << endl;
                    }
                }

                else if(treasureChoice == 4){
                    if(treasures.getCirclets() > 0){
                        cout << "You want to sell your Diamond Circlet for 40 Gold Pieces? (y/n)" << endl;
                        cin >> confirmation;

                        while(confirmation != 'y' && confirmation != 'Y' && confirmation != 'n' && confirmation != 'N'){
                            cout << "I didn't understand. Do you want to sell your Diamond Circlet for 40 Gold Pieces? (y/n)" << endl;
                            cin >> confirmation;
                        }

                        if(confirmation == 'y' || confirmation == 'Y'){
                            updateGold = party.getGold() + 40;
                            party.setGold(updateGold);

                            treasures.setCirclets(treasures.getCirclets() - 1);
                            printInventory(party, weapons, treasures, cookware);
                        }

                        else{
                            cout << "That's fine. What else can I do for you?" << endl;
                        }
                    }

                    else{
                        cout << "You don't have any Diamond Circlets." << endl;
                    }                    
                }
            
                else if(treasureChoice == 5){
                    if(treasures.getGoblets() > 0){
                        cout << "You want to sell your Gem-encrusted Goblet for 50 Gold Pieces? (y/n)" << endl;
                        cin >> confirmation;

                        while(confirmation != 'y' && confirmation != 'Y' && confirmation != 'n' && confirmation != 'N'){
                            cout << "I didn't understand. Do you want to sell your Gem-encrusted Goblet for 50 Gold Pieces? (y/n)" << endl;
                            cin >> confirmation;
                        }

                        if(confirmation == 'y' || confirmation == 'Y'){
                            updateGold = party.getGold() + 50;
                            party.setGold(updateGold);

                            treasures.setGoblets(treasures.getGoblets() - 1);
                            printInventory(party, weapons, treasures, cookware);
                        }

                        else{
                            cout << "That's fine. What else can I do for you?" << endl;
                        }
                    }

                    else{
                        cout << "You don't have any Gem-encrusted Goblets." << endl;
                    }
                }

                else{
                    cout << "That's fine. What else can I do for you?" << endl;
                }

                printMerchantChoices();
                menuChoice = checkChoice();
                break;
            }

            case 6:{
                cout << "Are you sure you're finished? You won't be able to buy anything else from me! (y/n)" << endl;
                cin >> exitConfirmation;
                
                while(exitConfirmation != 'n' && exitConfirmation != 'N' && exitConfirmation != 'y' && exitConfirmation != 'Y'){
                    cout << "I didn't understand. Are you sure you're finished? You won't be able to buy anything else from me! (y/n)" << endl;
                    cin >> exitConfirmation;
                }

                if(exitConfirmation == 'n' || exitConfirmation == 'N'){
                    cout << "What else can I do for you?" << endl;
                    printMerchantChoices();
                    menuChoice = checkChoice();
                }

                else{
                    cout << "Good luck out there!" << endl;
                }
                break;
            }

        }       
    }
}

void statusUpdate(Party &party, Weapons &weapons, Treasures &treasures, Cookware &cookware, Player &player, Player teammates[4], int &sorcererAnger){
    cout << endl;
    cout << "+----------------------------------------+" << endl;
    cout << "|                 STATUS                 |" << endl;
    cout << "+----------------------------------------+" << endl;
    cout << "| Rooms Cleared:                         |" << party.getNumRoomsCleared() << endl;
    cout << "| Keys:                                  |"  << party.getKeysFound() << endl;
    cout << "| Anger Level:                           |" << sorcererAnger << endl;
    cout << "+----------------------------------------+" << endl;
    cout << "|                 PARTY                  |" << endl;
    cout << "+----------------------------------------+" << endl;
    cout << "| " << player.getName() << ": "; for(int i = 0; i < 40 - player.getName().length() - 3; i++){cout << " ";} cout << "|" << endl;
    cout << "|      Fullness: " << player.getFullness() << "                      |" << endl;
    cout << "|      Weapon: " << player.getWeapon(); for(int i = 0; i < 40 - player.getWeapon().length() - 14; i++){cout << " ";} cout << "|" << endl;
    cout << "|      Armor: " << player.getArmor() << "                          |" << endl;
    cout << "+----------------------------------------+" << endl;
    
    cout << "| " << teammates[0].getName() << ": "; for(int i = 0; i < 40 - teammates[0].getName().length() - 3; i++){cout << " ";} cout << "|" << endl;
    cout << "|      Fullness: " << teammates[0].getFullness() << "                      |" << endl;
    cout << "|      Weapon: " << teammates[0].getWeapon(); for(int i = 0; i < 40 - teammates[0].getWeapon().length() - 14; i++){cout << " ";} cout << "|" << endl;
    cout << "|      Armor: " << teammates[0].getArmor() << "                          |" << endl;
    cout << "+----------------------------------------+" << endl;

    cout << "| " << teammates[1].getName() << ": "; for(int i = 0; i < 40 - teammates[1].getName().length() - 3; i++){cout << " ";} cout << "|" << endl;
    cout << "|      Fullness: " << teammates[1].getFullness() << "                      |" << endl;
    cout << "|      Weapon: " << teammates[1].getWeapon(); for(int i = 0; i < 40 - teammates[1].getWeapon().length() - 14; i++){cout << " ";} cout << "|" << endl;
    cout << "|      Armor: " << teammates[1].getArmor() << "                          |" << endl;
    cout << "+----------------------------------------+" << endl;

    cout << "| " << teammates[2].getName() << ": "; for(int i = 0; i < 40 - teammates[2].getName().length() - 3; i++){cout << " ";} cout << "|" << endl;
    cout << "|      Fullness: " << teammates[2].getFullness() << "                      |" << endl;
    cout << "|      Weapon: " << teammates[2].getWeapon(); for(int i = 0; i < 40 - teammates[2].getWeapon().length() - 14; i++){cout << " ";} cout << "|" << endl;
    cout << "|      Armor: " << teammates[2].getArmor() << "                          |" << endl;
    cout << "+----------------------------------------+" << endl;

    cout << "| " << teammates[3].getName() << ": "; for(int i = 0; i < 40 - teammates[3].getName().length() - 3; i++){cout << " ";} cout << "|" << endl;
    cout << "|      Fullness: " << teammates[3].getFullness() << "                      |" << endl;
    cout << "|      Weapon: " << teammates[3].getWeapon(); for(int i = 0; i < 40 - teammates[3].getWeapon().length() - 14; i++){cout << " ";} cout << "|" << endl;
    cout << "|      Armor: " << teammates[3].getArmor() << "                          |" << endl;
    cout << "+----------------------------------------+" << endl;

    printInventory(party, weapons, treasures, cookware);
}

bool NPCPuzzle(){
    int numRiddles;

    ifstream fin;
    fin.open("riddles.txt");

    vector<string> riddles;

    riddles.push_back("You measure my life in hours and I serve you by expiring. I’m quick when I’m thin and slow when I’m fat. The wind is my enemy. (single word, lowercase)~candle");
    riddles.push_back("I have cities, but no houses. I have mountains, but no trees. I have water, but no fish. What am I? (single word, lowercase)~map");
    riddles.push_back("What is seen in the middle of March and April that can’t be seen at the beginning or end of either month? (single word, lowercase)~r");
    riddles.push_back("What word in the English language does the following: the first two letters signify a male, the first three letters signify a female, the first four letters signify a great, while the entire word signifies a great woman. What is the word? (single word, lowercase)~heroine");
    riddles.push_back("What English word has three consecutive double letters? (single word, lowercase)~bookkeeper");
    riddles.push_back("What disappears as soon as you say its name? (single word, lowercase)~silence");
    riddles.push_back("I have keys, but no locks and space, and no rooms. You can enter, but you can’t go outside. What am I? (single word, lowercase)~keyboard");
    riddles.push_back("What gets wet while drying? (single word, lowercase)~towel");
    riddles.push_back("How many letters are in the alphabet? (integer)~11");
    riddles.push_back("What are the next three letters in this sequence: OTTFFSS? (no spaces, uppercase)~ENT");
    riddles.push_back("First you eat me, then you get eaten. What am I? (single word, lowercase)~fishhook");
    riddles.push_back("What comes once in a minute, twice in a moment, but never in a thousand years? (single word, lowercase)~m");
    riddles.push_back("Which word in the dictionary is always spelled incorrectly? (single word, lowercase)~incorrectly");
    riddles.push_back("What is able to go up a chimney when down but unable to go down a chimney when up? (single word, lowercase)~umbrella");
    riddles.push_back("What has a head and a tail, but no body or legs? (single word, lowercase)~coin");
    riddles.push_back("I am a solitary word, 5 letters long. Behead me once, I am the same. Behead me again, I am still the same. (single word, lowercase)~alone");
    riddles.push_back("You’ll often find us on a line. When we’re together, it’s a crime. What are we? (single word, lowercase)~crows");
    riddles.push_back("If I am holding a bee, what do I have in my eye? (single word, lowercase)~beauty");
    riddles.push_back("If there are five apples and you take away three, how many apples do you have? (integer)~3");
    riddles.push_back("I am lighter than air, but a hundred people cannot lift me. What am I? (single word, lowercase)~bubble");

    srand(time(NULL));

    int riddle = rand() % 20;

    char separator = '~';
    int size = 2;
    string arr[size];

    split(riddles[riddle], separator, arr, size);

    cout << arr[0] << endl;
    string riddleAnswer;
    cin >> riddleAnswer;

    if(riddleAnswer == arr[1]){
        return true;
    }

    else{
        return false;
    }
}

bool endGame(Party &party, Player &player, Player teammates[4], Cookware &cookware, Treasures &treasures, Map &map, int &sorcererAnger){
    bool endGame = false;
    bool win;
    
    if(party.getPartySize() <= 1){
        cout << "OH NO! All of your teammates have died! GAME OVER!" << endl;
        endGame = true;
        win = false;
    }

    else if(player.getIsAlive() == false){
        cout << "YOU DIE! GAME OVER!" << endl;
        endGame = true;
        win = false;
    }

    else if(party.getLastAction() == 'G'){
        cout << "GAME OVER!" << endl;
        endGame = true;
        win = false;
    }

    else if(sorcererAnger >= 100){
        cout << "The Sorcerer's Anger Level has reached 100! GAME OVER!" << endl;
        endGame = true;
        win = false;
    }

    else if(party.getNumRoomsCleared() >= 5 && map.isDungeonExit(map.getPlayerRow(), map.getPlayerCol()) == true){
        cout << "Congratulations! You have cleared all 5 rooms and made it out of the Dungeon alive! YOU WIN!" << endl;
        endGame = true;
        win = true;
    }

    if(endGame == true){
        cout << endl;
        cout << "+----------------------------------------+" << endl;
        cout << "|              FINAL STATS               |" << endl;
        cout << "+----------------------------------------+" << endl;
        cout << "|        Remaining Party Members         |" << endl;
        cout << "+----------------------------------------+" << endl;
        cout << "| " << player.getName(); for(int i = 0; i < 40 - player.getName().length() - 1; i++){cout << " ";} cout << "|" << endl;
        for(int i = 0; i < 4; i++){
            if(teammates[i].getIsAlive() == true){
                cout << "| " << teammates[i].getName(); for(int i = 0; i < 40 - player.getName().length() - 1; i++){cout << " ";} cout << "|" << endl;
            }
        }
        cout << "+----------------------------------------+" << endl;
        cout << "| Turns Elapsed:                         |" << party.getNumTurns() << endl;
        cout << "| Remaining gold:                        |" << party.getGold() << endl;
        cout << "| Treasures:                             |R: " << treasures.getRings() << " | N: " << treasures.getNecklaces() << " | B: " << treasures.getBracelets() << " | C: " << treasures.getCirclets() << " | G: " << treasures.getGoblets() << endl;
        cout << "| Spaces Explored:                       |" << party.getNumSpacesExplored() << endl;
        cout << "| Monster Defeated:                      |" << party.getMonstersDefeated() << endl;
        cout << "| Rooms cleared:                         |" << party.getNumRoomsCleared() << endl;
        cout << "+----------------------------------------+" << endl;
    
        ifstream fin;
        ofstream fout;
        int x = 1;

        fin.open("results.txt");
        vector<string> fileLines;

        while(!fin.eof()){
            string line;
            getline(fin, line);

            if((line[0] != '+' && line[0] != '|') && line.length() > 1){
                x++;
            }

            fileLines.push_back(line);
        }

        fin.close();

        fout.open("results.txt");

        for(int i = 0; i < fileLines.size(); i++){
            fout << fileLines[i] << endl;
        }

        fout << "Game " << x << " stats ("; if(win == true){fout << "VICTORY):" << endl;} else{fout << "DEFEAT):" << endl;}
        fout << "+----------------------------------------+" << endl;
        fout << "|              FINAL STATS               |" << endl;
        fout << "+----------------------------------------+" << endl;
        fout << "|        Remaining Party Members         |" << endl;
        fout << "+----------------------------------------+" << endl;
        fout << "| " << player.getName(); for(int i = 0; i < 40 - player.getName().length() - 1; i++){fout << " ";} fout << "|" << endl;
        for(int i = 0; i < 4; i++){
            if(teammates[i].getIsAlive() == true){
                fout << "| " << teammates[i].getName(); for(int y = 0; y < 40 - teammates[i].getName().length() - 1; y++){fout << " ";} fout << "|" << endl;
            }
        }
        fout << "+----------------------------------------+" << endl;
        fout << "| Turns Elapsed:                         |" << party.getNumTurns() << endl;
        fout << "| Remaining gold:                        |" << party.getGold() << endl;
        fout << "| Treasures:                             |R: " << treasures.getRings() << " | N: " << treasures.getNecklaces() << " | B: " << treasures.getBracelets() << " | C: " << treasures.getCirclets() << " | G: " << treasures.getGoblets() << endl;
        fout << "| Spaces Explored:                       |" << party.getNumSpacesExplored() << endl;
        fout << "| Monster Defeated:                      |" << party.getMonstersDefeated() << endl;
        fout << "| Rooms cleared:                         |" << party.getNumRoomsCleared() << endl;
        fout << "+----------------------------------------+" << endl;

        fout.close();
    }

    return endGame;
}

void rankGamesByTurns(string resultsFile){
    ifstream fin;

    fin.open(resultsFile);

    int x = 0;

    vector<string> fileLines;

    while(!fin.eof()){
        string line;
        getline(fin, line);

        if((line[0] != '+' && line[0] != '|') && line.length() > 1){
            x++;
        }

        fileLines.push_back(line);
    }

    string games[x][x];

    fin.close();

    int n = 0;
    string subLineTurns;
    string subLineName;
    string subLineRC;
    int roomsCleared;
    string playerName;
    string turnsInt;

    for(int i = 0; i < fileLines.size(); i++){
        if(fileLines[i].length() > 20){
            subLineName = fileLines[i].substr(9, 9);
            subLineTurns = fileLines[i].substr(2, 13);       
            subLineRC = fileLines[i].substr(2, 4);
        }

        if(subLineRC == "Room"){
            int lineLength = fileLines[i].length();

            roomsCleared = stoi(fileLines[i].substr(42, lineLength - 42));
        }
        
        if(subLineName == "Remaining"){
            playerName = fileLines[i + 2].substr(2, 30);
            
        }

        if(subLineTurns == "Turns Elapsed"){
            int lineLength = fileLines[i].length();

            turnsInt = fileLines[i].substr(42, lineLength - 42);            
    
            if(roomsCleared == 5){
                games[n][0] = playerName;
                games[n][1] = turnsInt;
                n++;
            }
        }
    }

        vector<string> rankGames;
        string temp;

        for(int i = 0; i < n; i++){
            string game = games[i][1] + "~" + games[i][0];

            rankGames.push_back(game);
        }

        for(int i = 0; i < n; i++){
            //char separator = "~";
            int size = 2;
            string arr[size];

            split(rankGames[i], '~', arr, size);

            int x = stoi(arr[0]);

		    for(int j = i + 1; j < n; j++){
                split(rankGames[j], '~', arr, size);
                int y = stoi(arr[0]);

			    if(x > y){
				    temp = rankGames[i];
				    rankGames[i] = rankGames[j];
				    rankGames[j] = temp;
			    }
		}
	}

        cout << "Best games in this session: " << endl;

        for(int i = 0; i < n; i++){
            int size = 2;
            string arr[size];

            split(rankGames[i], '~', arr, size);

            cout << "#" << i + 1 << " - " << arr[0] << " turns: " << arr[1] << endl;
        }
}

void dungeon(Party &party, Weapons &weapons, Treasures &treasures, Cookware &cookware, Player &player, Player teammates[4], Map &map, int &sorcererAnger){
    //Declare variables
    char location;
    int menuChoice;
    char movement;
    int randInt;

    statusUpdate(party, weapons, treasures, cookware, player, teammates, sorcererAnger);
    map.displayMap();
    if (!map.isNPCLocation(map.getPlayerRow(), map.getPlayerCol()) && !map.isRoomLocation(map.getPlayerRow(), map.getPlayerCol())){
        cout << "Select one:" << endl << "1. Move" << endl << "2. Investigate" << endl << "3. Pick a Fight" << endl << "4. Cook and Eat" << endl << "5. Give up" << endl;
        location = 'E';
    }
    else if (map.isNPCLocation(map.getPlayerRow(), map.getPlayerCol())){
        cout << "Select one:" << endl << "1. Move" << endl << "2. Speak to NPC" << endl << "3. Give up" << endl;
        location = 'N';
    }
    else if (map.isRoomLocation(map.getPlayerRow(), map.getPlayerCol())){
        cout << "Select one:" << endl << "1. Move" << endl << "2. Open the Door" << endl << "3. Give up" << endl;    
        location = 'R';    
    }
    cin >> menuChoice;

    switch (location){
        case 'E':{//Normal locations
            switch (menuChoice){
                case 1://Move
                    party.setLastAction('M');

                    cout << "Which direction would you like to move?(w,a,s,d)" << endl;
                    cin >> movement;
                    while (movement != 'w' && movement != 'a' && movement != 's' && movement != 'd'){
                        cout << "Please input a valid direction" << endl;
                        cin >> movement;
                    }
                    map.move(movement);
                    if (rand() % 5+1 == 1){
                        player.setFullness(player.getFullness()-1);
                    }
                    for (int i=0; i < 4; i++){
                        if (rand() % 5+1 == 1){
                            teammates[i].setFullness((teammates[i].getFullness()-1));
                        }
                    }
                    break;
                case 2://Investigate
                    party.setLastAction('I');

                    if (map.isExplored(map.getPlayerRow(), map.getPlayerCol())){
                        cout << "This location has already been explored. Please select a new action.";
                        break;
                    }
                    randInt = rand() % 10+1;
                    if (randInt == 1){
                        cout << "You found a key!" << endl;
                        party.setKeysFound(party.getKeysFound()+1);
                    }
                    if (randInt == 2 || randInt == 3){
                        cout << "You found a piece of treasure!" << endl;
                        if (party.getNumRoomsCleared() == 0){
                            treasures.setRings(treasures.getRings()+1);
                        }
                        else if (party.getNumRoomsCleared() == 1){
                            treasures.setNecklaces(treasures.getNecklaces()+1);
                        }
                        else if (party.getNumRoomsCleared() == 2){
                            treasures.setBracelets(treasures.getBracelets()+1);
                        }
                        else if (party.getNumRoomsCleared() == 3){
                            treasures.setCirclets(treasures.getCirclets()+1);
                        }
                        else if (party.getNumRoomsCleared() >= 4){
                            treasures.setGoblets(treasures.getGoblets()+1);
                        }
                    }
                    if (randInt == 4 || randInt == 5){
                        party.fight(false);
                    }

                case 3://Fight
                    party.setLastAction('F');

                    if (party.getNumWeapons() > 0){
                        int fightChoice=0;
                        cout << "Select one:" << endl << "1.Fight" << endl << "2.Surrender" << endl;
                        cin >> fightChoice;
                        while (fightChoice != 1 && fightChoice != 2){
                            cout << "Invalid choice, please enter a valid response." << endl;
                            cin >> fightChoice;
                        }
                        if (fightChoice == 1){
                            party.fight(false);
                        }
                        else if (fightChoice == 2){
                            randInt = rand() % 4;
                            cout << "Sadly " << teammates[randInt].getName() << " was slain in combat." << endl;
                            teammates[randInt] = teammates[party.getPartySize()-2];
                            party.setPartySize(party.getPartySize()-1);
                        }
                        break;
                    }
                case 4://Cook
                    party.setLastAction('C');
                    party.cook();
                    break;
                case 5://Give up
                    party.setLastAction('G');
                    break;
                default://Invalid input
                    cout << "Please input a valid choice." << endl;
                    break;
            }
            break;
        }
        case 'N':{//NPC locations
            switch (menuChoice){
                case 1://Move
                    party.setLastAction('M');

                    cout << "Which direction would you like to move?" << endl;
                    cin >> movement;
                    while (movement != 'w' && movement != 'a' && movement != 's' && movement != 'd'){
                        cout << "Please input a valid direction" << endl;
                        cin >> movement;
                    }
                    map.move(movement);
                    if (rand() % 5+1 == 1){
                        player.setFullness(player.getFullness()-1);
                    }
                    for (int i=0; i < 4; i++){
                        if (rand() % 5+1 == 1){
                            teammates[i].setFullness((teammates[i].getFullness()-1));
                        }
                    }
                    break;
                case 2://Speak to NPC
                    party.setLastAction('S');

                    if(NPCPuzzle() == true){
                        cout << "Do you wish to barter for goods? (y/n)" << endl;
                        char confirmation;
                        cin >> confirmation;

                        while(confirmation != 'y' && confirmation != 'n'){
                            cout << "Input your anser with 'y' or 'n'." << endl;
                            cin >> confirmation;
                        }
                        if(confirmation == 'y'){
                            merchantMenu(party, weapons, treasures, cookware, player, teammates);
                        }

                        else{
                            cout << "Good luck out there!" << endl;
                        }
                        
                    }

                    else{
                        party.fight(false);
                    }

                    map.removeNPC(map.getPlayerRow(), map.getPlayerCol());

                    break;
                case 3://Give up
                    party.setLastAction('G');
                    break;
                default://Invalid input
                    cout << "Please input a valid choice." << endl;
                    break;                
            }
            break;
        }
        case 'R':{//Room locations
            switch (menuChoice){
                case 1://Move
                    party.setLastAction('M');
                    cout << "Which direction would you like to move?" << endl;
                    cin >> movement;
                    while (movement != 'w' && movement != 'a' && movement != 's' && movement != 'd'){
                        cout << "Please input a valid direction" << endl;
                        cin >> movement;
                    }
                    map.move(movement);
                    if (rand() % 5+1 == 1){
                        player.setFullness(player.getFullness()-1);
                    }
                    for (int i=0; i < 4; i++){
                        if (rand() % 5+1 == 1){
                            teammates[i].setFullness((teammates[i].getFullness()-1));
                        }
                    }
                    break;
                case 2://Open Door
                    srand(time(NULL));
                    party.setLastAction('O');

                    if(party.getKeysFound() >= map.getRoomCount()){                        
                        if(party.fight(true) > 0){                            
                            if(rand() % 10 >= 4){
                                party.misfortune();
                            }
                            map.removeRoom(map.getPlayerRow(), map.getPlayerCol());
                            party.setNumRoomsCleared(party.getNumRoomsCleared() + 1);
                        }

                        else{
                            party.setKeysFound(party.getKeysFound() - 1);
                            if(rand() % 10 >= 6){
                                party.misfortune();
                            }
                        }
                    }

                    else{
                        if(NPCPuzzle() == true){
                            map.removeRoom(map.getPlayerRow(), map.getPlayerCol());
                            party.setNumRoomsCleared(party.getNumRoomsCleared() + 1);
                        }

                        else{
                            int randTeammate = rand() % 4;

                            switch(randTeammate){
                                case 0:
                                    teammates[0].setIsAlive(false);
                                    cout << "OH NO! " << teammates[0].getName() << " HAS DIED!" << endl;
                                    break;

                                case 1:
                                    teammates[1].setIsAlive(false);
                                    cout << "OH NO! " << teammates[1].getName() << " HAS DIED!" << endl;
                                    break;

                                case 2:
                                    teammates[2].setIsAlive(false);
                                    cout << "OH NO! " << teammates[2].getName() << " HAS DIED!" << endl;
                                    break;

                                case 3:
                                    teammates[3].setIsAlive(false);
                                    cout << "OH NO! " << teammates[3].getName() << " HAS DIED!" << endl;
                                    break;
                            }

                            party.setPartySize(party.getPartySize() - 1);                            
                        }
                    }        
                    break;
                case 3://Give up
                    party.setLastAction('G');
                    break;
                default://Invalid input
                    cout << "Please input a valid choice." << endl;
                break;
            }
            break;
        }
    }
    sorcererAnger++;

    if(endGame(party, player, teammates, cookware, treasures, map, sorcererAnger) == false){
        dungeon(party, weapons, treasures, cookware, player, teammates, map, sorcererAnger);
    }
}


int main(){
    Map map = Map();
    Player player = Player();
    Weapons weapons = Weapons();
    Treasures treasures = Treasures();
    Player teammates[4];

    for(int i = 0; i < 4; i++){
        teammates[i] = Player();
    }

    Cookware cookware = Cookware();
    string file_name = "monsters.txt";
    Party party = Party(player, teammates, cookware, weapons, treasures, file_name);

    int sorcererAnger = 0;
    
    cout << "Enter your name: " << endl;
    string playerName;
    cin >> playerName;

    while(playerName.length() >= 38){
        cout << "Name too long! (Maximum 37 carachters)" << endl;
        cin >> playerName;
    }

    player.setName(playerName);

    cout << "Who is your first teammate?" << endl;
    string teammate1Name;
    cin >> teammate1Name;

    while(teammate1Name.length() >= 38){
        cout << "Name too long! (Maximum 37 carachters)" << endl;
        cin >> teammate1Name;
    }

    teammates[0].setName(teammate1Name);

    cout << "Who is your second teammate?" << endl;
    string teammate2Name;
    cin >> teammate2Name;

    while(teammate2Name.length() >= 38){
        cout << "Name too long! (Maximum 37 carachters)" << endl;
        cin >> teammate2Name;
    }

    teammates[1].setName(teammate2Name);

    cout << "Who is your third teammate?" << endl;
    string teammate3Name;
    cin >> teammate3Name;

    while(teammate3Name.length() >= 38){
        cout << "Name too long! (Maximum 37 carachters)" << endl;
        cin >> teammate3Name;
    }

    teammates[2].setName(teammate3Name);

    cout << "Who is your fourth teammate?" << endl;
    string teammate4Name;
    cin >> teammate4Name;

    while(teammate4Name.length() >= 38){
        cout << "Name too long! (Maximum 37 carachters)" << endl;
        cin >> teammate4Name;
    }

    teammates[3].setName(teammate4Name);

    cout << endl << "Between the 5 of you, you have 100 gold pieces." << endl;
    cout << "You will need to spend the some of your money on the following items:" << endl;
    cout << "- INGREDIENTS. To make food, you have to cook raw ingredients." << endl;
    cout << "- COOKWARE. If you want to cook, you have to have cookware first." << endl;
    cout << "- WEAPONS. You'll want at least one weapon per party member to fend off monsters." << endl;
    cout << "- ARMOR. Armor increases the chances of surviving a monster attack." << endl << endl;
    cout << "You can spend all of your money here before you start your journey, or you can save some to spend on merchants along the way. But beware, some of the merchants in this dungeon are shady characters, and they won't always give you a fair price..." << endl;   
    cout << endl;    
    
    merchantMenu(party, weapons, treasures, cookware, player, teammates);
    dungeon(party, weapons, treasures, cookware, player, teammates, map, sorcererAnger);
}