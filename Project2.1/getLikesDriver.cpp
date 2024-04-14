#include <iostream>
#include <fstream>
#include <string>
#include "User.h"
#include "Post.h"
using namespace std;

int getLikes(string post_author, Post posts[], int num_posts_stored, string username, User users[], int num_users_stored){
    int result;
    int user_id;
    int post_id;
    bool validUser = false;
    bool validAuthor = false;

    if(num_posts_stored <= 0 || num_users_stored <= 0){
        result = -2;
    }

    else{
        for(int i = 0; i < num_posts_stored; i++){
            char separator = ',';
            int size = 4;
            string arr[size];

            //Verifies if the author inputted by the user is valid;
            if(post_author == posts[i].getPostAuthor()){
                validAuthor = true;
                post_id = i;
                break;
            }
        }

        for(int i = 0; i < num_users_stored; i++){
            char separator = ',';
            int size = 50;
            string arr[size];

            //Verifies if the username inputted by the user is valid;
            if(username == users[i].getUsername()){
                validUser = true;
                user_id = i;
                break;
            }
        }

        //If the author or username inputted by the user aren't valid, return -3;
        if(validAuthor == false || validUser == false){
            result = - 3;
        }

        //If the author and username inputted by the user are valid, take the number of likes for that author and username;
        else{
            result = users[user_id].getLikesAt(post_id);
        }
    }
    return result;
}

int main(){
//username and post_author exist, non zero likes
string post_author = "susanfrances";
num_posts_stored = 7;
string username = "chipthebuffalo";
num_users_stored = 5;

cout << getLikes(post_author, posts, num_posts_stored, username, users, num_users_stored)<<endl;

	
// // username and post_author exist, zero likes
// string post_author = "Layla";
// num_posts_stored = 7;
// string username = "kate128";
// num_users_stored = 5;

// cout << getLikes(post_author, posts, num_posts_stored, username, users, num_users_stored)<<endl;

	
// // username does not exist
// string post_author = "Layla";
// num_posts_stored = 7;
// string username = "cubuffs";
// num_users_stored = 5;

// cout << getLikes(post_author, posts, num_posts_stored, username, users, num_users_stored)<<endl;

	
// // post_author does not exist
// string post_author = "amazedOtter4";
// num_posts_stored = 7;
// string username = "cuboulderalumni";
// num_users_stored = 5;

// cout << getLikes(post_author, posts, num_posts_stored, username, users, num_users_stored)<<endl;

	
// // both username and post_author do not exist
// string post_author = "amazedOtter4";
// num_posts_stored = 7;
// string username = "cubuffs";
// num_users_stored = 5;

// cout << getLikes(post_author, posts, num_posts_stored, username, users, num_users_stored)<<endl;

	
// // 0 users in the array
// string post_author = "Layla";
// num_posts_stored = 7;
// string username = "kate128";
// num_users_stored = 0;

// cout << getLikes(post_author, posts, num_posts_stored, username, users, num_users_stored)<<endl;

// // 0 posts in the array
// string post_author = "Layla";
// num_posts_stored = 0;
// string username = "kate128";
// num_users_stored = 5;

// cout << getLikes(post_author, posts, num_posts_stored, username, users, num_users_stored)<<endl;
}