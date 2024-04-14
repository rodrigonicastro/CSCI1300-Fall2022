// CSCI 1300 Fall 2022
// Author: Rodrigo Nicastro
// Recitation: 201 – Elise Tate
// Homework 7 - Problem #1

#include <iostream>
#include <vector>
using namespace std;

int sumElements(vector<int> vect, int start_index, int end_index){
    //Return -1 if the start index is greater than the end index;
    if(start_index > end_index){
        return -1;
    }

    //Return -2 if the start index or end index (or both) are larger than the size of the vector;
    else if(start_index > vect.size() - 1 || end_index > vect.size() - 1){
        return -2;
    }

    else{
        int sum = 0;

        //Sum every number between the start and end index;
        for(int i = start_index; i <= end_index; i++){
            sum += vect[i];
        }
        return sum;
    }
}

int main(){
    vector<int> vect = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << sumElements(vect, 0, 9) << endl; //Test case 1 - success
    cout << sumElements(vect, -1, 10) << endl; // Test case 2 - fail (start and end index invalid);
    cout << sumElements(vect, 5, 5) << endl; // Test case 3 - sucess (start and end index are the same);
    cout << sumElements(vect, 8, 4) << endl; // Test case 4 - fail (start index is greater than end index);
}