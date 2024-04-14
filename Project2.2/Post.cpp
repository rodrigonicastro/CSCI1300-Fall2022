#include <iostream>
#include "Post.h"
using namespace std;

Post::Post(){
    body_ = "";
    post_author_ = "";
    date_ = "";
    num_likes_ = 0;
}

Post::Post(string inputBody, string inputAuthor, int inputLikes, string inputDate){
    body_ = inputBody;
    post_author_ = inputAuthor;
    num_likes_ = inputLikes;
    date_ = inputDate;
}

string Post::getPostBody(){
    return body_;
}

string Post::getPostAuthor(){
    return post_author_;
}

int Post::getPostLikes(){
    return num_likes_;
}

string Post::getPostDate(){
    return date_;
}

void Post::setPostBody(string inputBody){
    body_ = inputBody;
}

void Post::setPostAuthor(string inputAuthor){
    post_author_ = inputAuthor;
}

void Post::setPostLikes(int inputLikes){
    if(inputLikes >= 0){
        num_likes_ = inputLikes;
    }
}

void Post::setPostDate(string inputDate){
    date_ = inputDate;
}