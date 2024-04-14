#include <iostream>
#include "User.h"
using namespace std;

int main(){
    User a = User();
    
    cout << "User A: " << endl << " Username: " << a.getUsername() << endl << " # of Posts: " << a.getNumPosts() << endl << " Size: " << a.getSize() << endl;
    for(int i = 0; i < a.getNumPosts(); i++){
        cout << " Likes at Post #" << i << ": " << a.getLikesAt(i) << endl;
    }  

    int arr[10];
    User b = User("Rodrigo", arr, 10);
    for(int i = 0; i < 10; i++){
        b.setLikesAt(i, i);
    }

    cout << "User B: " << endl << " Username: " << b.getUsername() << endl << " # of Posts: " << b.getNumPosts() << endl << " Size: " << b.getSize() << endl;
    for(int i = 0; i < b.getNumPosts(); i++){
        cout << " Likes at Post #" << i << ": " << b.getLikesAt(i) << endl;
    }

    b.setNumPosts(15);
    b.setUsername("Rodrigo Nicastro");
    b.setLikesAt(12, 10);
    b.setLikesAt(13, 11);

    cout << "User B: " << endl << " Username: " << b.getUsername() << endl << " # of Posts: " << b.getNumPosts() << endl << " Size: " << b.getSize() << endl;
    for(int i = 0; i < b.getNumPosts(); i++){
        cout << " Likes at Post #" << i << ": " << b.getLikesAt(i) << endl;
    }

}