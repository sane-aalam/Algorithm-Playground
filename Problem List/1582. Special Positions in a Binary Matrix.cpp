class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {

            int n = mat.size();
            int m = mat[0].size();      

            // create the 2 Array for storing the frquency of 
            // [how many times 1's came into particular row and column]
            vector<int> countRow(n, 0);
            vector<int> countCol(m, 0);

            for(int i = 0; i<n; i++){
                for(int j = 0; j<m; j++){
                    if(mat[i][j] == 1){
                        countRow[i]++;
                        countCol[j]++;
                    }
                }
            }  

  
         // Count the number of 1 in each row and column
            // Count the number of positions that meet the following conditions:
            // mat[i][j] == 1
            // countRow[i] == 1
            // countCol[i] == 1

           int count = 0;
           for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
            // particular row == number of 1's count
            // particular col == number of 1's count
            // matrix[row][col] == current cell value of 1'
            // all in one have same 1's not more than 1 
            // which means 
                if((mat[i][j] == 1) && (countRow[i] == 1) && (countCol[j] == 1)){
                    count++;
                }
            }
           }
           return count;
    } 
};