// CSCI 1300 Fall 2022
// Author: Rodrigo Nicastro
// Recitation: 201 – Elise Tate
// Homework 7 - Problem #3

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int userInput = 2; //Declare an userInput so that the loop can begin;
    vector<int> cards;
    int counter = 0;

    while(userInput != 14){ //Ask the user for a new card until they input 14;
        cout << "Please enter a number:" << endl;
        cin >> userInput;

        while(userInput < 1 || userInput > 14){ //Makes sure the user inputs a number between 1 and 14;
            cout << "The number should be an integer between 1 and 14." << endl;
            cout << "Please enter a number:" << endl;
            cin >> userInput;
        }

        cards.push_back(userInput); //Adds the user's card to the end of the vector;

        if(userInput == 1){
            //Removes one card from the start of the vector and adds 1 to counter if there is only 1 element in the vector;
            if(cards.size() == 1){
                cards.erase(cards.begin());
                counter++;
            }

            //Removes two cards from the start of the vector and adds 2 to counter if there are two or more elements in the vector;
            else{
                cards.erase(cards.begin());
                cards.erase(cards.begin());
                counter += 2;
            }
        }

        else if(userInput == 11 || userInput == 12 || userInput == 13){
            //Removes one card from the end of the vector and adds 1 to counter if there is only 1 element in the vector;
            if(cards.size() == 1){
                cards.pop_back();
                counter++;
            }

            //Removes two cards from the end of the vector and adds 2 to counter if there are two or more elements in the vector;
            else{
                cards.pop_back();
                cards.pop_back();
                counter += 2;                        
            }
        }  
    }

    cards.pop_back(); //Removes the last card (14) from the vector when the user inputs 14;

    //Prints all cards remaining in the vector;
    cout << "Your remaining cards are:"; 
    for(int i = 0; i < cards.size(); i++){
        cout << " " << cards[i];
    }
    cout << endl;

    cout << "I have " << counter << " card(s)." << endl;

    //Prints "Tie!" if counter is equal to the size of the vector;
    if(counter == cards.size()){
        cout << "Tie!" << endl;
    }

    //Prints "I win!" if counter is greater than the size of the vector;
    else if(counter > cards.size()){
        cout << "I win!" << endl;
    }

    //Prints "You win!" if counter is smaller than the size of the vector;
    else{
        cout << "You win!" << endl;
    }
}