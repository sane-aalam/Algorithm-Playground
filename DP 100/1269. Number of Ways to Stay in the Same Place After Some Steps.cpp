
//✅BreakDown Hard to easy [recursion]
// Trust on yourself - you are doing better 99% students 

// point-1 You have a pointer at index 0 in an array of size arrLen.
// point-2 each steps, 
// you can move left by 1 position
// you can move right by 1 position
// you can stay into same position 
// you have number of steps that you can take

// ✅ helper(index,steps) => helper(0,0) (how many times hits- the number of ways such that your pointer is still at index 0 after exactly step)

// 📌Striver DP Series [rules]
// Try all the possible ways
//1. express everything in terms of indexes
//2. explore all paths
//3. sum up all possible ways [paths]
        

class Solution {
private:
// Since the answer may be too large, return it modulo 109 + 7.
   int mod = 1e9+7;
   int helper(int index,int steps, int n){
      // base case 1
      // left side ja rahe ho (negative mat jana)
      // right side ja rahe ho (arrayLen se mat jana)
       if(index < 0 || index >= n ){
           return 0;
       }
       // base case-2 
       // there are no number of steps
       if(steps < 0) return 0;

       // base case-2
       //  your pointer is still at index 0 
       if(index == 0 && steps == 0){
          return 1;
       }

       int left = helper(index-1,steps-1,n);
       int right = helper(index+1,steps-1,n);
       int staySame = helper(index,steps-1,n);
       int TotalNumberWays = (left + right + staySame) % mod;
       return TotalNumberWays;
   }
public:
    int numWays(int steps, int arrLen) {
        int n = arrLen;
        int index = 0;
        return helper(index,steps,n);
    }
};


// Time Limit Exceeded (we have to use dp solution)

// Striver DP Series [rules]
// Try all the possible ways
//1. express everything in terms of indexes
//2. explore all paths
//3. sum up all possible ways [paths]
// Memorization using changable variable
// ❌ accepted solution not - lot of mistake having
        

class Solution {
private:
// Since the answer may be too large, return it modulo 109 + 7.
   int mod = 1e9+7;
   int helper(int index,int steps, int n, vector<vector<int>> & dp){
      // base case 1
      // left side ja rahe ho (negative mat jana)
      // right side ja rahe ho (arrayLen se mat jana)
       if(index < 0 || index >= n ){
           return 0;
       }
       // base case-2 
       // there are no number of steps
       if(steps < 0) return 0;

       // base case-2
       //  your pointer is still at index 0 
       if(index == 0 && steps == 0){
          return 1;
       }

       // memorization of recursive calls
       // time complexity 0(1)
       if(dp[steps][index] != -1){
          return dp[steps][index];
       }

      // large number of value (store used long long int)
      long long int left = helper(index-1,steps-1,n,dp);
      long long int right = helper(index+1,steps-1,n,dp);
      long long int staySame = helper(index,steps-1,n,dp);
      long long int TotalNumberWays = (left + right + staySame) % mod;
      return dp[steps][index] = TotalNumberWays;
   }
public:
    int numWays(int steps, int arrLen) {
        int n = arrLen;
        int index = 0;

        vector<vector<int>> dp(steps+1,vector<int>(arrLen+1,-1));
        return helper(index,steps,n,dp);
    }
};

// ✅ accepted solution

class Solution {
private:
// Since the answer may be too large, return it modulo 109 + 7.
   int mod = 1e9+7;
   int helper(int index,int steps, int n, vector<vector<long long int>> & dp){
      // base case 1
      // left side ja rahe ho (negative mat jana)
      // right side ja rahe ho (arrayLen se mat jana)
       if(index < 0 || index >= n ){
           return 0;
       }
       // base case-2 
       // there are no number of steps
       if(steps < 0) return 0;

       // base case-2
       //  your pointer is still at index 0 
       if(index == 0 && steps == 0){
          return 1;
       }

       // memorization of recursive calls
       // time complexity 0(1)
       if(dp[steps][index] != -1){
          return dp[steps][index];
       }

      // large number of value (store used long long int)
      // every recusive need to do modificatin by large number MOD
      long long int left = helper(index-1,steps-1,n,dp) % mod;
      long long int right = helper(index+1,steps-1,n,dp) % mod;
      long long int staySame = helper(index,steps-1,n,dp) % mod;
      long long int TotalNumberWays = (left + right + staySame) % mod;
      return dp[steps][index] = TotalNumberWays;
   }
public:
    int numWays(int steps, int arrLen) {
         if(arrLen > steps) 
               arrLen = steps;
        int n = arrLen;
        int index = 0;
        // TLE
        // DP matrix used -> long long int (to store the large value)
        vector<vector<long long int>> dp(steps+1,vector<long long int>(arrLen+1,-1));
        return helper(index,steps,n,dp);
    }
};






