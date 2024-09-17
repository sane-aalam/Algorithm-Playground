
// Input: nums = [100,1,10]
// Output: 9
// Explanation: We can partition the array nums into nums1 = [10] and nums2 = [100,1].
// - The maximum element of the array nums1 is equal to 10.
// - The minimum element of the array nums2 is equal to 1.
// The value of the partition is |10 - 1| = 9.
// It can be proven that 9 is the minimum value out of all partitions.

// No need to divide into two half 
// Just need to sort the array = [1,10,100]
// adjency element difference nikal lo
// firsttime = min(10-1) = 9;
// secondTime = min(100-10) = 90;
// har var maximum element or miniumElement diffrenecy nikal rahe hai


class Solution {
public:
    int findValueOfPartition(vector<int>& nums){
        sort(nums.begin(),nums.end());

        int minimum_diff_value = INT_MAX;
        for(int i = 1; i<nums.size(); i++){
            int curr_diff_value = nums[i] - nums[i-1];
            // we want to minimum diff value 
            // jo sabe minimum ho
            minimum_diff_value = min(minimum_diff_value,curr_diff_value);
        }
        return minimum_diff_value;
    }
};