
// In other words, let k be the maximum value of the bitwise AND of any subarray of nums. Then, only subarrays with a bitwise AND equal to k should be considered.
//the length of the longest such subarray.


//----------------------Dry-Run---------------------------------
// please how to convert binary to decimal
// please how to convert decimal to binary
// all operation of AND,OR,NOT (thoery based)
// number1 & number2 (Do number of AND opreation karne kabhi humne jo value milege wo number1 or number2 se kam hi milyegi)
// number 1 & number 2 <= value 
// longest subarray, having maxValue (Hit) to solve
// This is not bit manuplation problem , actually This just array problem 
// Medium to easy [convert]
// currentValue continously kitne var aya ahai 

class Solution {
    public int longestSubarray(int[] nums) {
        int maxValue = 0;
        int result = 0;
        int streak = 0;

        for(int i = 0; i<nums.length; i++){
            if(nums[i] > maxValue){
                maxValue = nums[i];
                result = 0;
                streak = 0;
            }
            // you have got same element coutinously then increase the count
            if(maxValue == nums[i]){
                streak++;
            }else{
                // break the streak;
                streak = 0;
            }
            // Java, i am learning basic, 
            // nothing is new, same to same code
            result = Math.max(result,streak);
        }
        return result;
    }
}