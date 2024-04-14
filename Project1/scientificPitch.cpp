// CSCI 1300 Fall 2022
// Author: Rodrigo Nicastro
// Recitation: 201 – Elise Tate
//Project 1 - Problem #7

#include <iostream>
#include <iomanip>
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
    int userChoice;

    //Prompts the user with the menu.
    cout << "--- Menu ---" << endl;
    cout << "1. Calculate similarity between two tunes." << endl;
    cout << "2. Calculate best similarity between two tunes of potentially different lengths." << endl;
    cout << "3. Print three input tunes in order from most to least similar to the target tune." << endl;
    cout << "4. Exit." << endl;
    cout << "Please enter your choice (1 - 4):" << endl;
    cin >> userChoice;

    //Makes sure the user inputs a valid choice from the menu.
    while(userChoice != 1 && userChoice != 2 && userChoice != 3 && userChoice != 4){
            cout << "Invalid Input." << endl;
            cout << "--- Menu ---" << endl;
            cout << "1. Calculate similarity between two tunes." << endl;
            cout << "2. Calculate best similarity between two tunes of potentially different lengths." << endl;
            cout << "3. Print three input tunes in order from most to least similar to the target tune." << endl;
            cout << "4. Exit." << endl;
            cout << "Please enter your choice (1 - 4):" << endl;
            cin >> userChoice;
    }
    
    //If the user does not choose option 4 (Exit), the program continues to prompt them the menu.
    while(userChoice != 4){
        switch(userChoice){
            case 1:{
                string userTune1;
                string userTune2;

                //Takes the user input for the first tune.
                cout << "Please enter the first tune:" << endl;
                cin >> userTune1;

                //Makes sure the user inputs a valid SPN.
                while(isValidTune(userTune1) == false){
                    cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
                    cin >> userTune1;
                }

                //Takes the user input for the second tune.
                cout << "Please enter the second tune:" << endl;
                cin >> userTune2;

                //Makes sure the user inputs a valid SPN.
                while(isValidTune(userTune2) == false){
                    cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
                    cin >> userTune2;
                }

                //Calculates the similarity score between the tunes inputted by the user (with a precision of 2 decimal points).
                cout << "The similarity score is " << fixed << setprecision(2) << tuneSimilarity(userTune1, userTune2) << endl;

                //Presents the menu to the user again.
                cout << "--- Menu ---" << endl;
                cout << "1. Calculate similarity between two tunes." << endl;
                cout << "2. Calculate best similarity between two tunes of potentially different lengths." << endl;
                cout << "3. Print three input tunes in order from most to least similar to the target tune." << endl;
                cout << "4. Exit." << endl;
                cout << "Please enter your choice (1 - 4):" << endl;
                cin >> userChoice;

                //Makes sure the user inputs a valid choice from the menu.
                while(userChoice != 1 && userChoice != 2 && userChoice != 3 && userChoice != 4){
                    cout << "Invalid Input." << endl;
                    cout << "--- Menu ---" << endl;
                    cout << "1. Calculate similarity between two tunes." << endl;
                    cout << "2. Calculate best similarity between two tunes of potentially different lengths." << endl;
                    cout << "3. Print three input tunes in order from most to least similar to the target tune." << endl;
                    cout << "4. Exit." << endl;
                    cout << "Please enter your choice (1 - 4):" << endl;
                    cin >> userChoice;
                
                }
                break;
            }
            

            case 2:{
                string userInputTune;
                string userTargetTune;

                //Takes the user input for the first tune.
                cout << "Please enter the input tune:" << endl;
                cin >> userInputTune;

                //Makes sure the user inputs a valid SPN.
                while(isValidTune(userInputTune) == false){
                    cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
                    cin >> userInputTune;
                }

                //Takes the user input for the target tune.
                cout << "Please enter the target tune:" << endl;
                cin >> userTargetTune;

                //Makes sure the user inputs a valid SPN.
                while(isValidTune(userTargetTune) == false){
                    cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
                    cin >> userTargetTune;
                }

                //Calculates the best similarity score between the tunes inputted by the user (with a precision of 2 decimal points).
                cout << "The best similarity score is: " << fixed << setprecision(2) << bestSimilarity(userInputTune, userTargetTune) << endl;

                //Presents the menu to the user again.
                cout << "--- Menu ---" << endl;
                cout << "1. Calculate similarity between two tunes." << endl;
                cout << "2. Calculate best similarity between two tunes of potentially different lengths." << endl;
                cout << "3. Print three input tunes in order from most to least similar to the target tune." << endl;
                cout << "4. Exit." << endl;
                cout << "Please enter your choice (1 - 4):" << endl;
                cin >> userChoice;

                //Makes sure the user inputs a valid choice from the menu.
                while(userChoice != 1 && userChoice != 2 && userChoice != 3 && userChoice != 4){
                    cout << "Invalid Input." << endl;
                    cout << "--- Menu ---" << endl;
                    cout << "1. Calculate similarity between two tunes." << endl;
                    cout << "2. Calculate best similarity between two tunes of potentially different lengths." << endl;
                    cout << "3. Print three input tunes in order from most to least similar to the target tune." << endl;
                    cout << "4. Exit." << endl;
                    cout << "Please enter your choice (1 - 4):" << endl;
                    cin >> userChoice;
                }
                break;
            }

            case 3:{
                string userTune1;
                string userTune2;
                string userTune3;
                string userTargetTune;

                //Takes the user input for the first tune.
                cout << "Please enter the first tune:" << endl;
                cin >> userTune1;

                //Makes sure the user inputs a valid SPN.
                while(isValidTune(userTune1) == false){
                    cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
                    cin >> userTune1;
                } 

                //Takes the user input for the second tune.
                cout << "Please enter the second tune:" << endl;
                cin >> userTune2;

                //Makes sure the user inputs a valid SPN.
                while(isValidTune(userTune2) == false){
                    cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
                    cin >> userTune2;
                }

                //Takes the user input for the third tune.
                cout << "Please enter the third tune:" << endl;
                cin >> userTune3;

                //Makes sure the user inputs a valid SPN.
                while(isValidTune(userTune3) == false){
                    cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
                    cin >> userTune3;
                }

                //Takes the user input for the target tune.
                cout << "Please enter the target tune:" << endl;
                cin >> userTargetTune;
                
                //Makes sure the user inputs a valid SPN.
                while(isValidTune(userTargetTune) == false){
                    cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
                    cin >> userTargetTune;
                }

                //Calculates the rankings for the best similarity scores between the tunes inputted by the user.
                printTuneRankings(userTune1, userTune2, userTune3, userTargetTune);

                //Presents the menu to the user again.
                cout << "--- Menu ---" << endl;
                cout << "1. Calculate similarity between two tunes." << endl;
                cout << "2. Calculate best similarity between two tunes of potentially different lengths." << endl;
                cout << "3. Print three input tunes in order from most to least similar to the target tune." << endl;
                cout << "4. Exit." << endl;
                cout << "Please enter your choice (1 - 4):" << endl;
                cin >> userChoice;

                //Makes sure the user inputs a valid choice from the menu.
                while(userChoice != 1 && userChoice != 2 && userChoice != 3 && userChoice != 4){
                    cout << "Invalid Input." << endl;
                    cout << "--- Menu ---" << endl;
                    cout << "1. Calculate similarity between two tunes." << endl;
                    cout << "2. Calculate best similarity between two tunes of potentially different lengths." << endl;
                    cout << "3. Print three input tunes in order from most to least similar to the target tune." << endl;
                    cout << "4. Exit." << endl;
                    cout << "Please enter your choice (1 - 4):" << endl;
                    cin >> userChoice;      
                }
                break;
            }
        }           
    }

    //When the user chooses '4', prints "Goodbye!" and terminates the program.
    cout << "Goodbye!" << endl;
}