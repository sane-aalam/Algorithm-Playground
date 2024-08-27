// solution-1 recursive appraoch

class Solution {
public:
    int fib(int n) {
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }

        return fib(n-1) + fib(n-2);
    }
};

// solution-2 Memorization appraoch to improve time complexity and space complexity

class Solution {
private:
   int solve(int n, vector<int> & dp){
     if(n <=1){
        return n;
     }
     
     if(dp[n] != -1){
        return dp[n];
     }

     int secondSmallestNumber = solve(n-1,dp);
     int secondSmallestNumber2 = solve(n-2,dp);
     return dp[n] = secondSmallestNumber + secondSmallestNumber2;
   }
public:
    int fib(int n) {
        vector<int> dp(n+1,-1);
        int NthFibonacciNumber = solve(n,dp);
        return NthFibonacciNumber;
    }
};

// solution-3 Tabulation 
class Solution {
public:
    int fib(int n) {
        if(n <= 1){
            return n;
        }
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;

        for(int i = 2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

// solution-4 space optimization
// famous-doubtes used to understand 

class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        int prev1 = 1;
        int prev2 = 0;
        int curr = 0;

        for(int i = 2; i<=n; i++){
            curr = prev2 + prev1;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};