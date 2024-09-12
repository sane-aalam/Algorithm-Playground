class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
         
        //case-1  suppose you can't create the matrix
        // both size are not equal then not possible to create matrix
        if(m * n != original.size()){
              return {};
        }

        //case-2 size is not equal to (n*m)
         int insertIndex = 0;
         vector<vector<int>> ans(m, vector<int>(n));

         for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                ans[i][j] = original[insertIndex];
                insertIndex++;
            }
         }
         return ans;
    }
};