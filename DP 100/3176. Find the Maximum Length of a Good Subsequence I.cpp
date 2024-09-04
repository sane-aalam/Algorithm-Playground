
// if currentElement is same to prevElement
// on the basic of prevElement we have to pick the currentElement

class Solution {
private:
    // 1 <= nums.length <= 500
    // 0 <= k <= min(nums.length, 25)
    int dp[505][505][26];
    int solve(int index, int prev, int steps, vector<int> & nums){
         if(index >= nums.size())
           return 0;

         if(dp[index][prev+1][steps] != -1){
            return dp[index][prev+1][steps];
         }
        
         int pick = 0;
         int notpick = 0;
         notpick = solve(index+1,prev,steps,nums);

        // currentIndex = index+1 (become)
        // prevIndex = index (become)
         if(prev == -1 or nums[index] == nums[prev]){
            pick = 1 + solve(index+1,index,steps,nums);
         }else if(steps > 0){
            pick = 1 + solve(index+1,index,steps-1,nums);
         }

         return  dp[index][prev+1][steps] = max(pick, notpick);
    }
public:
    int maximumLength(vector<int>& nums, int k) {
        int index = 0;
        int prev = -1;

        // fill dp 3-d Array using -1 
        for(int i = 0; i<501; i++){
            for(int j= 0; j<501; j++){
                for(int k = 0; k<26; k++){
                    dp[i][j][k] = -1;
                }
            }
        }

        // you can use memset in STL
        // memset(dp,-1,sizeof(dp));
        return solve(index,prev,k,nums);
    }
};

