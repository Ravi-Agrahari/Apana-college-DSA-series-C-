/*

    x_pow(n) leetcode problem 
    --------------------------

    leecode link : https://leetcode.com/problems/powx-n/

*/


#include<iostream>
using namespace std ;

double pow(double x , int n){
    
    if(n == 0) return 1.0 ;
    if(x == 0) return 0.0 ;
    if(x == 1 && n%2 == 0 ) return 1.0 ;
    if(x == -1 && n%2 != 0 ) return -1.0 ;
    
    long num = n ; 

    // corner cases ....

    if(num < 0){
        x = 1/x ;
        n = -n ;
    }
    double result = 1 ; 

    // first convert to binary and then multiply the result with x
    // Example 
    // 5 = 101 then x^5 = x^4 * x^1 ie x^101 = x^100 * x^1 where 100=4 and 1 = 1 

    while( num>0 ){
        if(num %2 == 1){
            result *= x ;
        }

        x *= x ;
        num /= 2 ;
    }

    return result ;
}

int main(void){
    double x ; 
    int n ;

    cout << "Enter the value of x : " ;
    cin >> x ;

    cout << "Enter the value of n : " ;
    cin >> n ; 

    
    cout << "The result of x^n is : " << pow(x,n) << endl ;
    
return 0;
}