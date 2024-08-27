
// Try all possible paths
// sum of all paths
// recursion -> dp 
// [[1,1][3,4]]
// Explanation: The strictly increasing paths are:
// - Paths with length 1: [1], [1], [3], [4].
// - Paths with length 2: [1 -> 3], [1 -> 4], [3 -> 4].
// - Paths with length 3: [1 -> 3 -> 4].
// The total number of paths is 4 + 3 + 1 = 8.

// currentElement < nextElement (follow this concept for increasing path)
// where you can move from a cell to any adjacent cell in all 4 directions

class Solution {
public:
    // memorization of recursive code 
    int dp[1001][10001];
    // 4-direction of matrix traversal way
    int delrow[4] = {-1,1,0,0};
    int delcol[4] = {0,0,-1,1};

    // Since the answer may be very large, return it modulo 109 + 7.
    int mod = 1e9 + 7;

     // simple DFS algorihtm 
    int helper(int row, int col,vector<vector<int>>& grid,int n, int m){

        if(dp[row][col] != -1){
            return dp[row][col];
        }

        // at leats one cell for 1 path possible startly
        // recursive (i have trust)
        // recursive function sum up all path (strictly increasing paths in the grid)
        long long paths = 1;

        for(int direction = 0; direction < 4; direction ++){
            int newrow = delrow[direction] + row;
            int newcol = delcol[direction] + col;
            
            // Follow valid case + increasing next element order 
            // call for next pointer 
           

         // Check if the neighboring cell is within the grid boundaries and has a greater value
            if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m 
            && grid[row][col] < grid[newrow][newcol]){
                paths += helper(newrow,newcol,grid,n,m); // call for next cell (using newrow, newcol indexes)
            }
        }
        return dp[row][col] = paths % mod;
    }
public:
    int countPaths(vector<vector<int>>& grid) {

         int m = grid.size();
         int n = grid[0].size();

         memset(dp,-1,sizeof(dp));

         int result = 0;
         for(int row = 0; row < m; row ++){
            for(int col = 0; col < n; col++){
                result += helper(row,col,grid,m,n);
            }
         }

         return result % mod;
    }
};