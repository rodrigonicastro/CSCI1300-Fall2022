// CSCI 1300 Fall 2022
// Author: Rodrigo Nicastro
// Recitation: 201 – Elise Tate
// Homework 4 - Problem #6

#include <iostream>
using namespace std;

int zeroesToFives(int arr[], int arr_size){
	int count = 0;
	//loops through input array
	for(int i = 0; i < arr_size; i++) 
	{ 
		if(arr[i] == 0) //if an element is zero, set it to five
		{ 
    			arr[i] = 5;
			count++;
		}
	}
	return count;
}

int main(){
    int size = 3;
    int arr[size]={1, 2, 3};
    cout << zeroesToFives(arr, size) << endl;

    int size1 = 0;
    int arr1[size1]={};
    cout << zeroesToFives(arr1, size1) << endl;

    int size2 = 10;
    int arr2[size2]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << zeroesToFives(arr2, size2) << endl;

    int size3 = 5;
    int arr3[size3]={0, 0, 0, 0, 0};
    cout << zeroesToFives(arr3, size3) << endl;

    int size4 = 6;
    int arr4[size4]={0, 5, 0, 5, 0, 5};
    cout << zeroesToFives(arr4, size4) << endl;

    int size5 = 1;
    int arr5[size5]={0};
    cout << zeroesToFives(arr5, size5) << endl;

    int size6 = 1;
    int arr6[size6]={5};
    cout << zeroesToFives(arr6, size6) << endl;

    int size7 = 2;
    int arr7[size7]={0, 5};
    cout << zeroesToFives(arr7, size7) << endl;

    int size8 = 1;
    int arr8[size8]={1};
    cout << zeroesToFives(arr8, size8) << endl;

    int size9 = 3;
    int arr9[size9]={0, 5, 0};
    cout << zeroesToFives(arr9, size9) << endl;   
}