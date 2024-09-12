
//! A common subsequence of two strings is a subsequence that is common to both strings.
// Express everything is terms of indexes
// Explore all the paths(matched or matched)
// Find maximum subsequence of two strings 


// Function(N,M) -> function(0,0)
class Solution {
private:
   int solve(string text1, string text2, int i , int j){
        if(i == 0 or j == 0){
            return 0;
        }
       if(text1[i-1] == text2[j-1]){
           return 1 + solve(text1,text2,i-1,j-1);
       }else{
           return max(solve(text1,text2,i,j-1),solve(text1,text2,i-1,j));
       }
   }
public:
    int longestCommonSubsequence(string text1, string text2) {
         int n = text1.size();
         int m = text2.size();

         return solve(text1,text2,n,m);
    }
};

// [start to end] Design the recursive Tree
// function(0,0) -> (N,M) 
class Solution {
private:
   int solve(int index1, int index2, string text1, string text2,
                           int n , int m){

        if(index1 >= n or index2 >= n){
            return 0;
        }

        if(text1[index1] == text2[index2]){
            return 1 + solve(index1+1, index2+1, text1,text2,n,m);
        }else{
            return max(solve(index1, index2+1, text1,text2,n,m),
                   solve(index1+1, index2, text1,text2,n,m));
        }
   }
public:
    int longestCommonSubsequence(string text1, string text2) {
         int n = text1.size();
         int m = text2.size();

         int index1 = 0;
         int index2 = 0;

         return solve(index1,index2,text1,text2,n,m);
    }
};

 

//# recursive + memo = Time Limit Exceeded

class Solution {
private:
// Express everything is terms of indexes
// Explore all the paths(matched or matched)
// Find maximum 
   int solve(string text1, string text2, int i , int j,vector<vector<int>> &dp){
        if(i == 0 or j == 0){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
     // both string char are Equal 
     // both strings char are not Equal 
     // Choice Diagram
       if(text1[i-1] == text2[j-1]){
           return dp[i][j] = 1 + solve(text1,text2,i-1,j-1,dp);
       }else{
           return dp[i][j] = max(solve(text1,text2,i,j-1,dp),solve(text1,text2,i-1,j,dp));
       }
   }
public:
    int longestCommonSubsequence(string text1, string text2) {
         int n = text1.size();
         int m = text2.size();

        // recursive + memo
        // create matrix using changable variable
        // store the recursive calls
        // re-use the recursive calls
         vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
         return solve(text1,text2,n,m,dp);
    }
};

 
// table used : tabulation [filling the matrix]

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
         int n = text1.size();
         int m = text2.size();

         vector<vector<int>> dp(n+1,vector<int>(m+1));

        // base conditon convert into instillation of dp matrix (base conditon)
         for(int i = 0; i <= n; i++){
            for(int j = 0; j <=m; j++){
                if(i == 0 or j == 0){
                    dp[i][j] = 0;
                }
            }
         }

         // copy the recurrence relation
         // Equal or not Eqal
         for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
         }
         return dp[n][m];
    }
};

