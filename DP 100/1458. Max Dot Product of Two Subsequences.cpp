
// Why DP > choices we have ): 
// pick the current element + sovle(i+1,j+1)
// skip the first element
// skip the second element 

// A subsequence of a array is a new array which is formed from the original array 
// recursion 

class Solution {

    int solve(int i, int j,vector<int>& nums1, vector<int>& nums2, vector<vector<int>> &dp){
        if(i >= nums1.size() or j >= nums2.size()){
            return INT_MIN;
        }

        // memoriztion of recursive calls
        // 0(1) time complexity take to re-use the recursive calls into chace memory
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        // to handling the negative value,
        // we have to add max(0,-1) = 0 
        // we have to avoid negative value
        // There are four choices we have, ( pick or not pick appraoch hi hay)
        int first_choice = nums1[i] * nums2[j] + max(0,solve(i+1,j+1,nums1,nums2,dp));
        int second_choice = solve(i+1,j,nums1,nums2,dp);
        int thrid_choice = solve(i,j+1,nums1,nums2,dp);
        int final_result =  max(first_choice,max(second_choice,thrid_choice));

        return dp[i][j] = final_result;
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {

         int n = nums1.size();
         int m = nums2.size();

         vector<vector<int>> dp(n,vector<int> (m,-1));
         int i = 0;
         int j = 0;
         int result = solve(i,j,nums1,nums2,dp);
         return result;
    }
};


  