#include <iostream>
#include <fstream>
#include <string>
#include "Buffchat.h"
using namespace std;

//Prints the menu;
void printMenu(){
    cout << "======Main Menu=====" << endl;
    cout << "1. Read posts" << endl;
    cout << "2. Print Posts By Year" << endl;
    cout << "3. Read Likes" << endl;
    cout << "4. Get Likes" << endl;
    cout << "5. Find users with matching tag" << endl;
    cout << "6. Add a new post" << endl;
    cout << "7. Print popular posts for a year" << endl;
    cout << "8. Find least active user" << endl;
    cout << "9. Find unique likes for a post author" << endl;
    cout << "10. Quit" << endl;
}

//Takes and verifies the user's input. If the input isn't between 1-10, prompts the menu again;
int checkInput(){
    string userInputStr;
    getline(cin, userInputStr);

    int userInput = stoi(userInputStr);

    while(userInput <= 0 || userInput > 10){
        cout << "Invalid input" << endl;
        printMenu();
        getline(cin, userInputStr);

        userInput = stoi(userInputStr);
    }
    return userInput;
}

int main(){
    Buffchat a = Buffchat(); //Creates the Buffchat object to be used in the program;

    printMenu();
    int userChoice = checkInput();

    //Continue prompting the menu to the user if they don't choose 10;
    while(userChoice != 10){
        switch(userChoice){
            //If the user chooses 1, ask for the file name to be used in the "readPosts" function;
            case 1:{
                cout << "Enter a post file name: " << endl;
                string filename;
                getline(cin, filename);

                int result = a.readPosts(filename);

                switch(result){
                    //If "readPosts" returns -1, print "File failed to open. No posts saved to the database.";
                    case -1:
                        cout << "File failed to open. No posts saved to the database." << endl;
                        break;
                    
                    //If "readPosts" returns -2, print "Database is already full. No posts were added.";
                    case -2:
                        cout << "Database is already full. No posts were added." << endl;
                        break;

                    default:
                        //If "readPosts" returns a number equal to the size of the posts array, print "Database is full. Some posts may have not been added.";
                        if(result == a.getPostSize()){
                            cout << "Database is full. Some posts may have not been added." << endl;
                        }

                        //If "readPosts" returns a number that is greater or equal to 0 and less than the size of the posts array, print "Total posts in the database: <result>";
                        else if(result >= 0 && result < a.getPostSize()){
                            cout << "Total posts in the database: " << result << endl;
                        }
                        break;
                }
                printMenu();
                userChoice = checkInput();
                break;
            }

            //If the user chooses 2, ask for the year to be used in the "printPostsByYear" function;
            case 2:{
                cout << "Enter the year(YY):" << endl;
                string inputYear;
                getline(cin, inputYear);

                a.printPostsByYear(inputYear);

                printMenu();
                userChoice = checkInput();
                break;
            }
            
            case 3:{
                //If the user chooses 3, ask for the file name to be used in the "readLikes" function;
                cout << "Enter a user file name:" << endl;
                string filename;
                getline(cin, filename);

                int result = a.readLikes(filename);

                switch(result){
                    //If "readLikes" returns -1, print "File failed to open. No users saved to the database.";
                    case -1:
                        cout << "File failed to open. No users saved to the database." << endl;
                        break;

                    //If "readLikes" returns -2, print "Database is already full. No users were added.";
                    case -2:
                        cout << "Database is already full. No users were added." << endl;
                        break;
                    
                    default:
                        //If "readLikes" returns a number equal to the size of the users array, print "Database is full. Some users may have not been added.";
                        if(result == a.getUserSize()){
                            cout << "Database is full. Some users may have not been added." << endl;
                        }

                        //If "readLikes" returns a number that is greater or equal to 0 and less than the size of the users array, print "Total users in the database: <result>";
                        else if(result >= 0 && result < a.getUserSize()){
                            cout << "Total users in the database: " << result << endl;
                        }
                        break;
                }

                printMenu();
                userChoice = checkInput();
                break;
            }

            case 4:{
                //If the user chooses 4, ask for the post author and username to be used in the "getLikes" function;
                cout << "Enter a post author:" << endl;
                string inputAuthor;
                getline(cin, inputAuthor);

                cout << "Enter a user name:" << endl;
                string inputUsername;
                getline(cin, inputUsername);

                int result = a.getLikes(inputAuthor, inputUsername);

                switch(result){
                    //If "getLikes" returns 0, print "<username> has not liked the post posted by <author>";
                    case 0:
                        cout << inputUsername << " has not liked the post posted by " << inputAuthor << endl;
                        break;
                    
                    //If "getLikes" returns -1, print "<username> has not viewed the post posted by <author>";
                    case -1:
                        cout << inputUsername << " has not viewed the post posted by " << inputAuthor << endl;
                        break;

                    //If "getLikes" returns -2, print "Database is empty.";
                    case -2:
                        cout << "Database is empty." << endl;
                        break;

                    //If "getLikes" returns -3, print "<username> or <author> does not exist.";
                    case -3:
                        cout << inputUsername << " or " << inputAuthor << " does not exist." << endl;
                        break;

                    //Otherwise, print "<username> liked the post posted by <author> <result> times";
                    default:
                        cout << inputUsername << " liked the post posted by " << inputAuthor << " " << result << " times." << endl;
                        break;
                }
                printMenu();
                userChoice = checkInput();
                break;
            }
            
            case 5:{
                //If the user chooses 5, ask for the tag to be used in "findTagUser" and run the function with this parameter;
                cout << "Enter a tag:" << endl;
                string inputTag;
                getline(cin, inputTag);

                a.findTagUser(inputTag);

                printMenu();
                userChoice = checkInput();
                break;
            }

            case 6:{
                //If the user chooses 6, aks for the body, author, and date of the post to be used in "addPost";
                cout << "Enter a post body:" << endl;
                string inputBody;
                getline(cin, inputBody);

                cout << "Enter a post author:" << endl;
                string inputAuthor;
                getline(cin, inputAuthor);

                cout << "Enter a date(mm/dd/yy):" << endl;
                string inputDate;
                getline(cin, inputDate);

                int result = a.addPost(inputBody, inputAuthor, inputDate);

                switch(result){
                    //If "addPost" returns 1, print "<author>'s post added successfully";
                    case 1:
                        cout << inputAuthor << "'s post added successfully" << endl;
                        break;
                    
                    //If "addPost" returns 0, print "Database already full. <author>'s post was not added";
                    case 0:
                        cout << "Database is already full. " << inputAuthor << "'s post was not added" << endl;
                        break;
                }

                printMenu();
                userChoice = checkInput();
                break;
            }

            case 7:{
                //If the user chooses 7, ask for the number of posts and the year to be used in the "printPopularPosts" function, then run it with these parameters;
                cout << "Enter the number of posts:" << endl;
                string inputNumberStr;
                getline(cin, inputNumberStr);

                cout << "Enter the year(YY):" << endl;
                string inputYear;
                getline(cin, inputYear);

                int inputNumber = stoi(inputNumberStr);

                a.printPopularPosts(inputNumber, inputYear);

                printMenu();
                userChoice = checkInput();
                break;
            }
            
            case 8:{
                //If the user chooses 8, run the "findLeastActiveUser" function with the current database;
                User result = a.findLeastActiveUser();

                //If "findLeastActiveUser" returns an empty User, print "Database is empty.";
                if(result.getUsername() == ""){
                    cout << "Database is empty." << endl;
                }

                //Otherwise, print the username of the User returned by "findLeastActiveUser";
                else{
                    cout << result.getUsername() << " is the least active user" << endl;
                }

                printMenu();
                userChoice = checkInput();
                break;
            }
            
            case 9:{
                //If the user chooses 9, ask for the author to be used in the "countUniqueLikes" function;
                cout << "Enter a post author:" << endl;
                string inputAuthor;
                getline(cin, inputAuthor);

                int result = a.countUniqueLikes(inputAuthor);

                switch(result){
                    //If "countUniqueLikes" returns 0, print "The posts posted by <author> have received 0 likes so far";
                    case 0:
                        cout << "The posts posted by " << inputAuthor << " have received 0 likes so far." << endl;
                        break;

                    //If "countUniqueLikes" returns -1, print "The posts posted by <author> have not been viewed by anyone";
                    case -1:
                        cout << "The posts posted by " << inputAuthor << " have not been viewed by anyone." << endl;
                        break;

                    //If "countUniqueLikes" returns -2, print "Database is empty.";
                    case -2:
                        cout << "Database is empty." << endl;
                        break;

                    //Otherwise, print "The posts posted by <author> have been liked by <result> unique users";
                    default:
                        cout << "The posts posted by " << inputAuthor << " have been liked by " << result << " unique users." << endl;
                        break;
                }

                printMenu();
                userChoice = checkInput();
                break;
            }
        }   
    }
    //When the user finally chooses 10, print "Good bye!";
    cout << "Good bye!" << endl;
}