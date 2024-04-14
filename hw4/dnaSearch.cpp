// CSCI 1300 Fall 2022
// Author: Rodrigo Nicastro
// Recitation: 201 – Elise Tate
// Homework 4 - Problem #4

#include <iostream>
using namespace std;

int occurrences = 0;
bool invalidDNA = false;
bool invalidFragment = false;
string userSequence;
string userFragment;

int main(){
    //Takes the user's input for the DNA Sequence.
    cout << "Enter the DNA Sequence:" << endl;
    cin >> userSequence;

    int sequenceLength = userSequence.length();

    //Makes sure the user inputs a valid DNA Sequence.
    for(int x = 0; x <= sequenceLength - 1; x++){
        if(userSequence[x] != 'A' && userSequence[x] != 'C' && userSequence[x] != 'T' && userSequence[x] != 'G'){
            cout << "This is not a valid DNA sequence." << endl;
            invalidDNA = true;
            break;
        }
    }

    if(invalidDNA == false){
        //Takes the users input for the DNA Fragment.
        cout << "Enter the DNA fragment to be searched:" << endl;
        cin >> userFragment;
    
        int fragmentLength = userFragment.length();

        //Makes sure the user inputs a valid DNA Fragment.
        for(int y = 0; y <= fragmentLength - 1; y++){
                if(userFragment[y] != 'A' && userFragment[y] != 'C' && userFragment[y] != 'T' && userFragment[y] != 'G'){
                cout << "This is not a valid DNA sequence" << endl;
                invalidFragment = true;
                break;
                }
        }
            
                if(invalidFragment == false){
                    //Computes how many times the fragment inputed appears in the original DNA Sequence.
                    for(int i = 0; i <= sequenceLength - 1; i++){

                        string sequenceSub = userSequence.substr(i, fragmentLength);

                        if(userFragment == sequenceSub){
                            occurrences++;
                        }
                    }
                    //Prints how many times the fragment inputed appears in the original DNA Sequence.
                    cout << "Number of occurrences: " << occurrences << endl;
                }
}
}