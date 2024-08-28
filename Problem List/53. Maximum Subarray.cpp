
// Kadan's Algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int maximum_sum = INT_MIN;
        int current_sum = 0;
        
        for(int index = 0; index < nums.size(); index++){
            current_sum = current_sum + nums[index];
            if(current_sum > maximum_sum){
                maximum_sum = current_sum;
            }
            
            if(current_sum < 0){
                current_sum = 0;
            }
        }
        return maximum_sum;
    }
};