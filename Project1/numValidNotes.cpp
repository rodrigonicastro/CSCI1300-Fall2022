// CSCI 1300 Fall 2022
// Author: Rodrigo Nicastro
// Recitation: 201 – Elise Tate
//Project 1 - Problem #3

#include <iostream>
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

int numValidNotes(string tune){
    int tuneLength = tune.length();
    int validNotes = 0;
    
    for(int i = 0; i <= tuneLength - 1; i++){
            //Assigns a two-character note from the tune 
            string note;
            note.assign(tune,i,2);

            //Verifies if the note is valid. If so, adds 1 to "validNotes".
            if(isValidNote(note) == true){
                validNotes++;
            }
        }
        return validNotes;
}

int main(){
    cout << numValidNotes("Hello, World") << endl; //Invalid string
    cout << numValidNotes("A1B2C3D4") << endl; //Valid string with 4 valid notes
    cout << numValidNotes("AB12C9H2") << endl; //Testing if notes are assigned correctly
    cout << numValidNotes("") << endl; //Empty string
}