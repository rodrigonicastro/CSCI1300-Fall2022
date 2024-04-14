// CSCI 1300 Fall 2022
// Author: Rodrigo Nicastro
// Recitation: 201 – Elise Tate
// Homework 7 - Problem #2

#include <iostream>
#include <vector>
using namespace std;

string dnaRead(vector<string> vect){
    bool validSequence = true;

    //If one of the elements in the vector has a size different than 3, set "validSequence" to false;
    for(int i = 0; i < vect.size(); i++){
        if(vect[i].length() != 3){
            validSequence = false;
            break;
        }
        
        //If one of the characters inside the elements in the vector is different than A, C, T, or G, set "validSequence" to false;
        for(int n = 0; n < 3; n++){
            if(vect[i][n] != 'A' && vect[i][n] != 'C' && vect[i][n] != 'T' && vect[i][n] != 'G'){
                validSequence = false;
                break;
            }
        }
    }

    //If validSquence if false, return "Invalid sequence.";
    if(validSequence == false){
        return "Invalid sequence.";
    }

    else{
        //Set the DNA sequence to an empty string;
        string sequence = "";
        for(int i = 0; i < vect.size(); i++){
            //Start reading when the current element is "ATG";
            if(vect[i] == "ATG"){
                i++;
                //Continue adding elements to the DNA sequence until the end of the vector or a stop codon is reached;
                while(vect[i] != "TAA" && vect[i] != "TAG" && vect[i] != "TGA"){
                    sequence += vect[i];
                    i++;
                    if(i == vect.size()){
                        break;
                    }
                }
                break;
            }   
        }
        return sequence;
    }
}

int main(){
    //Test case 1 - success;
    vector<string> vect1 = {"ATG", "CAT", "ACT", "GAC", "TAA", "ACT", "TAC"};
    cout << dnaRead(vect1) << endl;

    //Test case 2 - no start codon;
    vector<string> vect2 = {"CAT", "ACT", "GAC", "TAA", "ACT", "TAC"};
    cout << dnaRead(vect2) << endl;

    //Test case 3 - no end codon;
    vector<string> vect3 = {"ATG", "CAT", "ACT", "GAC", "ACT", "TAC"};
    cout << dnaRead(vect3) << endl;

    //Test case 4 - invalid sequence(one element is shorter than 3 letters);
    vector<string> vect4 = {"ATG", "CAT", "ACT", "GC", "TAA", "ACT", "TAC"};
    cout << dnaRead(vect4) << endl;

    //Test case 5 - invalid sequence(one element has an invalid letter);
    vector<string> vect5 = {"ATG", "CAT", "ACT", "GOC", "TAA", "ACT", "TAC"};
    cout << dnaRead(vect5) << endl;


}