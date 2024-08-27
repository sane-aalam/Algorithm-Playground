class Solution
{
    private:
   // make sure you are passing [pass by reference all variable and matrix array ]
   int n,m;
   void dfs(int row, int col, int &count, vector<vector<int>> & grid, vector<vector<int>> & visited){
         
          visited[row][col] = 1;
          count = count + 1;

          // connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.
          int delrow[8] = {-1,1,0,0,-1,1,-1,1};
          int delcol[8] = {0,0,-1,1,1,-1,-1,1};

          for(int direction = 0; direction < 8; direction++){
            int newrow = delrow[direction] + row;
            int newcol = delcol[direction] + col;

            if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && grid[newrow][newcol] == 1
               && visited[newrow][newcol] == 0){
                   dfs(newrow,newcol,count,grid,visited);
               }
          }
    }
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
         n = grid.size();
         m = grid[0].size();

         vector<vector<int>> visited(n,vector<int>(m,0));
         int maxAreaIsland = 0;
         for(int row = 0; row < n; row ++){
            for(int col = 0; col < m; col++){
                if(grid[row][col] == 1 && visited[row][col] == 0){
                    int count = 0;
                    dfs(row,col,count,grid,visited);
                    maxAreaIsland = max(maxAreaIsland,count);
                }
            }
         }
         return maxAreaIsland;
    }
};