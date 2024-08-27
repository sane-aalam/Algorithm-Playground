class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
         int result = 0;

         // Array
        // Hash Table + Dynamic Programming
         unordered_map<int,int> mpp;

         for(int i = 0; i < arr.size(); i++){
              int current = arr[i];
              int prev = current - difference;
              // get the pahle ki lenght into hashamp 
              int prevLen = mpp[prev];
              
              // [1,2,3,]
              // newElement 4 is part of subsequence so, lenght prevLen + 1
              int currentLen = prevLen + 1;
              mpp[current] = currentLen;

              result = max(result,currentLen);
         }
         return result;
    }
};