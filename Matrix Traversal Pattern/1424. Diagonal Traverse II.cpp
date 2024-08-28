
// Map
// Queue
// Priorty_queue [reason is sorted order matrix, we can think about the heap]

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        queue<pair<int,int>> q;
        int n = nums.size();
        vector<int> result;
        q.push({0,0});

        while(!q.empty()){

        // take the curernt row, current col,
        // push into the result array 
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            result.push_back(nums[row][col]);
            // first you need to go down of matrix cell, [down to up] you can see clearly into the matrix
            // so first you need to go down, Then you need to go right direction 
            // make sure, not gonna to out of bounary of the matrix 
            if(col == 0 && row+1 < n){
                q.push({row+1,col});
            }
            // right size traversal 
            if(col+1 < nums[row].size()){
                q.push({row,col+1});
            }
        }
        return result;
    }
};