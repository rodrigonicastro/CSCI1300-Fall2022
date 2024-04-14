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

int readLikes(string file_name, User users[], int num_users_stored, int users_arr_size, int max_posts){
    int result;
    
    //If the likes array is already full, return -2;
    if(num_users_stored == users_arr_size){
        result = -2;
    }

    else{
        //Open the users file;
        ifstream fin;
        fin.open(file_name);

        //If the file doesn't open, return -1;
        if(fin.fail()){
            result = -1;
        }

        else{
            int i = num_users_stored;

            while(!fin.eof()){
                string line;
                
                while(num_users_stored < users_arr_size){    
                    char separator = ',';
                    int size = max_posts + 1;
                    string arr[size];

                    //Assign the current line of the file to a string "line";
                    getline(fin, line);
                
                    //Makes sure the current line can be successfully split;
                    if(split(line, separator, arr, size) != 1 || split(line, separator, arr, size) != 0){
                        int x = 0;
                        int y = 1;
                        string username = arr[0];
                        int likesArr_size = users[i].getNumPosts();
                        int likesArr[likesArr_size];

                        //Adjusts the variable "max_posts" if needed;
                        if(max_posts > likesArr_size){
                             max_posts = likesArr_size;
                        }

                        //Assigns a value of likes to each element of the array;
                        while(x < max_posts){
                            int likesAtX = stoi(arr[y]);
                            likesArr[x] = likesAtX;

                            x++;
                            y++;
                        }

                        //Declares an element of the User class with the current parameters;
                        users[i] = {User(username, likesArr, likesArr_size)};

                        if(i > 0){
                            //If the current line is the same as the previous, meaning the loop is stuck at the last line of the file, breakes the loop;
                            if(users[i].getUsername() == users[i - 1].getUsername()){
                                users[i] = {User()};
                                break;
                            }
                        }
                        
                        i++;
                        num_users_stored++;
                    }                 
                }
                break;
            }
            result = num_users_stored;
        }
    }
    return result;
}

int main(){
// check if we can call the function
User users[10];

int max_posts = 50;
int num_users_stored = 0;
int users_arr_size = 10;

readLikes("users.txt", users, num_users_stored, users_arr_size, max_posts);
cout << "checking if we can call the function" << endl;

	
// Reading unknown file
User users[10];

int max_posts = 50;
int num_users_stored = 0;
int users_arr_size = 10;

cout << readLikes("file_not_found.txt", users, num_users_stored, users_arr_size, max_posts) << endl;

	
// check return value after reading the file
User users[10];

int max_posts = 4;
int num_users_stored = 0;
int users_arr_size = 10;

cout << readLikes("users.txt", users, num_users_stored, users_arr_size, max_posts) << endl;

	
//  -2 if array cannot store any more users
User users[4];
int likes1[3] = {1, 3, 0};
users[0] = User("bookworm43", likes1, 3);
users[1] = User("bookworm43", likes1, 3);
users[2] = User("bookworm43", likes1, 3);
users[3] = User("bookworm43", likes1, 3);


int max_posts = 50;
int num_users_stored = 4;
int users_arr_size = 4;

cout << readLikes("users.txt", users, num_users_stored, users_arr_size, max_posts) << endl;


}