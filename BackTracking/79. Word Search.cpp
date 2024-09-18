class Solution {
private:
    bool dfs(int row, int col, string &word, vector<vector<char>>& board, int index, vector<vector<int>> &vis){
        // cout<<board[row][col]<<endl;

        if(index==word.length()) 
         return true;

        int n = board.size();
        int m = board[0].size();

        vis[row][col]=1;

        int delrow[4] = {1,0,-1,0};
        int delcol[4] = {0,1,0,-1};

        for(int i=0;i<4;i++){
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
             !vis[nrow][ncol] && word[index]==board[nrow][ncol]){
                if(dfs(nrow,ncol,word,board,index+1,vis)) 
                        return true;
            }
        }
        vis[row][col]=0;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int index = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[index]){
                    if(dfs(i,j,word,board,index+1,vis)) 
                        return true;
                }
            }
        }
        return false;
    }
};

	
Introduction to Binary Search Tree
Search in a Binary Search Tree
Find Min/Max in BST
Ceil in a Binary Search Tree
Floor in a Binary Search Tree
Insert a given Node in Binary Search Tree
Delete a Node in Binary Search Tree
Find K-th smallest/largest element in BST
Check if a tree is a BST or BT
LCA in Binary Search Tree
Construct a BST from a preorder traversal
Inorder Successor/Predecessor in BST
Merge 2 BST's
Two Sum In BST | Check if there exists a pair with Sum K
Recover BST | Correct BST with two nodes swapped
Largest BST in Binary Tree