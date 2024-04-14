// CSCI 1300 Fall 2022
// Author: Rodrigo Nicastro
// Recitation: 201 – Elise Tate
// Homework 4 - Problem #3b

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

int secondPlace(string input_strings[], string string_to_insert, string string_to_find, int num_elements, int array_size, int count){
    int result = num_elements;

    if(num_elements != array_size && num_elements + count <= array_size){

        for(int x = 0; x < num_elements; x++){
            if(input_strings[x] == string_to_find){
                insertAfter(input_strings, num_elements, array_size, x, string_to_insert);
                num_elements++;
                result++;
            }  
        }          
    }
    
    return result;
}

int main(){
    	
    int size = 9;
    int count = 4;
    string inputStrings[size] = {"clefairy", "raichu", "raichu","raichu", "ponyta", "charizard"};
    int numElements = 6;
    string stringToInsert = "pikachu";
    string stringToFind = "meowth";

    numElements = secondPlace(inputStrings, stringToInsert, stringToFind, numElements, size, count);

    cout << "Function returned value: " << numElements << endl;

    for(int i = 0; i < size; i++){
            cout << inputStrings[i] << endl;
    }
}