#include <iostream>
#include <string>
#include <fstream>
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
            arr[x + 1] = piece.assign(input_string, y + n + 1, input_string_length - n - 1);

            x++;
            y = i + 1;
            n = -1;
            result++;

            if(x > arr_size){
                result = -1;
                break;
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

int readPosts(string filename){
    int result;
    string line;
    int size = 3;
    string arr[size];
    char separator = ',';

    ifstream fin;

    fin.open(filename);

    if(fin.fail()){
        result = -1;
    }

    else{
        result = 0;

        while(!fin.eof()){
            getline(fin, line);

            if(split(line, separator, arr, size) == 3){
                result++;
            }
        }
    }
    return result;
}

int main(){
    string file_name = "posts.txt";
    int num_posts = readPosts(file_name);

    if(num_posts == -1){
        cout << "Could not open file." << endl;
    }

    else{
        cout << "Number of posts: " << num_posts << endl;
    }
}