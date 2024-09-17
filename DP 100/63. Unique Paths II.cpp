class Solution {
public:
   // problem me block cell value = 1 bhaiJaan 
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        // start me obstacle ho - not possible way to reach
        // block value bhaijaan 1 hay 
        if(obstacleGrid[0][0] == 1){
            return 0;
        }
        
        // last me obstacle ho - not possible way to reach
         // block value bhaijaan 1 hay 
        if(obstacleGrid[m-1][n-1] == 1){
            return 0;
        }

        vector<vector<int>> dp(m,vector<int> (n+1));

         for(int i = 0; i<m; i++){
            for(int j = 0;j<n; j++){
                if(i == 0 and j == 0){
                    dp[i][j] = 1;
                    continue;
            // A path that the robot takes cannot include any square that is an obstacle.
            // There is an obstacle then not possible way
            // Obstacle Grid value = 1
                }else if(i > 0 && j > 0 && obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                    continue;
                }else{
                    int up = 0;
                    int right = 0;
                    if(i > 0 && obstacleGrid[i][j] != 1){
                        up = dp[i-1][j];
                    }
                    if(j > 0 && obstacleGrid[i][j] != 1){
                        right = dp[i][j-1];
                    }
                    dp[i][j] = right + up;
                }
            }
         }
         return dp[m-1][n-1];
    }
};