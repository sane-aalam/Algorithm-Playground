// sort the aray using comp function (based on two number)
// it will sort the array according to largest number
// combine them all number as string
// _to_string(num1) + _to_string(num2)

// agar sab zero hai answer 0 hoga
// [0,0] == "0" wrong anwer (test case - 229)
// result[0] == '0' return "0"


class Solution {
private: 
    // comp function used here
    bool static comp(int num1, int num2){
        string st1 = to_string(num1);
        string st2 = to_string(num2);
        string s = st1  + st2;
        string z = st2 + st1;
        return s > z;
    }
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), comp);
        
        string result;
        for(int i = 0; i<n; i++){
            // push har number into resut string ke andar
            result += to_string(nums[i]);
        }
        if(result[0] == '0'){
            return "0";
        }
        return result;
    }
};