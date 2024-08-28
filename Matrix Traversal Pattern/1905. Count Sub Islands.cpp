/*
We need to use DFS in grid2 to explore each island/sub-island because we want to check if the sub-island in grid2 is also present in grid1.
Why DFS?
Need to explore entire sub-island.
*/

class Solution {
private:
   bool islands;
   int n,m;
   void dfs(int row, int col, vector<vector<int>> & grid1, vector<vector<int>> & grid2){
       
       if(grid1[row][col] != grid2[row][col]){
           islands = false;
       }
       // we don't want to extra space for mark visited current cell
       // we just change the current cell value (-1), which means we did't came again this same cell 
       // but you can try visited Matrix, no need

       grid1[row][col] = -1;
       grid2[row][col] = -1;

       //  4-directionally (horizontal or vertical)
        int delrow[4] = {0, 0, 1, -1};
        int delcol[4] = {1, -1, 0, 0};
        for(int direction = 0; direction < 4; direction++){
            int newrow = delrow[direction] + row;
            int newcol = delcol[direction] + col;
            if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && grid2[newrow][newcol] == 1){
                // call for next cell 
                // valid range + matrix2 have land(1)
                dfs(newrow,newcol,grid1,grid2);
            }
       }
   }
public:
    // Number of islands [pattern]
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
         n = grid2.size();
         m = grid2[0].size();

        int count = 0;
        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                  if(grid2[row][col] == 1){
                    islands = true;
                    dfs(row,col,grid1,grid2);
                    if(islands == true){
                        count++;
                    }
                  }
            }
        }
        return count;
    }
};