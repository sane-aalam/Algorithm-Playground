
// Hard Story to code convertion [breakDown into steps]
// algorithm simple BFS
// Point-1 -> You are given an m x n matrix maze (0-indexed) with empty cells (represented as '.') and walls (represented as '+')
// Point-2 -> start point of entrance = [entrancerow, entrancecol]
// point-3 -> you can move one cell up, down, left, or right.
// you can move 4-direction, delrow[4] = [-1,0,1,0], delcol[4] = [0,1,0,1];
// point-4 -> you have to exit point (bounary of matrix) in which you can exit into matrix
// point-5 -> number of steps in the shortest path from the entrance to the nearest exit
// Whenever you need to find the shorted path,Think about the shortes path,
// Think about BFS!

class Solution
{
public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {

        int n = maze.size();
        int m = maze[0].size();
        // create the visited matrix
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // [steps,(row,col)] queue contain
        queue<pair<int, pair<int,int>>> q;
        
        // entrance = [entrancerow, entrancecol]
        int entranceRow = entrance[0];
        int entranceCol = entrance[1];

        q.push({0,{entranceRow, entranceCol}});
        vis[entranceRow][entranceCol] = 1;

        int level = 0;

        while (!q.empty())
        {   
            int steps = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            // In one step, you can move one cell up, down, left, or right.
            int delrow[4] = {-1, 0, 1, 0};
            int delcol[4] = {0, 1, 0, -1};

            for (int direction = 0; direction < 4; direction++){
                int newrow = delrow[direction] + row;
                int newcol = delcol[direction] + col;

                if (newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && 
                                  maze[newrow][newcol] == '.' && vis[newrow][newcol] == 0){
                // When you hit the bounary of matrix [exit point into the matrix]
                // entrance hi exit point na ho 
                    if (newrow == 0 or newrow == n - 1 or newcol == 0 or newcol == m - 1){
                        // this is great point
                        // The entrance does not count as an exit.
                        if (!(newrow == entranceRow && newcol == entranceCol)){
                            return steps+1;
                        }
                    }
                    q.push({steps+1,{newrow, newcol}});
                    vis[newrow][newcol] = 1;
                }
            }
        }
        return -1;
    }
};
