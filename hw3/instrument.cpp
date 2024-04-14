// CSCI 1300 Fall 2022
// Author: Rodrigo Nicastro
// Recitation: 201 – Elise Tate
// Homework 3 - Problem #5

#include <iostream>
using namespace std;

int inputCategory;
int inputInstrument;

int main(){
    //Takes the user input for the instrument category.
    cout << "Select a category: (1)Brass (2)Woodwind (3)Percussion" << endl;
    cin >> inputCategory;

    //Makes sure the user inputs a valid category.
    while(inputCategory != 1 && inputCategory != 2 && inputCategory != 3){
        cout << "Please enter a valid input." << endl;
        cin >> inputCategory;
    }

    switch(inputCategory){
        case 1:
            //Takes the user input for the instrument, in case the chosen category was Brass.
            cout << "Select an instrument: (1)Trumpet (2)Trombone" << endl;
            cin >> inputInstrument;

            //Makes sure the user inputs a valid instrument.
            while (inputInstrument != 1 && inputInstrument != 2){
                cout << "Please enter a valid input." << endl;
                cin >> inputInstrument;
            }

            switch(inputInstrument){
                case 1:
                    //Prints how much the Trumpet instrument will cost.
                    cout << "Your instrument will be $350." << endl;
                    break;
                case 2:
                    //Prints how much the instrument Trombone will cost.
                    cout << "Your instrument will be $400." << endl;
                    break;
                }
            break;

        case 2:
            //Takes the user input for the instrument, in case the chosen category was Woodwind.
            cout << "Select an instrument: (1)Flute (2)Saxophone" << endl;
            cin >> inputInstrument;

            //Makes sure the user inputs a valid instrument.
            while (inputInstrument != 1 && inputInstrument != 2){
                cout << "Please enter a valid input." << endl;
                cin >> inputInstrument;
            }
            
            switch(inputInstrument){
                case 1:
                    //Prints how much the instrument Flute will cost.
                    cout << "Your instrument will be $325." << endl;
                    break;
                case 2:
                    //Prints how much the instrument Saxophone will cost.
                    cout << "Your instrument will be $425." << endl;
                    break;
                }
            break;

        case 3:
            //Takes the user input for the instrument, in case the chosen category was Percussion.
            cout << "Select an instrument: (1)Snare Drum (2)Cymbals" << endl;
            cin >> inputInstrument;

            //Makes sure the user inputs a valid instrument.
            while (inputInstrument != 1 && inputInstrument != 2){
                cout << "Please enter a valid input." << endl;
                cin >> inputInstrument;
            }
            
            switch(inputInstrument){
                case 1:
                    //Prints how much the instrument Snare Drum will cost.
                    cout << "Your instrument will be $275." << endl;
                    break;
                case 2:
                    //Prints how much the instrument Cymbals will cost.
                    cout << "Your instrument will be $200." << endl;
                    break;
                }
            break;
    }
}