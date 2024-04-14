#include <iostream>
using namespace std;

void swap(int myArray[], int startIndex, int endIndex){
    myArray[startIndex] = myArray[endIndex];
    myArray[endIndex] = myArray[startIndex];
}

void reverseArray(int myArray[], int myArrayLength){
    for(int i = 0, n = myArrayLength; i <= myArrayLength/2; i++, n--){
        swap(myArray[myArrayLength], i, n);
    }

    cout << "The reversed array is: " << myArray[myArrayLength] << endl;
}

int main(){
    cout << "Please enter the size of the array:" << endl;
    cin >> myArrayLength;

    cout << "Please enter the elements of the array:" << endl;
    cin >> myArray;

    reverseArray(myArray[myArrayLength], myArrayLength);
}