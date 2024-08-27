class Solution {
private:
    int delrow[4] = {-1,0,1,0};
    int delcol[4] = {0,1,0,-1};
    int dp[201][201];
    int helper(int row, int col, vector<vector<int>> & matrix, int n, int m){
          
          if(dp[row][col] != -1){
            return dp[row][col];
          }

          int increasingPaths = 1;

          for(int direction = 0; direction < 4; direction ++){
             int newrow = row + delrow[direction];
             int newcol = col + delcol[direction];

             if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m
              && matrix[row][col] < matrix[newrow][newcol]){
            // [3]
            // [3,4]
            // [3,4,5]
            // [3,4,5,6]
            // path will increasing by 1 for next calls 
                    increasingPaths = max( 1 + helper(newrow,newcol,matrix,n,m), increasingPaths);
              }
          }

          return dp[row][col] =  increasingPaths;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
         int n = matrix[0].size();

        // fill the entire matrix - dp using -1 
         memset(dp,-1,sizeof(dp));

        int maximumIncreasingPaths = 0;
         for(int row = 0; row < m; row ++){
            for(int col = 0; col < n; col++){
                 int result = helper(row,col,matrix,m,n);
                 // fill maximum of all paths 
                 maximumIncreasingPaths = max(result,maximumIncreasingPaths);
            }
         }

         return maximumIncreasingPaths;
    }
};