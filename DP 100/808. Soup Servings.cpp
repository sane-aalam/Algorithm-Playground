class Solution {
public:
    double solve(int A,int B,vector<vector<double>>&dp){
        if(A<=0 && B<=0){
            return 0.5;
        }
        if(A<=0){
            return 1;
        }
        if(B<=0){
            return 0;
        }
        if(dp[A][B]!=-1){
            return dp[A][B];
        }

        // do according to quesitions
        // Try all possible ways (There are 4 options) 
        // Serve 100 ml of soup A and 0 ml of soup B,
        // Serve 75 ml of soup A and 25 ml of soup B,
        // Serve 50 ml of soup A and 50 ml of soup B, and
        // Serve 25 ml of soup A and 75 ml of soup B.

        double x = solve(A-100,B,dp);
        double y = solve(A-75,B-25,dp);
        double z = solve(A-50,B-50,dp);
        double k = solve(A-25,B-75,dp);

        return dp[A][B]=0.25*(x + y + z + k);
    }
    double soupServings(int n) {
        if(n>=4800){
            return 1;
        }
        vector<vector<double>>dp(n+1,vector<double>(n+1,-1));
        return solve(n,n,dp);
    }
};