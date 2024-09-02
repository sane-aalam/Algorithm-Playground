// 213. House Robber II

class Solution {
private:
    int HouseRobberFunction(vector<int>& nums) {
        int n = nums.size();
        
        int prev_i = nums[0];
        int prev2_i = 0;
        int curr_i = 0;

        for(int i = 1; i<nums.size(); i++){
            int pick = nums[i];
            if (i > 1)
                  pick += prev2_i;
             int notPick = 0 + prev_i;
            // maximum amount of money you can rob tonight
            curr_i = max(pick,notPick);
            prev2_i = prev_i;
            prev_i = curr_i;
        }

        return prev_i;
    }
public:
    int rob(vector<int>& nums) {
        vector<int> temp1;
        vector<int> temp2;
        
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        for(int i=0; i<n; i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }

        // →  All houses at this place are arranged in a circle.
        // → it will automatically contact the police if two adjacent houses were broken into on the same night.

        int SkipFirstElementResult = HouseRobberFunction(temp1);
        int SkipLastElementResult = HouseRobberFunction(temp2);
        int maximumProfitRobber =  max(SkipFirstElementResult,SkipLastElementResult);
        return maximumProfitRobber;
    }
};