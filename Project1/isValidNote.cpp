// CSCI 1300 Fall 2022
// Author: Rodrigo Nicastro
// Recitation: 201 – Elise Tate
//Project 1 - Problem #1

#include <iostream>
using namespace std;

bool isValidNote(string note){
    int noteLength = note.length();
    bool validNote;

    //Makes sure the note is 2 characters long
    if(noteLength != 2){
        validNote = false;
    }

    else{
        //Converts each character of the note to ASCII code.
        int ascii1 = int(note[0]);
        int ascii2 = int(note[1]);

        //Verifies if the characters are within the valid scope. If so, the function returns true.
        if((ascii1 >= 65 && ascii1 <= 71) && (ascii2 >= 48 && ascii2 <= 57)){
            validNote = true;
        }

        //If one of the characters are not within the valid scope, the function returns false.
        else{
            validNote = false;
        }
    }

    return validNote;
}

int main(){
    //Test cases:
    cout << isValidNote("C1") << endl; //Valid note
    cout << isValidNote("C1D1") << endl; //Invalid length
    cout << isValidNote("c1") << endl; //Case sensitivity
    cout << isValidNote("") << endl; //Empty string
}