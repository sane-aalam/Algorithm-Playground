class Solution {
private:
    int totalNumberWays(int m, int n,vector<vector<int>> & dp){
        
        // When you reached source to destination then you can say 1 Possible way 
        if(m == 0 and n == 0){
            return 1;
        }
        
        // When you are gonna to out the boundary of the matrix
        if(m < 0 or n < 0){
            return 0;
        }
        
        // Memorization of the recursive calls using dp
        if(dp[m][n] != -1){
            return dp[m][n];
        }
        
        int leftWay = totalNumberWays(m,n-1,dp);
        int UpWay = totalNumberWays(m-1,n,dp);
        
        return dp[m][n] = leftWay + UpWay;
    }
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        // solution function called 
        return totalNumberWays(m-1,n-1,dp);
    }
};