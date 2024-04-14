#include <iostream>
#include <fstream>
#include <string>
#include "Post.h"
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

int readPosts(string file_name, Post posts[], int num_posts_stored, int posts_arr_size){
    int result;
    string line;
    int size = 4;
    string arr[size];
    char separator = ',';

    //open posts file;
    ifstream fin;
                        
    fin.open(file_name);

    //if the file doesn't open, return -1;
    if(fin.fail()){
        result = -1;    
    }

    //If the array is already full, return -2;
    else if(posts_arr_size == num_posts_stored){
        result = -2;        
    }

    else{
        result = num_posts_stored;
        int i = num_posts_stored;

        while(!fin.eof()){
                //Assign a line of the file to a string "line";
                getline(fin, line);

                //If the line has all parameters of Post, declare an element of the Post class;
                if(split(line, separator, arr, size) == 4){
                    posts[i] = Post(arr[0], arr[1], stoi(arr[2]), arr[3]);
                
                    result++;
                    i++;

                    //Once the array has reached its size limit, breal the loop;
                    if(i == posts_arr_size){
                        break;
                    }
                }
        }
    }
    return result;
}


int main(){

readPosts("posts.txt", posts, 0, 50);
cout << "checking if we can call the function" << endl;

// Test non-exist file;
cout << readPosts("nonexistentfile.txt", posts, 0, 50) << endl;

// Test if the return value is correct
cout << readPosts("posts.txt", posts, 0, 50) << endl;

	
// return -2 if the arr is already full
posts[0] = Post("new post","user1", 10, "10/02/22");
posts[1] = Post("Hello!","user2", 9, "10/04/22");
posts[2] = Post("Hey!","user3", 9, "10/04/22");

num_posts_stored = 3;

num_posts_stored = readPosts("posts.txt", posts, num_posts_stored, 3);
cout << "Function returned value: " << num_posts_stored << endl;

	
// return size if the arr gets full while reading a file
num_posts_stored = 0;
num_posts_stored = readPosts("posts.txt", posts, num_posts_stored, 10);
cout << "Function returned value: " << num_posts_stored << endl;

printPostLikes(posts, num_posts_stored);

// Testing empty lines
num_posts_stored = 0;

num_posts_stored = readPosts("posts_empty_lines.txt", posts, num_posts_stored, 50);
cout << "Function returned value: " << num_posts_stored << endl;

printPostAuthor(posts, num_posts_stored);
}