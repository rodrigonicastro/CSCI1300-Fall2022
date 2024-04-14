// CSCI 1300 Fall 2022
// Author: Rodrigo Nicastro
// Recitation: 201 – Elise Tate
// Homework 4 - Problem #2

#include <iostream>
#include <iomanip>
using namespace std;

double min(double arr[], int arr_size){
    double minHours = 168;

    for(int i = 0; i < arr_size; i++){
        double hours = arr[i];
        
        if(hours < minHours){
            minHours = hours;
        }
    }
    return minHours;
}

double sum(double arr[], int arr_size){
    double sumHours = 0;

    for(int i = 0; i < arr_size; i++){
        sumHours += arr[i];
    }
    return sumHours;
}

double average(double arr[], int arr_size){
    double sumHours = 0;

    for(int i = 0; i < arr_size; i++){
        sumHours += arr[i];
    }
    
    double averageHours = sumHours / arr_size;

    return averageHours;
}

int main(){
    double arr[] = {1.24, 5.68, 3.456};
    int arr_size = 3;
    cout << "Min: " << fixed << setprecision(3) << min(arr, arr_size) << endl;
    cout << "Sum: " << fixed << setprecision(3) << sum(arr, arr_size) << endl;
    cout << "Avg: " << fixed << setprecision(3) << average(arr, arr_size) << endl;
}