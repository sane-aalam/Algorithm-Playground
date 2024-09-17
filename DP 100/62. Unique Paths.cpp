
//  < How to write down good DP solution >
// [ best solution] - try all possible ways [ recursion ]
// [ recursion -> memo -> table -> space optimization ]

// Recursive solution - TLE
class Solution {
private:
    int solve(int index1, int index2){

        if(index1 == 0 and index2 == 0){
            return 1;
        }

        if(index1 < 0 or index2 < 0){
            return 0;
        }

        // The robot can only move either down or right at any point in time.
        // There are two possible ways to reached source to destination 
        // we are writing recursion 
        // destination to top (n,m) -> (0,0);
        // When you reached (0,0) then hits the base condition 

        int up = solve(index1-1, index2);
        int right = solve(index1, index2-1);
        return up + right;
    }
public:
    int uniquePaths(int m, int n) {
        int index1 = m - 1;
        int index2 = n - 1;
        return solve(index1, index2);
    }
};




// Memo solution-

class Solution {
private:
    int solve(int index1, int index2,vector<vector<int>>&dp){

        // When you hit the (0,0)
        // This is one possible way to reached
        if(index1 == 0 and index2 == 0){
            return 1;
        }

        // not gonna to out of boundary of matrix 
        if(index1 < 0 or index2 < 0){
            return 0;
        }

        if(dp[index1][index2] != -1){
            return dp[index1][index2];
        }

        // The robot can only move either down or right at any point in time.
        // There are two possible ways to reached source to destination 
        // we are writting recursion 
        // destination to top (n,m) -> (0,0);
        // When you reached (0,0) then hits the base condtion 
        // direction changed - up and right new direction
        int up = solve(index1-1, index2,dp);
        int right = solve(index1, index2-1,dp);
        return dp[index1][index2] = up + right;
    }
public:
    int uniquePaths(int m, int n) {
        int index1 = m - 1;
        int index2 = n - 1;
        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
        int final_result =  solve(index1, index2,dp);
        return final_result;
    }
};


// table solution 

class Solution {
public:
    int uniquePaths(int m, int n) {
         vector<vector<int>> dp(m,vector<int> (n+1));

         for(int i = 0; i<m; i++){
            for(int j = 0;j<n; j++){
                if(i == 0 and j == 0){
                    dp[i][j] = 1;
                }else{
                    int up = 0;
                    int right = 0;
                    if(i > 0){
                        up = dp[i-1][j];
                    }
                    if(j > 0){
                        right = dp[i][j-1];
                    }
                    dp[i][j] = right + up;
                }
            }
         }
         return dp[m-1][n-1];
    }
};

