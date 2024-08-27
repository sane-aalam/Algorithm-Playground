class Solution {
public:
    int minimumDelete(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        
        int dp[n+1][m+1];
        
        for(int i = 0; i<n+1; i++){
            for(int j = 0; j<m+1; j++){
                if(i == 0 or j == 0){
                    dp[i][j] = 0;
                }
            }
        }
        
        for(int i = 1; i<n+1; i++){
            for(int j = 1; j<m+1; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = int(s1[i-1]) + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        // number of insertion = string 1 - LCS
       // number of deltion = string 2 - LCS
        int LCS = dp[n][m];
        int deletionOperation = n - LCS;
        int insertionOperation = m - LCS;
        int steps = deletionOperation + insertionOperation;
        return steps;
    }
};
















