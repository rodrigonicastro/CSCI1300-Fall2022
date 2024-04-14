// CSCI 1300 Fall 2022
// Author: Rodrigo Nicastro
// Recitation: 201 – Elise Tate
// Homework 6 - Problem #2

#include <iostream>
#include <string>
#include <fstream>
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
            arr[x + 1] = piece.assign(input_string, y + n + 1, input_string_length - n - 1);

            x++;
            y = i + 1;
            n = -1;
            result++;

            if(x > arr_size){
                cout << "a" << endl;
                result = -1;
                break;
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

void printMountainStats(string filename){
    string line;

    ifstream fin;

    fin.open(filename);

    if(fin.fail()){
        cout << "Could not open file." << endl;
    }

    else{
        int tallestMountain;
        int shortestMountain;
        string tallestMountainName;
        string shortestMountainName;
        int num_lines = 1;
        char separator = '|';
        int size = 2;
        string arr[size];

        getline(fin, line);
        while(line == ""){
            
        }
        
        split(line, separator, arr, size);
        int mountain = stoi(arr[1]);

        tallestMountain = mountain;
        tallestMountainName = arr[0];
        shortestMountain = mountain;
        shortestMountainName = arr[0];

        while(!fin.eof()){
            getline(fin, line);

            if(line != ""){
                split(line, separator, arr, size);
                mountain = stoi(arr[1]);

                if(mountain > tallestMountain){
                    tallestMountain = mountain;
                    tallestMountainName = arr[0];
                }

                if(mountain < shortestMountain){
                    shortestMountain = mountain;
                    shortestMountainName = arr[0];
                }
                num_lines++;
            }
        }
        cout << "Number of lines read: " << num_lines << "." << endl;
        cout << "Tallest mountain: " << tallestMountainName << " at " << tallestMountain << " feet." << endl;
        cout << "Shortest mountain: " << shortestMountainName << " at " << shortestMountain << " feet." << endl;
    }
}

int main(){
    string filename = "mountain_data.txt";
    printMountainStats(filename);
}