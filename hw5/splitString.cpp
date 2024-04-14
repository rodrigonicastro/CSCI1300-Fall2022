// CSCI 1300 Fall 2022
// Author: Rodrigo Nicastro
// Recitation: 201 – Elise Tate
// Homework 4 - Problem #4

#include <iostream>
using namespace std;

int split(string input_string, char separator, string arr[], int arr_size){
    int x = 0;
    int y = 0;
    string piece;
    int result = 1;
    bool validSeparator = false;
    int input_string_length = input_string.length();
    
    for(int i = 0, n = 0; i < input_string_length; i++, n++){ 
        if(input_string[i] == separator){
            validSeparator = true;
            arr[x] = piece.assign(input_string, y, n);

            x++;
            y = i + 1;
            n = -1;
            result++;

            if(x == arr_size){
                result = -1;
                break;
            }

            else{
             arr[x] = piece.assign(input_string, y + n + 1, input_string_length - n - 1);   
            }
        }
    }

    if(validSeparator == false){
        result = 1;
        arr[0] = input_string;
    }

    if(input_string == ""){
        result = 0;
    }

    return result;
}

int main(){	
    string testcase = "culegislative,1,-1,-1";
    char separator = ',';
    int size = 50;
    string arr[size];

    int numSplits = split(testcase, separator, arr, size);
    cout << "Function returned value: " << numSplits << endl;

    for(int i = 0; i < size; i++){
            cout <<"arr[" << i << "]: " << arr[i] << endl;
    }
}