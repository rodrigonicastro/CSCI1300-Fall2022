#include <iostream>
#include <fstream>
#include <string>
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

int readRestaurantData(string filename, string restaurants[], int ratings[][3], int arrSize){
    int num_restaurants;
        
    ifstream fin;

    fin.open(filename);

    if(fin.fail()){
        num_restaurants = -1;
    }

    else{
        int i = 0;
        string line;
            
        while(i < arrSize){
            getline(fin, line);
            int splitSize = 4;
            string arr[splitSize];

            int splitResult = split(line, '~', arr, splitSize);

            if(splitResult == 4){
                restaurants[i] = arr[0];
                ratings[0][i] = stoi(arr[1]);
                ratings[1][i] = stoi(arr[2]);
                ratings[2][i] = stoi(arr[3]);
                //cout << "Restaurant: " << restaurants[i] << " - Ratings: " << ratings[0][i] << " " << ratings[1][i] << " " << ratings[2][i] << endl;

                num_restaurants++;
                i++;
            }
        }
    }
    return num_restaurants;
}

int main(){
    string filename = "restaurant_samples.txt";
    int num_restaurants = 4;
    string restaurants[num_restaurants];
    int ratings[num_restaurants][3];

    int result = readRestaurantData(filename, restaurants, ratings, num_restaurants);

    if(result == -1){
        cout << "Could not open file." << endl;
    }

    else{
        cout << "Number of lines: " << num_restaurants << endl;
        for(int i = 0; i < num_restaurants; i++){
            cout << "names[" << i << "]: " << restaurants[i] << endl;
        }

        for(int i = 0; i < num_restaurants; i++){
            cout << "food quality: " << ratings[0][i] << " / 10, cleanliness: " << ratings[1][i] << " / 5, wait time: " << ratings[2][i] << " / 5" << endl;
        }
    }
}