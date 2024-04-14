#include <iostream>
#include "User.h"
using namespace std;

User::User(){
    username_ = "";

    for(int i = 0; i < size_; i++){
        likes_[i] = -1;
    }

    num_posts_ = 0;
}

User::User(string inputUsername, int inputArr[], int arrSize){
    username_ = inputUsername;
    
    if(arrSize < size_){
        int i = 0;

        while(i < arrSize){
            likes_[i] = inputArr[i];
            i++;
        }

        while(i < size_){
            likes_[i] = -1;
            i++;
        }
    }

    else if(arrSize == size_){
        for(int i = 0; i < size_; i++){
            likes_[i] = inputArr[i];
        }
    }

    num_posts_ = arrSize;
}

string User::getUsername(){
    return username_;
}

int User::getLikesAt(int post_id){
    int result;
    
    if(post_id < 0 || post_id >= size_){
        result = -2;
    }

    else{
        result = likes_[post_id];
    }

    return result;
}

int User::getNumPosts(){
    return num_posts_;
}

int User::getSize(){
    return size_;
}

void User::setUsername(string inputUsername){
        username_ = inputUsername;
}

bool User::setLikesAt(int post_id, int inputLikes){
    bool result = false;

    if(post_id >= 0 && post_id < num_posts_ && inputLikes >= -1 && inputLikes <= 10){
        likes_[post_id] = inputLikes;
        result = true;
    }
    return result;
}

void User::setNumPosts(int inputPosts){
    if(inputPosts > 0 && inputPosts < 50){
        num_posts_ = inputPosts;
    }
}