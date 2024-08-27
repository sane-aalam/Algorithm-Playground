


// we can also do in-place method
// we need extra space matrix 
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>temp(m,vector<int>(n));

        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
               // transpote the matrix 
               swap(matrix[row][col],temp[col][row]);
            }
        }
        return temp;
    }
};