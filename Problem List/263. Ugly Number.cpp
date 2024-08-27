/*
Approach
Start by checking if the number is non-positive or 1. If it’s 1, return true; 
if it's non-positive, return false. 
Then, repeatedly divide the number by 2, 3, and 5 until it’s no longer divisible by any of them. 
Finally, check if the number is 1. If it is, return true; otherwise, return false.
*/
class Solution {
public:
    bool isUgly(int n) {
        if(n==1) 
             return true;
        if(n<=0) 
              return false;
        while(n%2==0) n/=2;
        while(n%3==0) n/=3;
        while(n%5==0) n/=5;
        
        if(n!=1) return false;
        return true;
    }
};