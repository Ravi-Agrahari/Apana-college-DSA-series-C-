/*

Majority Element
----------------

leetcode: https://leetcode.com/problems/majority-element/

Problem description:
--------------------

Given an array of size n, find the majority element. The majority element is the element that appears more than n/2 times.

Test case:
----------

Input:

5
2 2 3 3 3

Output:

3


// Brute force approach: (O(n^2))


int n = 5; 
vector<int> arr = {2,2,3,3,3};

for(int i = 0; i < n; i++) {
    int count = 0;
    for(int j = 0; j < n; j++) {
        if(arr[i] == arr[j]) {
            count++;
        }
    }
    if(count > n/2) {
        cout << arr[i] << endl;
        return;
    }
}



// Optimised approach: O(n.log(n))


find the majority element in the array using sorting.


int n = 5;
vector<int> arr = {2,2,3,3,3};

sort(arr.begin(), arr.end());

int count = 1;
for(int i = 1; i < n; i++) {
    if(arr[i] == arr[i - 1]) {
        count++;
    } else {
        count = 1;
    }
    if(count > n/2) {
        cout << arr[i] << endl;
        return;
    }
}




// moore's voting algorithm: O(n)

if same element , freq++ ;
else if different element ,  freq-- ;
no need of sorting... 

code 
-----

int n = 5;
vector<int> arr = {2,2,3,3,3};

int count = 0;
for(int i = 0; i < n; i++) {
    if(count == 0) {
        majority_element = arr[i];
    } 
    if(majority_element == arr[i]) {
        count++;
    } else {
        count--;
    }
}





*/




#include<iostream>
#include<vector>
#include<algorithm>

using namespace std ;


int brute_majority_element(vector<int> arr){
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        int count = 0;
        for(int j = 0; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
            }
        }
        if(count > n/2) {
            return arr[i];
        }
    }
    return -1;
}


/// Optimised approach: O(n.log(n)) - using sorting

int majority_element_using_sorting(vector<int> arr){
    int n = arr.size();
    sort(arr.begin(), arr.end());

    int count = 1;

    for(int i = 1; i < n; i++) {
        if(arr[i] == arr[i - 1]) {
            count++;
        } else {
            count = 1;
        }
        if(count > n/2) {
            return arr[i];
        }
    }
    return -1;
}


// moore's voting algorithm: O(n)
int majority_element_using_moore_voting_algorithm(vector<int> arr){
    int n = arr.size();
    int count = 0;
    int majority_element = -1;

    for(int i = 0; i < n; i++) {
        if(count == 0) {
            majority_element = arr[i];
        }

        if(majority_element == arr[i]) {
            count++;
        } else {
            count--;
        }
    }
    return majority_element;
}


int main(void){

    int n = 5; 
    vector<int> arr = {2,2,3,3,3};


    // cout << brute_majority_element(arr) << endl;

    // cout << majority_element_using_sorting(arr) << endl;

    cout << majority_element_using_moore_voting_algorithm(arr) << endl; 

    
    
return 0;
}