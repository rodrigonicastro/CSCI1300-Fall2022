#include <iostream>
#include <fstream>
#include <string>
#include "User.h"
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

int readLikes(string file_name, User users[], int num_users_stored, int users_arr_size, int max_posts){
    int result;
    
    //If the likes array is already full, return -2;
    if(num_users_stored == users_arr_size){
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
            int i = num_users_stored;

            while(!fin.eof()){
                string line;
                
                while(num_users_stored < users_arr_size){    
                    char separator = ',';
                    int size = max_posts + 1;
                    string arr[size];

                    //Assign the current line of the file to a string "line";
                    getline(fin, line);
                
                    //Makes sure the current line can be successfully split;
                    if(split(line, separator, arr, size) != 1 || split(line, separator, arr, size) != 0){
                        int x = 0;
                        int y = 1;
                        string username = arr[0];
                        int likesArr_size = users[i].getNumPosts();
                        int likesArr[likesArr_size];

                        //Adjusts the variable "max_posts" if needed;
                        if(max_posts > likesArr_size){
                             max_posts = likesArr_size;
                        }

                        //Assigns a value of likes to each element of the array;
                        while(x < max_posts){
                            int likesAtX = stoi(arr[y]);
                            likesArr[x] = likesAtX;

                            x++;
                            y++;
                        }

                        //Declares an element of the User class with the current parameters;
                        users[i] = {User(username, likesArr, likesArr_size)};

                        if(i > 0){
                            //If the current line is the same as the previous, meaning the loop is stuck at the last line of the file, breakes the loop;
                            if(users[i].getUsername() == users[i - 1].getUsername()){
                                users[i] = {User()};
                                break;
                            }
                        }
                        
                        i++;
                        num_users_stored++;
                    }                 
                }
                break;
            }
            result = num_users_stored;
        }
    }
    return result;
}

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

void findTagUser(string username_tag, User users[], int num_users_stored){
    bool validTag = false;

    if(num_users_stored <= 0){
        cout << "No users are stored in the database" << endl;
    }

    else{
        for(int i = 0; i < num_users_stored; i++){
            int tagLength = username_tag.length();
            string username = users[i].getUsername(); //Assigns the current username in the array to the string "username";
            int usernameLength = username.length();
            string piece;
        
            //Verifies if the tag inputted by the user matches the current username;
            for(int n = 0; n < usernameLength; n++){
                piece.assign(username, n, tagLength);

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

            for(int i = 0; i < num_users_stored; i++){
                int tagLength = username_tag.length();
                string username = users[i].getUsername();
                int usernameLength = username.length();
                string piece;
        
                for(int n = 0; n < usernameLength; n++){
                    piece.assign(username, n, tagLength);

                    if(piece == username_tag){
                        cout << username << endl;
                    }
                }
            }
        }
    }
}

//Prints the menu;
void printMenu(){
    cout << "======Main Menu======" << endl;
    cout << "1. Read Posts" << endl;
    cout << "2. Print Posts By Year" << endl;
    cout << "3. Read Likes" << endl;
    cout << "4. Get Likes" << endl;
    cout << "5. Find users with matching tag" << endl;
    cout << "6. Quit" << endl;    
}

//Takes and verifies the user's input. If the input isn't between 1-6, prompts the menu again;
int checkInput(){
    int userInput;
    cin >> userInput;

    while(userInput <= 0 || userInput > 6){
        cout << "Invalid input." << endl;
        printMenu();
        cin >> userInput;
    }
    return userInput;
}

int main(){
    Post posts[50];
    User users[50];

    int num_posts_stored = 0;
    int num_users_stored = 0;
    int posts_arr_size = 50;
    int users_arr_size = 50;
    int max_posts = 50;

    printMenu();
    int userChoice = checkInput();

    while(userChoice != 6){ //Prompts the menu to the user until they select 6;
        switch(userChoice){
            case 1:{
                //Takes a posts file;
                cout << "Enter a post file name:" << endl;
                string filename;
                cin >> filename;

                //Runs the function "readPosts" with the current parameters;
                int result = readPosts(filename, posts, num_posts_stored, posts_arr_size);

                switch(result){
                    //If the result of the function "readPosts" is -1, print "File failed to open. No posts saved to the database.";
                    case -1:
                        cout << "File failed to open. No posts saved to the database." << endl;
                        break;
                    
                    //If the result of the function "readPosts" is -2, print "Database is already full. No posts were added.";
                    case -2:
                        cout << "Database is already full. No posts were added." << endl;
                        break;
                    
                    default:
                        //If the result of the function "readPosts" equals the size of the posts array, print "Database is full. Some posts may have not been added."
                        if(result == posts_arr_size){
                            cout << "Database is full. Some posts may have not been added." << endl;
                            num_posts_stored = result;
                        } 

                        else{
                            //Otherwise, print the total number of posts in the database;
                            cout << "Total posts in the database: " << result << endl;
                            num_posts_stored = result;
                        }
                        break;
                }
                printMenu();
                userChoice = checkInput();
                break;
            }

            case 2:{
                //Takes the user's input for the year
                cout << "Enter the year(YY):" << endl;
                string inputYear;
                cin >> inputYear;

                //Runs the "printPostsByYear" function with the current paremeters;
                printPostsByYear(posts, inputYear, num_posts_stored);

                printMenu();
                userChoice = checkInput();
                break;
            }
            
            case 3:{
                //Takes a users file;
                cout << "Enter a user file name:" << endl;
                string filename;
                cin >> filename;

                //Runs the function "readLikes" with the current parameters;
                int result = readLikes(filename, users, num_users_stored, users_arr_size, max_posts);

                switch(result){
                    //If the result of the function "readLikes" is -1, print "File failed to open. No users saved to the database.";
                    case -1:
                        cout << "File failed to open. No users saved to the database." << endl;
                        break;
                    
                    //If the result of the function "readLikes" is -2, print "Database is already full. No users were added.";
                    case -2:
                        cout << "Database is already full. No users were added." << endl;
                        break;

                    default:
                    //If the result of the function "readLikes" equals the size of the posts array, print "Database is full. Some posts may have not been added."
                        if(result == users_arr_size){
                            cout << "Database is full. Some users may have not been added." << endl;
                            num_users_stored = result;
                        }

                        else{
                            //Otherwise, print the total number of users in the database;
                            cout << "Total users in the database: " << result << endl;
                            num_users_stored = result;
                        }
                        break;
                }
                printMenu();
                userChoice = checkInput();
                break;
            }

            case 4:{
                //Takes an author from the user;
                cout << "Enter a post author:" << endl;
                string inputAuthor;
                cin >> inputAuthor;

                //Takes a username from the user;
                cout << "Enter a user name:" << endl;
                string inputUsername;
                cin >> inputUsername;

                //Runs the function "getLikes with the current parameters";
                int result = getLikes(inputAuthor, posts, num_posts_stored, inputUsername, users, num_users_stored);

                switch(result){
                    //If the result of the function "getLikes" is -3, print "<username> or <author> does not exist." 
                    case -3:
                        cout << inputUsername << " or " << inputAuthor << " does not exist." << endl;
                        break;
                    
                    case -2:
                        //If the result of the function "readLikes" is -2, print "Database is empty";
                        cout << "Database is empty." << endl;
                        break;

                    case -1:
                        //If the result of the function "readLikes" is -1, print "<username has not viewed the post posted by <author>"
                        cout << inputUsername << " has not viewed the post posted by " << inputAuthor << endl;
                        break;

                    case 0:
                        //If the result of the function "readLikes" is 0, print "<username has not liked the post posted by <author>"
                        cout << inputUsername << " has not liked the post posted by author " << inputAuthor << endl;
                        break;

                    default:
                        //Otherwise, print the number of times <username> has liked the post by <author>
                        cout << inputUsername << " liked the post by " << inputAuthor << " " << result << " times." << endl;
                        break;
                }
                printMenu();
                userChoice = checkInput();
                break;
            }

            case 5:{
                //Takes a Tag from the user;
                cout << "Enter a tag:" << endl;
                string inputTag;
                cin >> inputTag;

                //Runs the function "findTagUser" with the current parameters;
                findTagUser(inputTag, users, num_users_stored);

                printMenu();
                userChoice = checkInput();
                break;
            }
        }
    }
    cout << "Good bye!" << endl;
}