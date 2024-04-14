#include <iostream>
#include <fstream>
#include <string>
#include "User.h"
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

void findTagUser(string username_tag, User users[], int num_users_stored){
    bool validTag = false;

    if(num_users_stored <= 0){
        cout << "No users are stored in the database" << endl;
    }

    else{
        for(int i = 0; i < num_users_stored; i++){
            int tagLength = username_tag.length();
            string username = users[i].getUsername(); //Assigns the current username in the array to the string "username";
            int usernameLength = username.length();
            string piece;
        
            //Verifies if the tag inputted by the user matches the current username;
            for(int n = 0; n < usernameLength; n++){
                piece.assign(username, n, tagLength);

                if(piece == username_tag){
                    validTag = true;
                }
            }
        }

        //If there are no matches to the tag, print "No matching user found";
        if(validTag == false){
            cout << "No matching user found" << endl;
        }

        //If there are matches to the tag, print all usernames that apply;
        else{
            cout << "Here are all the usernames that contain " << username_tag << endl;

            for(int i = 0; i < num_users_stored; i++){
                int tagLength = username_tag.length();
                string username = users[i].getUsername();
                int usernameLength = username.length();
                string piece;
        
                for(int n = 0; n < usernameLength; n++){
                    piece.assign(username, n, tagLength);

                    if(piece == username_tag){
                        cout << username << endl;
                    }
                }
            }
        }
    }
}

int main(){
// test only one matching user
User users[10];

int max_posts = 4;
int num_users_stored = 0;
int users_arr_size = 10;

num_users_stored = readLikes("users.txt", users, num_users_stored, users_arr_size, max_posts);
findTagUser("best",users, num_users_stored);

	
//test no users are stored in the database
User user_array[5];
findTagUser("ol",user_array,0);

// test no matching user
User users[10];

int max_posts = 4;
int num_users_stored = 0;
int users_arr_size = 10;

num_users_stored = readLikes("users.txt", users, num_users_stored, users_arr_size, max_posts);
findTagUser("AT",users, num_users_stored);

// test multiple matching users
User users[10];

int max_posts = 4;
int num_users_stored = 0;
int users_arr_size = 10;

num_users_stored = readLikes("userstxt", users, num_users_stored, users_arr_size, max_posts);
findTagUser("am",users, num_users_stored);
}