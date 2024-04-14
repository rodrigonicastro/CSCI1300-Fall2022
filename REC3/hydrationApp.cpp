#include <iostream>
using namespace std;

int userInput;
int drinkAmount;

int main(){
    cout << "How many fl oz of water have you drank today?" << endl;
    cin >> userInput;

    drinkAmount = 64 - userInput;

    if(userInput >= 64){
        cout << "You’ve hit your goal for the day! Great job getting hydrated!" << endl;
    }

    else if (userInput >= 32 && userInput < 64) {
        cout << "You’re doing great, but you’re still halfway to your goal! Get that water in! You have " << drinkAmount << " fl oz left to drink" << endl;
    }

    else {
        cout << "You’re very, very dehydrated! Get that water in! You have " << drinkAmount << " fl oz left to drink." << endl;
    }

}