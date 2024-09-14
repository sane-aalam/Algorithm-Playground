
// Algorithm - 
// if you are able to reached into last (n-1,m-1) having at least 1 health return true;
// other you can not reached (lastrow, lastcolumn) [N,M]

// bruthforce - recursion (reject)
// BFS (matrix of grid) - (success)
// Try all possible algorithm,Which came into your mind


class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int m = grid.size();
        int n = grid[0].size();

        queue<tuple<int, int, int>> q;

        // Queue(row,col,health-0,1)
        // health 0 kuch nahi kam hoga
        // health 1 hai, reduce by 1 ho jayega 
        q.push({0, 0, health - grid[0][0]});
        
        vector<vector<int>> visited(m, vector<int>(n, -1));

        // you have visited this current cell
        visited[0][0] = health - grid[0][0];
        
        while (!q.empty()) {
            auto [x, y, h] = q.front();
            q.pop();
            
            // When you reached the destinatino with health > 0 (you have at least 1 health)
            if (x == m - 1 && y == n - 1 && h > 0) {
                return true;
            }
            
            int delrow[4] = {-1,0,1,0};
            int delcol[4] = {0,1,0,-1};

            for(int direction = 0; direction < 4; direction++){
                int newrow = x + delrow[direction];
                int newcol = y + delcol[direction];
                
                // not gonna to out of boundary of matrix
                // update the health
                if (newrow >= 0 && newrow < m && newcol >= 0 && newcol < n) {
                    int newHealth = h - grid[newrow][newcol];

                    if (newHealth > 0 && newHealth > visited[newrow][newcol]) {
                        visited[newrow][newcol] = newHealth;
                        q.push({newrow, newcol, newHealth});
                    }
                }
            }
        }
        
        return false;
    }
};