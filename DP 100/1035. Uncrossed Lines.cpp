// Problem statement 
/*
- You are given two integer arrays nums1 and nums2. 
- We write the integers of nums1 and nums2 (in the order they are given) on two separate horizontal lines.
- We may draw connecting lines: a straight line connecting two numbers nums1[i] and nums2[j] such that:
nums1[i] == nums2[j], and
the line we draw does not intersect any other connecting (non-horizontal) line.

Note that a connecting line cannot intersect even at the endpoints (i.e., 
each number can only belong to one connecting line).
Return the maximum number of connecting lines we can draw in this way.
 */

// Recursive solution 
// TakeUforward [Rules]
// 1. express everything in terms of index
// 2. explore all the possible ways (here we have nums are matched or not matched)
// 3. find maximum (of all ways)

private:
    int helper(int i, int j, int n, int m, vector<int> & arr1, vector<int> & arr2){

        if(i == n or j == m){
            return 0;
        }


        if(arr1[i] == arr2[j]){
            return 1 + helper(i+1,j+1,n,m,arr1,arr2);
        }else{
            int skip_first = helper(i+1,j,n,m,arr1,arr2);
            int skip_second = helper(i,j+1,n,m,arr1,arr2);
            return  max(skip_first,skip_second);
        }
    }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
         int i = 0;
         int j = 0;
         int n = nums1.size();
         int m = nums2.size();

         int result = helper(i,j,n,m,nums1,nums2);
         return result;
    }
};

// Memorization solution - reduce the time complexity 
class Solution {
private:
    int helper(int i, int j, int n, int m, vector<int> & arr1, vector<int> & arr2, vector<vector<int>> & dp){

        if(i == n or j == m){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(arr1[i] == arr2[j]){
            return 1 + helper(i+1,j+1,n,m,arr1,arr2,dp);
        }else{
            int skip_first = helper(i+1,j,n,m,arr1,arr2,dp);
            int skip_second = helper(i,j+1,n,m,arr1,arr2,dp);
            return dp[i][j] = max(skip_first,skip_second);
        }
    }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
         int i = 0;
         int j = 0;
         int n = nums1.size();
         int m = nums2.size();

         vector<vector<int>> dp(n+1, vector<int> (m+1,-1));
         int result = helper(i,j,n,m,nums1,nums2,dp);
         return result;
    }
};







// Tabulation code
// base condtion + recursive code convert into iterative code 

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
         int n = nums1.size();
         int m = nums2.size();

         int dp[n+1][m+1];
         // base conditon convert into the instillization
         for(int i = 0; i<=n; i++){
            for(int j = 0; j<=m; j++){
                if(i == 0 or j == 0){
                    dp[i][j] = 0;
                }
            }
         }

         // copy the recurrence relation 
         // according to changeable varaible run loop

          for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                // both are equal and both are not equal 
                // the line we draw does not intersect any other connecting (non-horizontal) line.
                if(nums1[i-1] == nums2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
         }
         return dp[n][m];
    }
};