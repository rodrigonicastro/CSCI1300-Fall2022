// CSCI 1300 Fall 2022
// Author: Rodrigo Nicastro
// Recitation: 201 – Elise Tate
//Project 1 - Problem #5

#include <iostream>
using namespace std;

double tuneSimilarity(string tune1, string tune2){
    double tune1Length = tune1.length();
    double tune2Length = tune2.length();
    double tuneSimilarity = 0;
    double matchingNotes = 0;
    double matchNoteMatchPitch = 0;
    double diffNoteDiffPitch = 0;

    if(tune1Length != tune2Length){
        tuneSimilarity = 0;
    }

    else{
        for(int i = 0; i <= tune1Length - 1; i+=2){
            string noteTune1;
            noteTune1.assign(tune1,i,2);

            string noteTune2;
            noteTune2.assign(tune2,i,2);

            if(noteTune1[0] == noteTune2[0] && noteTune1[1] != noteTune2[1]){
                matchingNotes++;
            }

            else if(noteTune1 == noteTune2){
                matchNoteMatchPitch++;
                matchingNotes++;
            }

            else if(noteTune1[0] != noteTune2[0] && noteTune1[1] != noteTune2[1]){
                diffNoteDiffPitch++;
            }
        }

        tuneSimilarity = ((matchingNotes/ (tune1Length/2.0)) + matchNoteMatchPitch - diffNoteDiffPitch);

    }
    return tuneSimilarity;
}

double bestSimilarity(string inputTune, string targetTune){
    double inputTuneLength = inputTune.length();
    double targetTuneLength = targetTune.length();
    double bestSimilarity;
    string subInputTune;

    //Makes sure the input string is not shorter than the target tune. If so, the function returns 0.
    if(inputTuneLength < targetTuneLength){
            bestSimilarity = 0;
    }
    
    else{ 
        double subInputTuneLength = inputTuneLength;
        subInputTune.assign(inputTune,0,targetTuneLength);
        bestSimilarity = tuneSimilarity(subInputTune, targetTune);

        for(int i = 0; subInputTuneLength >= targetTuneLength; i += 2){
            //Assigns a tune with equal length as the target string to the input string
            subInputTune.assign(inputTune,i,targetTuneLength);
            subInputTuneLength = subInputTune.length();

            //Breaks the loop when the tune assigned to the input string becomes shorter than the target string
            if(tuneSimilarity(subInputTune, targetTune) == 0){
                break;
            }

            //Updates the "bestSimilarity" variable if the similarity of the current tune is greater than the previous.
            if(tuneSimilarity(subInputTune, targetTune) > bestSimilarity){
                bestSimilarity = tuneSimilarity(subInputTune, targetTune);
            }
        }
    }
            

    return bestSimilarity;
}

int main(){
    cout << bestSimilarity("F1E2C2D1A7B8D3", "F2A7C3") << endl; //Valid input
    cout << bestSimilarity("A1B2C3", "F2A7C3D5") << endl; //Input string shorter than target string
}