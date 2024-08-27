

// Solution-1
// Lecture-7 recursive playlist
// If got your one goodString return 1;
// other return 0;

class Solution {
public:
  // for clear function calling, i have declared all variable upper of the function 
  // no need to pass again, again
    int rangeLow;
    int rangeHigh;
    int zeroLength;
    int oneLength;
    long long mod = 1e9 + 7; // mod
    int dp[100001];
   
   // recursive + memorization function, written here 
    int solve(int length){

        // base conditons
        if(length > rangeHigh)
           return 0;

        int count = 0;
        // A good string is a string constructed by the above process having a length between low and high (inclusive).
        if(rangeLow <= length && length <= rangeHigh){
            count = count + 1;
        }

        // Reduce the recursive calls
        // Memorize our recursive code 
        if(dp[length] != -1){
            return dp[length];
        }

        int appendOne = solve(length+oneLength) % mod;
        int appendZero = solve(length+zeroLength) % mod;
        // count all possible ways
        // sum up all ways 
        int totalGoodString = (appendOne + appendZero + count) % mod ;
        return dp[length] = totalGoodString % mod ;
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        rangeLow = low;
        rangeHigh = high;
        zeroLength = zero;
        oneLength = one;

        memset(dp,-1,sizeof(dp));

        // starting length of good string zero(0)
        return solve(0);
    }
};