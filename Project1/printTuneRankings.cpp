// CSCI 1300 Fall 2022
// Author: Rodrigo Nicastro
// Recitation: 201 – Elise Tate
//Project 1 - Problem #6

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

    if(inputTuneLength < targetTuneLength){
            bestSimilarity = 0;
    }
        
    else{
        double subInputTuneLength = inputTuneLength;
        subInputTune.assign(inputTune,0,targetTuneLength);
        bestSimilarity = tuneSimilarity(subInputTune, targetTune);

        for(int i = 0; subInputTuneLength >= targetTuneLength; i += 2){
            subInputTune.assign(inputTune,i,targetTuneLength);
            subInputTuneLength = subInputTune.length();

            if(tuneSimilarity(subInputTune, targetTune) == 0){
                break;
            }

            if(tuneSimilarity(subInputTune, targetTune) > bestSimilarity){
                bestSimilarity = tuneSimilarity(subInputTune, targetTune);
            }
        }
    }
            

    return bestSimilarity;
}

void printTuneRankings(string inputTune1, string inputTune2, string inputTune3, string targetTune2){
    double simTune1 = bestSimilarity(inputTune1, targetTune2); //Takes the best similarity for tune 1.
    double simTune2 = bestSimilarity(inputTune2, targetTune2); //Takes the best similarity for tune 2.
    double simTune3 = bestSimilarity(inputTune3, targetTune2); //Takes the best similarity for tune 3.
    string bestSim;
    string secBestSim;
    string thirdBestSim;

    //Checks if the most similar tune is Tune 1.
    if(simTune1 >= simTune2 && simTune1 >= simTune3){
        bestSim = "Tune 1";

        //Checks if Tune 2 has a better similarity score than Tune 3.
        if(simTune2 >= simTune3){
            secBestSim = "Tune 2";
            thirdBestSim = "Tune 3";
        }

        //Checks if Tune 3 has a better similarity score than Tune 2.
        else{
            secBestSim = "Tune 3";
            thirdBestSim = "Tune 2";
        }
    }

    //Checks if the most similar tune is Tune 2.
    else if(simTune2 >= simTune1 && simTune2 >=simTune3){
        bestSim = "Tune 2";

        //Checks if Tune 1 has a better similarity score than Tune 3.
        if(simTune1 >= simTune3){
            secBestSim = "Tune 1";
            thirdBestSim = "Tune 3";
        }

        //Checks if Tune 3 has a better similarity score than Tune 1.
        else{
            secBestSim = "Tune 3";
            thirdBestSim = "Tune 1";
        }
    }

    //Checks if the most similar tune is Tune 3.
    else if(simTune3 >= simTune1 && simTune3 >= simTune2){
        bestSim = "Tune 3";

        //Checks if Tune 1 has a better similarity score than Tune 2.
        if(simTune1 >= simTune2){
            secBestSim = "Tune 1";
            thirdBestSim = "Tune 2";
        }

        //Checks if Tune 2 has a better similarity score than Tune 1.
        else{
            secBestSim = "Tune 2";
            thirdBestSim = "Tune 1";
        }
    }
    cout << "1) " << bestSim << ", 2) " << secBestSim << ", 3) " << thirdBestSim << endl;
}

int main(){
   printTuneRankings("C2E7", "E3D4", "D3F4", "A7"); //Valid inputs and different similarity scores
   printTuneRankings("C4D6G1A8", "C4D6G1", "G9B7A0", "C4D8A1"); //Valid inputs but tunes 1 and 2 have equal similarity scores
   printTuneRankings("G9B7A0", "C4D6G1", "C4D6G1A8", "C4D8A1"); //Valid inputs but tunes 2 and 3 have equal similarity scores
   printTuneRankings("C4D6G1A8", "G9B7A0", "C4D6G1", "C4D8A1"); //Valid inputs but tunes 1 and 3 have equal similarity scores
}