// CSCI 1300 Fall 2022
// Author: Rodrigo Nicastro
// Recitation: 201 – Elise Tate
// Homework 4 - Problem #3a

#include <iostream>
using namespace std;

bool insertAfter(string input_strings[], int num_elements, int array_size, int index, string string_to_insert){
    bool validInput = true;

    if(index >= array_size || num_elements == array_size){
        validInput = false;
    }

    else{
        if(input_strings[index + 1] != ""){
            for(int i = num_elements - 1; i >= index + 1; i--){
                input_strings[i + 1] = input_strings[i];
            }
            input_strings[index + 1] = string_to_insert;
        }

        else{
            input_strings[index + 1] = string_to_insert;
        }
    }
    return validInput;
}

int main(){
    int size = 5;
    string input_strings[size] = {"clefairy", "meowth", "snorlax"};
    int num_elements = 3;
    int index = 1;
    string string_to_insert = "charizard";

    bool result = insertAfter(input_strings, num_elements, size, index, string_to_insert);
    cout << "Function returned value: "<< result << endl;

    for(int i = 0; i < size; i++){
        cout << input_strings[i] << endl;
    }
}