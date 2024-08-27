class Solution {
private:
    bool solve(int index, vector<int> & nums, vector<int> & dp){

        int n = nums.size();

        // base condition
        if(index >= n){
            return true;
        }

        // Number of overlapping problem 
        // To reduce the overlapping problem - memorization of code
        if(dp[index] != -1){
            return dp[index];
        }

        int ans = false;

        // Rule-1 
        // The subarray consists of exactly 2, equal elements. For example, the subarray [2,2] is good.
        // why (i+1 < n)
        // why (i+2 < n)
        // before comparing the next element, really avaiable next element or not 
        if(index + 1 < n){
                if(nums[index] == nums[index+1]){
                int nextIndex = index+2;
                ans = solve(nextIndex,nums,dp);
                if(ans == true){
                    return true;
                }
            }
        }
        // Rule-2
        // The subarray consists of exactly 3, equal elements. For example, the subarray [4,4,4] is good.
        if(index +2 < n){
                if(nums[index] == nums[index+1] && nums[index] == nums[index+2]){
                int nextIndex = index+3;
                ans = solve(nextIndex,nums,dp);
                if(ans == true){
                    return ans;
                }
            }
        }

        // Rule-3
        // The subarray consists of exactly 3 consecutive increasing
        // 0 base indexes interger array, next call(0,1,2) -> f(3)
        // valid range of element + rule-3 follow karna chaiye 
        if(index + 2 < n){
              if(nums[index+1] - nums[index] == 1 &&  nums[index+2] - nums[index+1] == 1){
                int nextIndex = index+3;
                ans = solve(nextIndex, nums,dp);
                if(ans == true){
                    return ans;
                }
           }
        }
        return dp[index] = ans;
    }
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        int index = 0;

        // Trust on yourself
        // Trust on practice session 
        // you will win one Day!

        vector<int> dp(n+1,-1);
        bool result = solve(index, nums,dp);
        return result;
    }
};



//* Tabulation solution 

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n+1,false);
        dp[0] = true;

        // if two element are equal then 
        if(nums[1] == nums[0]){
            dp[2] = true;
        }

        for(int i = 2; i<n; i++){
            // previous compulate value se check karte jana for all three condtion follow 
            // case1 - compare with 2 equal elements
            if(nums[i] == nums[i-1]){
                dp[i+1] = dp[i+1] or dp[i-1];
            }
            // case2 - when three 3 elements are equal
            if(nums[i] == nums[i-1] and nums[i] == nums[i-2]){
                dp[i+1] = dp[i+1] or dp[i-2];
            }
            // case3 - when three 3 are eqaul with increase order 
              if(nums[i] == nums[i-1] + 1 and nums[i] == nums[i-2] + 2){
                dp[i+1] = dp[i+1] or dp[i-2];
            }
        }
        return dp[n];
    }
};