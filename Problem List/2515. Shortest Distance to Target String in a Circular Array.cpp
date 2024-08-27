
/*
You are given a 0-indexed circular string array words and a string target. A circular array means that the array's end connects to the array's beginning.

Formally, the next element of words[i] is words[(i + 1) % n] and the previous element of words[i] is words[(i - 1 + n) % n], where n is the length of words.
*/

class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
         int n = words.size();
         int ans = INT_MAX;
         for(int i =0; i<n; i++){
            if(words[i] == target){

                // pick starting of index string
                // pick last of index of string
                int first_take = abs(i-startIndex);
                int last_take = n - abs(i - startIndex);
                ans = min({first_take,last_take,ans});
            }
         }
         
         if(ans == INT_MAX) return -1;
         return ans;
    }
};