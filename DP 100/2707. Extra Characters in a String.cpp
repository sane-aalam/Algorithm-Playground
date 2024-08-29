// 2707. Extra Characters in a String

class Solution {
    int dp[51];
    int helper(int index, string s, unordered_set<string> & unset ){
          
          // base condition - if you have traversal the complete string, Then return true;
          if (index == s.size()) 
                return 0;
           
          if(dp[index] != -1) 
              return dp[index];

          string curr = "";
          int minExtraChar = s.length();

          for(int nextIndex = index; nextIndex <= s.length(); nextIndex ++){
            curr += s[nextIndex];
            int currSize = curr.size();

            // if curr-substring is present into set, currSize = 0; 
            if(unset.count(curr)){
                currSize = 0;
            }

// We can break s in two substrings: "hello" from index 3 to 7 and "world" from index 8 to 12. The characters at indices 0, 1, 2 are not used in any substring and thus are considered as extra characters. Hence, we return 3.
            int remeningSize = helper(nextIndex+1,s,unset); // call for baki sab ke liye

            int total = currSize + remeningSize;
            minExtraChar = min(minExtraChar, total);
          }

          return dp[index] = minExtraChar;
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> unset;
        for(auto it : dictionary){
            unset.insert(it);
        }

        int index = 0;
        // memorization of dp array - only one variable change so 1D array need to chache 
        memset(dp,-1,sizeof(dp));
        return helper(index,s,unset);
    }
};