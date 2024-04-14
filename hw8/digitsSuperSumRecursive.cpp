#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <cassert>
using namespace std;
    
vector<int> vct;

/*
This function takes a number n, stores its digits in a vector, and returns this vector.
1. Make sure n is greater than 0;
2. Store the remainder of n/10 in the vector. This will be the last digit of n;
3. Update the variable n with the value n/10. This will remove the digit that's now stored in the vector from n;
4. Call the function again. When this loop reaches the last digit, the result of n/10 will be 0, breaking the loop;
5. Return the populated vector;
*/
vector<int> storeDigits(int n){

    if(n > 0){
        vct.push_back(n % 10); //Store the remainder of n/10 in the vector. This will be the last digit of n;
        n /= 10; //Update the variable n with the value n/10. This will remove the digit that's now stored in the vector from n;
        storeDigits(n); //Call the function again. When this loop reaches the last digit, the result of n/10 will be 0, breaking the loop;
    }

    return vct;
}

/*
This function takes a vector v and returns the sum of its elements.
1. If the size of the vector is 1, return that element;
2. If the size of the vector is 0, return 0;
3. If the size of the vector is greater than 1, sum its 2 last elements and remove them;
4. Populate the last element of the vector with the previous sum;
5. Call the function again. This way, the function will call itself until there is only one element left in the vector(the total sum of all elements);
*/
int sumVectorElements(vector<int> v){
    //If the size of the vector is 1, return that element;
    if(v.size() == 1){
        return v[0];
    }

    //If the size of the vector is 0, return 0;
    else if(v.size() == 0){
        return 0;
    }

    else{
        int sum;

        sum = v[v.size() - 1] + v[v.size() - 2]; //Sum the last 2 elements of the vector;
        
        //Remove the last two elements from the vector;
        v.pop_back();
        v.pop_back();

        v.push_back(sum); //Populate the last element of the vector with the previous sum;

        return sumVectorElements(v); //Call the function again. This way, the function will call itself until there is only one element left in the vector(the total sum of all elements);
    }
}

/*
This function executes the super sum of a number that already has its digits split in a vector.
1. If the number only has one digit (i.e the size of the vector is 1), return the first (and only) element in the vector;
2. If the number has more than one digit, declare an int x and make it equal to the sum of all elements in the vector;
3. Split the digits of x into a new vector;
4. If the size of the new vector is 1, return the first (and only) element in the vector;
5. If the size of the new vector is greater than 1, call the function again. This way, the function will call itself until the vector has only 1 element;
*/
int vectorSuperSum(vector<int> numsToSum){
    //If the number only has one digit, return the first element in the vector;
    if(numsToSum.size() == 1){
        return numsToSum[0];
        
    }

    else{
        //If the number has more than one digit, declare an int x and make it equal to the sum of all elements in the vector;
        int x = sumVectorElements(numsToSum);
        
        vct.clear();
        vector<int> v = storeDigits(x); //Split the digits of x into a new vector;

        //If the size of the new vector is 1, return the first element in the vector;
        if(v.size() == 1){
            return v[0];
        }

        else{
            //If the size of the new vector is greater than 1, call the function again. This way, the function will call itself until the vector has only 1 element;
            return vectorSuperSum(v);
        }      
    }
}

/*
This function takes a positive integer N and returns its super sum.
1. If N is between 0-9, return N;
2. If N is greater than 9, populate a vector with its digits using the storeDigits function;
3. Return the result of vectorSuperSum with the newly created vector of digits as the parameter;
*/
int digitsSuperSumRecursive(int N){
    vct.clear();
    int x = N;

    //If N is between 0-9, return N;
    if(N >= 0 && N < 10){
        return N;
    }

    else{
        //If N is greater than 9, populate a vector with its digits;
        vector<int> numsToSum = storeDigits(N);

        //Return the result of vectorSuperSum with the newly created vector of digits as the parameter;
        return vectorSuperSum(numsToSum);       
    }
}

int main(){
    //Test case 1
    assert(digitsSuperSumRecursive(0) == 0);
    //Test case 2
    assert(digitsSuperSumRecursive(5) == 5);
    //Test case 3
    assert(digitsSuperSumRecursive(12) == 3);
    //Test case 4
    assert(digitsSuperSumRecursive(4567) == 4);
    //Test case 5
    assert(digitsSuperSumRecursive(69420) == 3);
}