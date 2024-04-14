#include <iostream>
#include "User.h"
#include "Post.h"
using namespace std;

class Buffchat{
    private:
        static const int posts_size_ = 50;
        static const int users_size_ = 50;
        Post posts[posts_size_];
        User users[users_size_];
        int num_posts_;
        int num_users_;

    public:
        Buffchat();
        int getPostSize();
        int getUserSize();
        int getNumPosts();
        int getNumUsers();
        int readPosts(string);
        void printPostsByYear(string);
        int readLikes(string);
        int getLikes(string, string);
        void findTagUser(string);
        bool addPost(string, string, string);
        void printPopularPosts(int, string);
        int countUniqueLikes(string);
        User findLeastActiveUser();
};