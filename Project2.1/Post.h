#include <iostream>
using namespace std;

class Post{
    private:
        string body_;
        string post_author_;
        int num_likes_;
        string date_;

    public:
        Post();
        Post(string, string, int, string);
        string getPostBody();
        string getPostAuthor();
        int getPostLikes();
        string getPostDate();
        void setPostBody(string);
        void setPostAuthor(string);
        void setPostLikes(int);
        void setPostDate(string);
};