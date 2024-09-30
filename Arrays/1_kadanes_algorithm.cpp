/*
    Maximum Subarray Sum using Brute Force Approach - O(n^3)
    --------------------------------------------------------


    leetcode link :- https://leetcode.com/problems/maximum-subarray/

    // just to print the subarray

    for(int start = 0; start < n; start++) {
        for(int end = start; end < n; end++) {
            for(int k = start; k <= end; k++) {
                cout << arr[k] << " ";
            }
            cout << endl;
        }
    }


    Time Complexity: O(n^3)


    Brute Force Approach:
    ---------------------

    Time Complexity: O(n^3)

        int maxSum = INT_MIN;

        for(int start = 0; start < n; start++) { 
            for(int end = start; end < n; end++) {
                int sum = 0;
                for(int k = start; k <= end; k++) { // subarray from start to end
                    sum += arr[k]; // sum of subarray
                }
                maxSum = max(maxSum, sum);// maximum sum of subarray
            } 
        }

        cout << maxSum << endl;


    Or, 

    Time Complexity: O(n^2)

        int maxSum = INT_MIN;

        for(int start = 0; start < n; start++) { 
            int current_sum = 0 ; 
            for(int end = start; end < n; end++) {
                current_sum += arr[end]; // sum of subarray
                maxSum = max(maxSum, current_sum); // maximum sum of subarray
            }   
        }

        cout << maxSum << endl;



    Kadane's Algorithm:
    -------------------

    Time Complexity: O(n)

        int maxSum = INT_MIN;
        int current_sum = 0;

        for(int i = 0; i < n; i++) {
            current_sum += arr[i];
            maxSum = max(maxSum, current_sum);
            if(current_sum < 0) {
                current_sum = 0;
            }
        }

        cout << maxSum << endl;


*/


// example kadanes algorithm:


#include<iostream>
using namespace std ;

int main(void){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxSum = INT_MIN;
    int current_sum = 0;

    for(int i = 0; i < n; i++) {
        current_sum += arr[i];
        maxSum = max(maxSum, current_sum);
        if(current_sum < 0) {
            current_sum = 0;
        }
    }

    cout << maxSum << endl;
return 0;
}