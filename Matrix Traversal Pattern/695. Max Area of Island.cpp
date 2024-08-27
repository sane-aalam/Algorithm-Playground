class Solution {
private:
   // make sure you are passing [pass by reference all variable and matrix array ]
   // same to same [number of islands code]
   // just count the lands 
   // which islands have maximum lands return max(all of island lands result)
   int n,m;
   void dfs(int row, int col, int &count, vector<vector<int>> & grid, vector<vector<int>> & visited){
         
          visited[row][col] = 1;
          count = count + 1;

          int delrow[4] = {-1,0,1,0};
          int delcol[4] = {0,1,0,-1};

          for(int direction = 0; direction < 4; direction++){
            int newrow = delrow[direction] + row;
            int newcol = delcol[direction] + col;

            if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && grid[newrow][newcol] == 1
               && visited[newrow][newcol] == 0){
                   dfs(newrow,newcol,count,grid,visited);
               }
          }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
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