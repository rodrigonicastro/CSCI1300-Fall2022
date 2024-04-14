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

    ifstream fin;

    fin.open(file_name);

    if(fin.fail()){
        result = -1;
    }

    else if(posts_arr_size == num_posts_stored){
        result = -2;
    }

    else{
        result = num_posts_stored;
        int i = num_posts_stored;

        while(!fin.eof()){
                getline(fin, line);

                if(split(line, separator, arr, size) == 4){
                    posts[i] = Post(arr[0], arr[1], stoi(arr[2]), arr[3]);
                
                    result++;
                    i++;

                    if(i == posts_arr_size){
                        break;
                    }
                }
        }
    }
    return result;
}

void printPostsByYear(Post posts[], string year, int num_posts_stored){
    //If the number of posts stored in the array is 0 or less, print "No posts are stored";
    if(num_posts_stored <= 0){
        cout << "No posts are stored" << endl;
    }

    else{
        int size = 3;
        string arr[size];
        char separator = '/';
        bool validYear = false;

        for(int i = 0; i < num_posts_stored; i++){
            //Take the year of the post by using the split function on the post date string;
            split(posts[i].getPostDate(), separator, arr, size);

            //Verify if the year of the post is the same as the year chosen by the user;
            if(arr[2] == year){
                validYear = true;
            }
        }

        //If there are any posts matching the year chosen by the user, print all posts that apply;
        if(validYear == true){
            cout  << "Here is a list of posts for year " << year << endl;

            for(int i = 0; i < num_posts_stored; i++){
                split(posts[i].getPostDate(), separator, arr, size);

                if(arr[2] == year){
                    cout << posts[i].getPostBody() << endl;
                }
            }
        }

        //If no matches are found, print "No posts stored for year <year>";
        else{
            cout << "No posts stored for year " << year << endl;
        }
    }
}

int main(){
// no posts stored with numberOfPosts 0
Post list_Posts[] = {};
int number_Posts = 0;
string year = "20";
printPostsByYear(list_Posts, year, number_Posts);

// two posts released in year 22
Post p1 = Post("new post1","Lisa1", 10, "10/02/22");
Post p2 = Post("new post2","Lisa2", 10, "10/02/22");
Post p3 = Post("new post3","Lisa3", 10, "10/02/19");
Post list_Posts[] = {p1, p2, p3};
int number_Posts = 3;
string year = "22";
printPostsByYear(list_Posts, year, number_Posts);

	
// all posts released in year 22
Post p1 = Post("new post1","Lisa1", 10, "10/02/22");
Post p2 = Post("new post2","Lisa2", 10, "10/02/22");
Post p3 = Post("new post3","Lisa3", 10, "10/02/22");
Post list_Posts[] = {p1, p2, p3};
int number_Posts = 3;
string year = "22";
printPostsByYear(list_Posts, year, number_Posts);

// no posts released in year 21
Post p1 = Post("new post1","Lisa1", 10, "10/02/22");
Post p2 = Post("new post2","Lisa2", 10, "10/02/22");
Post p3 = Post("new post3","Lisa3", 10, "10/02/22");
Post list_Posts[] = {p1, p2, p3};
int number_Posts = 3;
string year = "21";
printPostsByYear(list_Posts, year, number_Posts);
}