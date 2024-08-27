// 3254. Find the Power of K-Size Subarrays I
// 3254. Find the Power of K-Size Subarrays 2
// same appraoch solved 2 problems 

//* pre-processing appraoch

// 1.consecutiveLength array to maintain the asecending order ()
//    if(arr[i] == arr[i-1] + 1) 
//    incease the consectuive ness by 1
//    maximum element according store all consecutiveLength ness of each element 

// 2. according to consective arary element consective value greater than >= k
//     its elements are consecutiveLength and sorted in ascending order.
//     else we need to store ( -1 ) otherwise.


class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
         int n = nums.size();
         // by default each element have 1 consective ness 
         // i am think like solving dp 

         vector<int>consecutiveLength(n,1);

         for(int i = 1; i<n; i++){
            // consecutiveLength ness (1<2<3<4<5)
            // currentElement = privoursElement + 1
            if(nums[i] == nums[i-1] + 1){
                // mistake i am doing += 
                consecutiveLength[i] += consecutiveLength[i-1]; 
            }
         }

         // 2. according to consective arary element consective value greater than >= k
        //     its elements are consecutiveLength and sorted in ascending order.
        //     else we need to store ( -1 ) otherwise.

        vector<int> ans;
        for(int i=k-1;i<n;i++){
            if(consecutiveLength[i]>=k){
                ans.push_back(nums[i]);
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};