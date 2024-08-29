class Solution {
public:
    int thirdMax(vector<int>& nums) {
         int n = nums.size();
         long long max1 = LONG_MIN , max2 = LONG_MIN , max3 = LONG_MIN;

         for(auto num : nums){
            if(num == max1 or num == max2 or num == max3){
                continue;
            }
            if(num > max1){
                max3 = max(max3,max2);
                max2 = max(max2,max1);
                max1 = num;
            }else if(num > max2){
                 max3 = max(max3,max2);
                 max2 = num;
            }else{
                 max3 = max(max3, (long long)(num));
            }
         }

         if(max3 != LONG_MIN) return max3;
         return max1;
    }
};