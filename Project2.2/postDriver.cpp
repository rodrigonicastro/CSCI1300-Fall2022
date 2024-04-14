#include <iostream>
#include "Post.h"
using namespace std;

int main(){
    Post post1 = Post();
    cout << "Post Author: " << post1.getPostAuthor() << endl;
    cout << "Post Body: " << post1.getPostBody() << endl;
    cout << "Post Likes: " << post1.getPostLikes() << endl;
    cout << "Post Date: " << post1.getPostDate() << endl;

    Post post2 = Post("Hello, World!", "Rodrigo", 10, "10/18/22");
    cout << "Post Author: " << post2.getPostAuthor() << endl;
    cout << "Post Body: " << post2.getPostBody() << endl;
    cout << "Post Likes: " << post2.getPostLikes() << endl;
    cout << "Post Date: " << post2.getPostDate() << endl;
}