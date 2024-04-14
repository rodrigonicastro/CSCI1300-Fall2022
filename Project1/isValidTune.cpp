// CSCI 1300 Fall 2022
// Author: Rodrigo Nicastro
// Recitation: 201 – Elise Tate
//Project 1 - Problem #2

#include <iostream>
#include <cstring>
using namespace std;

bool isValidNote(string note){
    int noteLength = note.length();
    bool validNote;

    if(noteLength != 2){
        validNote = false;
    }

    else{
        int ascii1 = int(note[0]);
        int ascii2 = int(note[1]);

        if((ascii1 >= 65 && ascii1 <= 71) && (ascii2 >= 48 && ascii2 <= 57)){
            validNote = true;
        }

        else{
            validNote = false;
        }
    }

    return validNote;
}

bool isValidTune(string tune){
    bool validTune;
    int validNotes = 0;
    int tuneLength = tune.length();

    //Verifies if the length of the string is valid.
    if(tuneLength % 2 != 0 || tuneLength < 2){
        validTune = false;
    }
    else{
        for(int i = 0; i <= tuneLength - 1; i+=2){
            //Assigns a two-character note from the tune 
            string note;
            note.assign(tune,i,2);

            //Verifies if the note assigned is valid.
            if(isValidNote(note) == true){
                validTune = true; 
            }

            //Returns false as soon as one note is invalid.
            else{
                validTune = false;
                break;
            }
        }
    }
    
    return validTune;
}

int main(){
    cout << isValidTune("A1B2C3D4") << endl; //Valid note
    cout << isValidTune("A1B2C") << endl; //Invalid length
    cout << isValidTune("a1b2c3d4") << endl; //Case sensitivity
    cout << isValidTune("H1I2J3K4") << endl; //Invalid notes
    cout << isValidTune("") << endl; //Empty string
}