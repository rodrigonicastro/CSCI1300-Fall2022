#include <iostream>
#include <fstream>
using namespace std;

int main(){
    cout << "Enter the input filenames that you want to concatenate:" << endl;
    string file1Name;
    cin >> file1Name;
    string file2Name;
    cin >> file2Name;

    cout << "Enter the output filename:" << endl;
    string outputName;
    cin >> outputName;

    ifstream file1Name(file1Name);
    

        if(file1Name.fail()){
            cout << "Could not open file/files" << endl;
        }


    ifstream file2Name(file2Name); 

        if(file2Name.fail()){
            cout << "Could not open file/files" << endl;
        }

    
}