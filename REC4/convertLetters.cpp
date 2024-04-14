#include <iostream>
using namespace std;

int main(){
    //Takes a string from the user.
    cout << "Please enter a string:" << endl;
    string userInput;
    getline(cin, userInput);
    
    int stringLength = userInput.length(); //Stores the amount of characters in the string as an int in the variable "stringLength".

    
    for(int i=0; i<=stringLength;i++){ //Loops the steps below until the number of characters in the string is reached.
        char letter = userInput[i]; //Stores a character from the string inside the char "letter".
        int decimal = int(letter); //Converts the character into its decimal value.

        if(decimal >= 97 && decimal <= 122){ //Verifies if the character is a lowercase letter.
            decimal -= 32; //Converts the decimal value of the lowercase letter to its uppercase counterpart.
            letter = int(decimal); //Converts the decimal value for the uppercase letter to a char.
            cout << letter; //Prints the uppercase letter.
        }
        else{
            cout << letter; //Prints the character if it is not a letter, or already a uppercase one.
        }        
    }
    cout << endl;
}