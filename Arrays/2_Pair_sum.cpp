/*

Pair sum
--------

leetcode link :- https://leetcode.com/problems/two-sum/

Q. Given an array of n integers, find a pair (x, y) such that x + y = sum.

    Test case:
    ----------

    Input:
    5
    1 2 3 4 5
    7

    Output:
    3 4

    Brute force approach:
    ---------------------

    Time Complexity: O(n^2)

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) { // generate all possible pairs of i and j
                if(arr[i] + arr[j] == sum) { 
                    cout << arr[i] << " " << arr[j] << endl;
                }
            }
        }

    Optimised approach:
    -------------------

    if the array is sorted, then we can use two pointer approach to solve this problem.

    Time Complexity: O(n)

    2 pointer approach:
    -------------------

    int target = 7;
    vector<int> arr  = {1,2,3,4,5}; 
    int n = 5;


    int low = 0;
    int high = n - 1;


    while(low < high){
        int pair_sum = arr[low] + arr[high];

        if(pair_sum == target){
            cout << arr[low] << " " << arr[high] << endl;
            return;
        }
        if(pair_sum < target){
            low++;
        } else {
            high--;
        }
        
    }


    

*/

#include<iostream>
#include<vector>
using namespace std ;

// brute force approach (O(n^2))
vector<int> Brute_PairSum(vector<int> arr, int sum){

    vector<int> result;
    int n = arr.size();

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] + arr[j] == sum) {
                result.push_back(arr[i]);
                result.push_back(arr[j]);
                return result;
            }
        }
    }

    return {};
}


// 2 pointer approach (O(n))
vector<int> PairSum(vector<int> arr, int sum){

    vector<int> result;
    int n = arr.size();

    int low = 0;
    int high = n - 1;

    while(low < high){
        int pair_sum = arr[low] + arr[high];

        if(pair_sum == sum){
            result.push_back(arr[low]);
            result.push_back(arr[high]);
            return result;
        }
        if(pair_sum < sum){
            low++;
        } else {
            high--;
        }
    }

    return {};
}





int main(void){
    
    int n = 5 ; 
    vector<int> arr = {1, 2, 3, 4, 5};
    int sum = 7;

    // vector<int> result = Brute_PairSum(arr, sum);
    vector<int> result = PairSum(arr, sum);

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

return 0;
}