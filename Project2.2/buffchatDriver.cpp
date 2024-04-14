#include <iostream>
#include <fstream>
#include <string>
#include "Buffchat.h"
using namespace std;

int main(){
    cout << "Testing readPosts" << endl;
        //Invalid File
            Buffchat test = Buffchat();
            cout << "  Invalid file test - readPosts returned: " << test.readPosts("doesnotexist.txt") << endl; 
        
        //Valid File, 50 posts
            Buffchat test1 = Buffchat();
            cout << "  0 posts test - readPosts returned: " << test1.readPosts("posts.txt") << endl;
        
        //Valid File, 50 posts (missing lines)
            Buffchat test2 = Buffchat();
            cout << "  50 posts + missing lines test - readPosts returned: " << test2.readPosts("posts2.txt") << endl;

        //Valid File, 20 posts
            Buffchat test3 = Buffchat();
            cout << "  20 posts test - readPosts returned: " << test3.readPosts("posts3.txt") << endl;

        //Empty File
            Buffchat test4 = Buffchat();
            cout << "  Empty file test - readPosts returned: " << test4.readPosts("posts4.txt") << endl;

    cout << "Testing printPostsByYear" << endl;
        //Invalid year 
            Buffchat test5 = Buffchat();
            test5.readPosts("posts.txt");
            cout << "  Invalid year format test - printPostsByYear returned: "; test5.printPostsByYear("10");
        
        //Valid year, 8 posts
            Buffchat test6 = Buffchat();
            test6.readPosts("posts.txt");
            cout << "  Valid year, 8 posts test - printPostsByYear returned: " << endl; test6.printPostsByYear("18");

        //No posts stored
            Buffchat test7 = Buffchat();
            cout << "  Empty database test - printPostsByYear returned: "; test7.printPostsByYear("22");

    cout << "Testing readLikes" << endl;
        //Invalid File
            Buffchat test8 = Buffchat();
            cout << "  Invalid file test - readLikes returned: " << test8.readLikes("doesnotexist.txt") << endl; 
        
        //Valid File, 50 users
            Buffchat test9 = Buffchat();
            cout << "  50 users test - readLikes returned: " << test9.readLikes("posts.txt") << endl;
        
        //Valid File, 50 users (missing lines)
            Buffchat test10 = Buffchat();
            cout << "  50 users + missing lines test - readLikes returned: " << test10.readLikes("users2.txt") << endl;

        //Valid File, 20 users
            Buffchat test11 = Buffchat();
            cout << "  20 users test - readLikes returned: " << test11.readLikes("users3.txt") << endl;

        //Empty File
            Buffchat test12 = Buffchat();
            cout << "  Empty file test - readLikes returned: " << test12.readLikes("users4.txt") << endl;

    cout << "Testing getLikes" << endl;
        //Invalid Author, Valid User
            Buffchat test13 = Buffchat();
            test13.readPosts("posts.txt");
            test13.readLikes("users.txt");
            cout << "  Invalid Author, Valid User test - getLikes returned: " << test13.getLikes("thisAuthorDoesNotExist", "michelleryan") << endl;
        
        //Valid Author, Invalid User
            Buffchat test14 = Buffchat();
            test14.readPosts("posts.txt");
            test14.readLikes("users.txt");
            cout << "  Valid Author, Invalid User test - getLikes returned: " << test14.getLikes("cubuffs", "thisUserDoesNotExist") << endl;

        //Valid Author, Valid User
            Buffchat test15 = Buffchat();
            test15.readPosts("posts.txt");
            test15.readLikes("users.txt");
            cout << "  Valid Author, Valid User test - getLikes returned: " << test15.getLikes("cubuffs", "michelleryan") << endl;

        //Empty Database
            Buffchat test16 = Buffchat();
            cout << "  Empty Database test - getLikes returned: " << test16.getLikes("cubuffs", "michelleryan") << endl;

    cout << "Testing findTagUser" << endl;
        //Invalid Tag
            Buffchat test17 = Buffchat();
            test17.readPosts("posts.txt");
            test17.readLikes("users.txt");
            cout << "  Invalid Tag test - findTagUser returned: "; test17.findTagUser("invalid");

        //Valid Tag, multiple users
            Buffchat test18 = Buffchat();
            test18.readPosts("posts.txt");
            test18.readLikes("users.txt");
            cout << "  Valid Tag, multiple users test - findTagUser returned: " << endl; test18.findTagUser("cu");

        //Valid Tag, only 1 user
            Buffchat test19 = Buffchat();
            test19.readPosts("posts.txt");
            test19.readLikes("users.txt");
            cout << "  Valid Tag, only 1 user test - findTagUser returned: " << endl; test19.findTagUser("128");

        //Empty Database
            Buffchat test20 = Buffchat();
            cout << "  Empty Database test - findTagUser returned: "; test20.findTagUser("cu");
            
    cout << "Testing addPost" << endl;
        //Success
            Buffchat test21 = Buffchat();
            cout << "  Success test - addPost returned: " << test21.addPost("test", "Rodrigo", "10/30/22") << endl;

        //Fail (database full)
            Buffchat test22 = Buffchat();
            test22.readPosts("posts.txt");
            cout << "  Fail (database full) test - addPost returned: " << test22.addPost("test", "Rodrigo", "10/30/22") << endl;

    cout << "Testing printPopularPosts" << endl;
        //Invalid Year
            Buffchat test23 = Buffchat();
            test23.readPosts("posts.txt");
            cout << "  Invalid Year test - printPopularPosts returned: "; test23.printPopularPosts(5, "10");

        //Valid Year, more posts than <count>
            Buffchat test24 = Buffchat();
            test24.readPosts("posts.txt");
            cout << "  Valid Year, more posts than <count> test - printPopularPosts returned: " << endl; test24.printPopularPosts(5, "18");

        //Valid Year, less posts than <count>
            Buffchat test25 = Buffchat();
            test25.readPosts("posts.txt");
            cout << "  Valid Year, less posts than <count> test - printPopularPosts returned: " << endl; test25.printPopularPosts(10, "18");

        //Valid Year, posts equal to <count>
            Buffchat test26 = Buffchat();
            test26.readPosts("posts.txt");
            cout << "  Valid Year, posts equal to <count> test - printPopularPosts returned: " << endl; test26.printPopularPosts(8, "18");

        //Empty Database
            Buffchat test27 = Buffchat();
            cout << "  Empty Database test - printPopularPosts returned: "; test27.printPopularPosts(8, "18");

    cout << "Testing countUniqueLikes" << endl;
        //Invalid Author
            Buffchat test28 = Buffchat();
            test28.readPosts("posts.txt");
            test28.readLikes("users.txt");
            cout << "  Invalid Author test - countUniqueLikes returned: " << test28.countUniqueLikes("thisAuthorDoesNotExist") << endl;

        //Sucess
            Buffchat test29 = Buffchat();
            test29.readPosts("posts.txt");
            test29.readLikes("users.txt");
            cout << "  Sucess test - countUniqueLikes returned: " << test29.countUniqueLikes("michelleryan") << endl;

        //Empty User Database
            Buffchat test30 = Buffchat();
            test29.readPosts("posts.txt");
            cout << "  Empty User Database test - countUniqueLikes returned: " << test30.countUniqueLikes("cubuffs") << endl;

        //Empty Post Database
            Buffchat test31 = Buffchat();
            test29.readLikes("users.txt");
            cout << "  Empty Post Database test - countUniqueLikes returned: " << test31.countUniqueLikes("cubuffs") << endl;

        //Empty User and Post Database
            Buffchat test32 = Buffchat();
            cout << "  Empty User and Post Database test - countUniqueLikes returned: " << test32.countUniqueLikes("cubuffs") << endl;

    cout << "Testing findLeastActiveUser" << endl;
        //Sucess
            Buffchat test33 = Buffchat();
            test33.readLikes("users.txt");
            cout << "  Sucess test - findLeastActiveUser returned: " << test33.findLeastActiveUser().getUsername() << endl;

        //Empty Database
            Buffchat test34 = Buffchat();
            cout << "  Empty Database test - findLeastActiveUser returned: " << test34.findLeastActiveUser().getUsername() << endl;
}