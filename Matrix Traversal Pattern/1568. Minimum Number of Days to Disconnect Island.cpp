
/* short-notes of this problem [hard to become easy problem]

we can conclude that a minimum of two days is required to disconnect the grid. 
The reasoning behind this is that any grid that is connected but doesn't get disconnected by the removal of any single land cell must have a structure that requires at least two removals to break apart.*/
// If we cut an island from any corner leaving smalllest possible island, we need two 0 in diagonal setting.

/*  make sure this conditon you should understand clearly !
       if(islands > 1 || islands == 0) return 0;
        1. at least two islands two ho chiaye
        2. island == 0
        3.island is zada tab bhi kuch nahi karna hai
 */
class Solution {
private:
    // DFS + Backtacking concept used here
    int n,m;
    void dfs(int row, int col, vector<vector<int>> & grid, vector<vector<int>> & visited){
         
          visited[row][col] = 1;

          int delrow[4] = {-1,0,1,0};
          int delcol[4] = {0,1,0,-1};

          for(int direction = 0; direction < 4; direction++){
            int newrow = delrow[direction] + row;
            int newcol = delcol[direction] + col;

            if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && grid[newrow][newcol] == 1
               && visited[newrow][newcol] == 0){
                   dfs(newrow,newcol,grid,visited);
               }
          }
    }
    int numIslands(vector<vector<int>>& grid) {
         vector<vector<int>> visited(n,vector<int>(m,0));

         int NumberIslands = 0;

         for(int row = 0; row < n; row ++){
            for(int col = 0; col < m; col++){
                if(grid[row][col] == 1 && visited[row][col] == 0){
                    dfs(row,col,grid,visited);
                    NumberIslands = NumberIslands + 1;
                }
            }
         }

         return NumberIslands;
    }
public:
    int minDays(vector<vector<int>>& grid) {
     
        n = grid.size();
        m = grid[0].size();

        int islands = numIslands(grid);

        // at least two islands two ho chiaye
        // island == 0
        // island is zada tab bhi kuch nahi karna hai
        if(islands > 1 || islands == 0){
            return 0;
        }

        for(int row = 0; row < n; row ++){
            for(int col = 0; col<m; col++){

            // if current cell having 1 to convert into zero (0)
            // check you have done disconnect in this way
            // number of islands become more than 2 or zero 
              if(grid[row][col] == 1){
                    grid[row][col] = 0;
                    islands = numIslands(grid);
                    if(islands > 1 || islands == 0){
                        return 1;
                    }
                    // backtrack 
                    // If you have made current cell 0' for disconnet
                    // suppose not possbile to make disconnect island 
                    // you have to undo your works
                    grid[row][col] = 1;
                }
                  
            }
        }
        // all the conditon is not possible 
        // Then we can conclude that a minimum of two days is required to disconnect the grid. 
        return 2;
    }
};
