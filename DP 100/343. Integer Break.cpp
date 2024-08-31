class Solution {
private:
    int solve(int n, vector<int> & dp){
        if(n == 2) return 1;
        if(dp[n] != -1) return dp[n];

        int ans = INT_MIN;

        // Try all possible way to each index value 
        // n-i
        // firstly called (n-1) = (5-1) = 4
        // second called (n-2) = (5-2) = 3
        // thrid called (n-3) = 5-3 =
        for(int i = 1; i<n; i++){
            ans = max(ans,i*max((n-i),solve(n-i,dp)));
        }
        return dp[n] = ans;
    }
public:
    int integerBreak(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};