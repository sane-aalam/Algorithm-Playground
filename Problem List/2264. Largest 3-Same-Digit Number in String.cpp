
// Algorithm of this problems 
// currentElement = currentElement + 1 == currentElement + 2
// all elemenet have unique (same element), Then we have to pick maximum string 
// first we have to find the maximum char, then we can generate the 3 length string using 
// STIRING METHOD -> string(3,"ch")

class Solution {
public:
    string largestGoodInteger(string nums) {
    
        int ans = -1;
        string finalResult = "";

        // currentElmenet = privousElement = privouse ka privourse se complare karke dekh liya 
        // i = 2 < lastIndex to complare
        
        for(int i = 2; i<nums.size(); i++){
            // follow all rules of the string then you need to?
            if(nums[i] == nums[i-1] and nums[i] == nums[i-2]){
                // pick the 3 size of substring into the orignal string 
                string sub = nums.substr(i-2,3);
                int curr = stoi(sub); // convert into the integer 

                // Return the maximum good integer as a string
                // Inorder to find maximum good integer to maintain!
                if(curr > ans){
                    ans = curr;
                    finalResult = sub;
                }
            }
        }
        return finalResult;
    }
};