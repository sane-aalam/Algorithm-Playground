class Solution {
public:
    const int MOD = 1e9 + 7;
    long long solve(int n, int goal, int k, vector<vector<int>>& dp) {

        // Lecture-7 recursion playlist [takeuforwared]
        // count all the possible ways 
        if (n == 0 && goal == 0) 
              return 1;
        if (n == 0 || goal == 0) 
              return 0;

        // memorization of the recusive code
        if (dp[n][goal] != -1) 
             return dp[n][goal];

        // pick the song or NOT pick the song
        long long pick = solve(n - 1, goal - 1, k, dp) * n;
        long long notpick = solve(n, goal - 1, k, dp) * max(n - k, 0);
        return dp[n][goal] = (pick + notpick) % MOD;
    }

    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(goal + 1, -1));
        return solve(n, goal, k, dp);
    }
};