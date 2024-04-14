// CSCI 1300 Fall 2022
// Author: Rodrigo Nicastro
// Recitation: 201 – Elise Tate
// Homework 4 - Problem #Extra Credit

#include <iostream>
#include <cmath>
using namespace std;

double userFrequency;
int noteNumber;
string notes = "CdDeEFgGaAbB";
char finalNote;

int main(){
    //Takes the user input for the frequency.
    cout << "What is your frequency?" << endl;
    cin >> userFrequency;
    
   //Makes sure the user inputs a valid frequency.
    if(userFrequency < 32.7 || userFrequency > 4186){
            cout << "Your note is not on a piano." << endl;
        }

    else{
    //Computes the number that represents the closest note from the user's frequency
    noteNumber = round(12 * log2(userFrequency/32.7));

    //Computes and prints the user's final note.
    finalNote = notes[noteNumber - 12*(noteNumber/12)];
    cout << "Your note is: " << finalNote << noteNumber/12 + 1 << "." << endl;

    cout << "Your melody is: " << finalNote << noteNumber/12 + 1 << ", ";

   while(noteNumber > 0){
        //Computes the next note in the melody if the current note is a lower case note.
        if(finalNote == 'd' || finalNote == 'e' || finalNote == 'g' || finalNote == 'a' || finalNote == 'b'){
            noteNumber = noteNumber + 4;

                if(noteNumber < 12){
                    finalNote = notes[noteNumber];
                    cout << finalNote << noteNumber/12 + 1 << ", ";
                }

                else{
                    finalNote = notes[noteNumber - 12*(noteNumber/12)];
                    cout << finalNote << noteNumber/12 + 1 << ", ";
                }

        }

        //Computes the next note in the melody if the current note is a higher case note.
        else{
            noteNumber = noteNumber - 7;

            if(noteNumber < 0){}

            else{
                if(noteNumber < 12){
                    finalNote = notes[noteNumber];
                    cout << finalNote << noteNumber/12 + 1 << ", ";
                }

                else{
                    finalNote = notes[noteNumber - 12*(noteNumber/12)];
                    cout << finalNote << noteNumber/12 + 1 << ", ";
                }
            }
        }
    }

    cout << endl;

    }
}