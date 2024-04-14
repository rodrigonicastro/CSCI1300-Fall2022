// CSCI 1300 Fall 2022
// Author: Rodrigo Nicastro
// Recitation: 201 – Elise Tate
//Project 1 - Problem #4

#include <iostream>
using namespace std;

double tuneSimilarity(string tune1, string tune2){
    double tune1Length = tune1.length();
    double tune2Length = tune2.length();
    double tuneSimilarity = 0;
    double matchingNotes = 0;
    double matchNoteMatchPitch = 0;
    double diffNoteDiffPitch = 0;

    //Makes sure that both strings have the same length. If not, the function returns 0.
    if(tune1Length != tune2Length){
        tuneSimilarity = 0;
    }

    else{
        for(int i = 0; i <= tune1Length - 1; i+=2){
            //Assigns a two-character note from the first tune.
            string noteTune1;
            noteTune1.assign(tune1,i,2);

            //Assigns a two-character note from the second tune.
            string noteTune2;
            noteTune2.assign(tune2,i,2);

            //Checks if the notes match. If so, adds 1 to "matchingNotes".
            if(noteTune1[0] == noteTune2[0] && noteTune1[1] != noteTune2[1]){
                matchingNotes++;
            }

            //Checks if the notes and pitches match. If so, adds 1 to "matchingNotes" and "matchNoteMatchPitch".
            else if(noteTune1 == noteTune2){
                matchNoteMatchPitch++;
                matchingNotes++;
            }

            //Checks if both notes and pitches are different. If so, adds 1 to "diffNoteDiffPitch".
            else if(noteTune1[0] != noteTune2[0] && noteTune1[1] != noteTune2[1]){
                diffNoteDiffPitch++;
            }
        }

        //Calculates the tune similarity.
        tuneSimilarity = ((matchingNotes/ (tune1Length/2.0)) + matchNoteMatchPitch - diffNoteDiffPitch);

    }
    return tuneSimilarity;
}

int main(){
    cout << tuneSimilarity("A0E2D4", "D4E5C0") << endl; //Valid input
    cout << tuneSimilarity("A0E2", "D4E5C0") << endl; //First string shorter than the second
    cout << tuneSimilarity("A0E2D4", "D4E5") << endl; //First string longer than the second
}