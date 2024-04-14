#include <iostream>
#include <fstream>
#include "Buffchat.h"
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

Buffchat::Buffchat(){
    num_posts_ = 0;
    num_users_ = 0;
}

int Buffchat::getPostSize(){
    return posts_size_;
}

int Buffchat::getUserSize(){
    return users_size_;
}

int Buffchat::getNumPosts(){
    return num_posts_;
}

int Buffchat::getNumUsers(){
    return num_users_;
}

int Buffchat::readPosts(string file_name){
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
    else if(posts_size_ == num_posts_){
        result = -2;        
    }

    else{
        result = num_posts_;
        int i = num_posts_;

        while(!fin.eof()){
                //Assign a line of the file to a string "line";
                getline(fin, line);

                //If the line has all parameters of Post, declare an element of the Post class;
                if(split(line, separator, arr, size) == 4){
                    posts[i] = Post(arr[0], arr[1], stoi(arr[2]), arr[3]);
                
                    num_posts_++;
                    result++;
                    i++;

                    //Once the array has reached its size limit, break the loop;
                    if(i == posts_size_){
                        break;
                    }
                }
        }
    }
    return result;
}

void Buffchat::printPostsByYear(string year){
    //If the number of posts stored in the array is 0 or less, print "No posts are stored";
    if(num_posts_ <= 0){
        cout << "No posts are stored" << endl;
    }

    else{
        int yearNum = stoi(year);
        int size = 3;
        string arr[size];
        char separator = '/';
        bool validYear = false;

        for(int i = 0; i < num_posts_; i++){
            //Take the year of the post by using the split function on the post date string;
            split(posts[i].getPostDate(), separator, arr, size);

            //Verify if the year of the post is the same as the year chosen by the user;
            if(stoi(arr[2]) == yearNum){
                validYear = true;
            }
        }

        //If there are any posts matching the year chosen by the user, print all posts that apply;
        if(validYear == true){
            cout  << "Here is a list of posts for year " << year << endl;

            for(int i = 0; i < num_posts_; i++){
                split(posts[i].getPostDate(), separator, arr, size);

                if(stoi(arr[2]) == yearNum){
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

int Buffchat::readLikes(string file_name){
    int result;
    
    //If the likes array is already full, return -2;
    if(num_users_ == users_size_){
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
            int i = num_users_;
            string line;

            //Keep taking new lines until the end of the file (unless the users array has reached its limit);
            while(!fin.eof()){
                getline(fin, line);
                char separator = ',';
                int size = num_posts_ + 1;
                string arr[size];

                int splitResult = split(line, separator, arr, size);

                //Makes sure the line has all of the necessary elements;
                if(splitResult == size || splitResult == -1){
                    string username = arr[0];
                    users[i].setUsername(username);

                    //Assigns each like of the current line to the likes array in the User class;
                    for(int x = 0, y = 1; x < num_posts_; x++, y++){
                        users[i].setLikesAt(x, stoi(arr[y]));
                    }
                    
                    num_users_++;
                    i++;

                    //Breaks the loop if the users array has reached its limit;
                    if(num_users_ == users_size_){
                        break;
                    }
                }
            }
            result = num_users_;
        }
    }
    return result;
}

int Buffchat::getLikes(string post_author, string username){
    int result;
    int user_id;
    int post_id;
    bool validUser = false;
    bool validAuthor = false;

    //Returns -2 if the number of users or posts stored is 0 (or less than 0);
    if(num_posts_ <= 0 || num_users_ <= 0){
        result = -2;
    }

    else{
        for(int i = 0; i < num_posts_; i++){
            //Verifies if the author inputted by the user is valid;
            if(post_author == posts[i].getPostAuthor()){
                validAuthor = true;
                post_id = i;
                break;
            }
        }

        for(int i = 0; i < num_users_; i++){
            //Verifies if the username inputted by the user is valid;
            if(username == users[i].getUsername()){
                validUser = true;
                user_id = i;
                break;
            }
        }

        //If the author or username inputted by the user aren't valid, return -3;
        if(validAuthor == false || validUser == false){
            result = -3;
        }

        //If the author and username inputted by the user are valid, take the number of likes for that author and username;
        else{
            result = users[user_id].getLikesAt(post_id);
        }
    }
    return result;
}

void Buffchat::findTagUser(string username_tag){
    bool validTag = false;

    if(num_users_ <= 0){
        cout << "No users are stored in the database" << endl;
    }

    else{
        for(int i = 0; i < num_users_; i++){
            int tagLength = username_tag.length(); //Takes the length of the tag string;
            string username = users[i].getUsername(); //Assigns the current username in the array to the string "username";
            int usernameLength = username.length(); //Takes the length of the username string;
            string piece;
        
            //Verifies if the tag inputted by the user matches the current username;
            for(int n = 0; n < usernameLength; n++){
                piece.assign(username, n, tagLength); //Assigns a section of the string "username" to the string "piece";

                //Compares the string "piece" to the tag inputted by the user;
                if(piece == username_tag){
                    validTag = true;
                }
            }
        }

        //If there are no matches to the tag, print "No matching user found";
        if(validTag == false){
            cout << "No matching user found" << endl;
        }

        //If there are matches to the tag, print all usernames that apply;
        else{
            cout << "Here are all the usernames that contain " << username_tag << endl;

            for(int i = 0; i < num_users_; i++){
                int tagLength = username_tag.length(); //Takes the length of the tag string;
                string username = users[i].getUsername(); //Assigns the current username in the array to the string "username";
                int usernameLength = username.length(); //Takes the length of the username string;
                string piece;
        
                for(int n = 0; n < usernameLength; n++){
                    piece.assign(username, n, tagLength); //Assigns a section of the string "username" to the string "piece";

                    //Compares the string "piece" to the tag inputted by the user;
                    if(piece == username_tag){
                        cout << username << endl;
                    }
                }
            }
        }
    }
}

bool Buffchat::addPost(string post_body, string post_author, string date){
    bool result;

    //Returns false if the posts array is already full;
    if(num_posts_ == posts_size_){
        result = false;
    }

    //If there is space in the posts array, create a Post object with the parameters inputted by the user;
    else{
        posts[num_posts_] = Post(post_body, post_author, 0, date);
        num_posts_++;
        result = true;
    }
    return result;
}

void Buffchat::printPopularPosts(int count, string year){
    if(num_posts_ <=0){
        cout << "No posts are stored" << endl;
    }

    else{
        int yearNum = stoi(year);
        int numPostsForYear = 0;
        int size = 3;
        string arr[size];
        char separator = '/';
        bool validYear = false;

        //Verifies if there are any posts posted in the year inputted by the user;
        for(int i = 0; i < num_posts_; i++){
            split(posts[i].getPostDate(), separator, arr, size);

            if(stoi(arr[2]) == yearNum){
                validYear = true;
                numPostsForYear++;
            }
        }

        if(validYear == false){
            cout << "No posts stored for year " << year << endl;
        }

        //If the number of posts for <year> is the same as the input provided for <count>, print all posts in that year;
        else if(validYear == true && numPostsForYear == count){
            cout << "Top " << count << " posts for year " << year << endl;

            for(int i = 0; i < num_posts_; i++){
                split(posts[i].getPostDate(), separator, arr, size);

                if(stoi(arr[2]) == yearNum){
                    cout << posts[i].getPostLikes() << " likes: " << posts[i].getPostBody() << endl;
                }
            }
            

        }

        //If the number of posts for <year> is greater than the input provided for <count>, print only the ones with the most likes;
        else if(validYear == true && numPostsForYear > count){
            int n = 0;
            Post postsForYear[numPostsForYear];

            cout << "Top " << count << " posts for year " << year << endl;

            //Takes the post ID's for the posts posted in <year>;
            for(int i = 0; i < num_posts_; i++){
                split(posts[i].getPostDate(), separator, arr, size);

                if(stoi(arr[2]) == yearNum){
                    postsForYear[n] = posts[i];
                    n++;
                }
            }

        	int w = 0;
            for(int i = 0; i < numPostsForYear; i++){
                int y = 0;

                //Compares the number of likes for the current post to all of the other posts stored;
                for(int x = 0; x < numPostsForYear; x++){
                    if(postsForYear[i].getPostLikes() < postsForYear[x].getPostLikes()){
                        y++;
                    }
                }

                //If the current post was liked more than <count> other posts, print it;
                if(y < count){
                    cout << postsForYear[i].getPostLikes() << " likes: " << postsForYear[i].getPostBody() << endl;
                    w++;
                }

                //Breaks the loop when the number of posts printed equals <count>;
                if(w == count){
                    break;
                }
            }
        }

        //If the number of posts for <year> is less than <count>, print how many posts there are for <year> and print all of them;
        else if(validYear == true && numPostsForYear < count){
            cout << "There are fewer than " << count << " posts for year " << year << ". Top " << numPostsForYear << " posts for year " << year << endl;

            for(int i = 0; i < num_posts_; i++){
                    split(posts[i].getPostDate(), separator, arr, size);

                    if(stoi(arr[2]) == yearNum){
                        cout << posts[i].getPostLikes() << " likes: " << posts[i].getPostBody() << endl;
                    }
            }
        }
    }
}

User Buffchat::findLeastActiveUser(){

    //Returns an empty User object if the number of users stored is 0 (or less than 0);
    if(num_users_ <= 0){
        return User();
    }

    else{
        int userInactivity[num_users_];

        //Counts how many unviewed posts each user has and assigns this number to an "userInactivity" array;
        for(int i = 0; i < num_users_; i++){
            int unviewedPosts = 0;

            for(int n = 0; n < num_posts_; n++){
                if(users[i].getLikesAt(n) == -1){
                    unviewedPosts++;
                }
            }
            userInactivity[i] = unviewedPosts;
        }

        int mostInactiveID;
        int greatestInactivity = userInactivity[0];

        //Takes the greatest number stored in the "userInactivity" array;
        for(int i = 1; i < num_users_; i++){
            if(userInactivity[i] > greatestInactivity){
                greatestInactivity = userInactivity[i];
            }
        }

        int i = 0;

        //Takes the user ID for the number of unviewed posts found previously;
        while(i < num_users_){
            if(userInactivity[i] == greatestInactivity){
                mostInactiveID = i;
                break;
            }
            i++;
        }

        //Takes the username for the least active user;
        string leastActiveUsername = users[i].getUsername();
        int leastActiveLikes[num_posts_];

        //Assigns the least active user's likes to a separate array;
        for(int n = 0; n < num_posts_; n++){
            leastActiveLikes[n] = users[i].getLikesAt(n);
        }

        //Declares a new User object with the parameters found previously and returns it;
        User leastActive = User(leastActiveUsername, leastActiveLikes, num_posts_);

        return leastActive;
    }
}

int Buffchat::countUniqueLikes(string post_author){
    int unviewedPosts = 0;
    int result = 0;
    int postsByAuthor = 0;

    //Returns -2 if the number of posts or users stored is 0 (or less than 0);
    if(num_posts_ <= 0 || num_users_ <= 0){
        result = -2;
    }

    else{
        //Counts how many posts the author inputted by the user has posted;
        for(int i = 0; i < num_posts_; i++){
            if(posts[i].getPostAuthor() == post_author){
                postsByAuthor++;
            }
        }

        int postsIDs[postsByAuthor];
        int x = 0;
        int y = 0;

        //Takes the post ID's for each post posted by <post_author> and assigns it to an array "postsIDs";
        while(x < postsByAuthor){
            if(posts[y].getPostAuthor() == post_author){
                postsIDs[x] = y;
                x++;
            }
            y++;
        }

        //Counts how many users have not yet viewed the post by <post_author>;
        for(int n = 0; n < postsByAuthor; n++){
            for(int u = 0; u < num_users_; u++){
                if(users[u].getLikesAt(postsIDs[n]) == -1){
                    unviewedPosts++;
                }
            }
        }

        //If no users have viewed the posts by <post_author>, return -1;
        if(unviewedPosts == num_users_){
            result = -1;
        }

        else{
            //Count how many users have liked the posts by <post_author>;
            for(int n = 0; n < postsByAuthor; n++){
                for(int u = 0; u < num_users_; u++){
                    if(users[u].getLikesAt(postsIDs[n]) != 0 && users[u].getLikesAt(postsIDs[n]) != -1){
                        result++;
                    }
                }
            }
        }
    }
    return result;
}