#include <iostream>
using namespace std;

class User{
    private:
        string username_;
        int size_ = 50;
        int num_posts_;
        int likes_[50];

    public:
        User();
        User(string, int[], int);
        string getUsername();
        int getLikesAt(int);
        int getNumPosts();
        int getSize();
        void setUsername(string);
        bool setLikesAt(int, int);
        void setNumPosts(int);
};