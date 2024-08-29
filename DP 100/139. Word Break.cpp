
// recursion solution 


// Intuition
// Think like child, try all possible way to break down string, checking into wordDict
// if current-substring is present + call for remening part

// Algorithm [Think like child]
// 1. create the unorderset to easy search sub-string
// 2. break down, every possible way [each index]
// 3. if you found the current-String is set, Then call for remaning substring, to next char is present or not 

// case-1 full string can be present into map
// case-2 segment kar ke present ho into map

class Solution {
private:
    bool helper(int index, string s, unordered_set<string> & unset ){
          
          // base condition - if you have traversal the complete string, Then return true;
          if(index > s.length()){
            return true;
          }

          // full string can be present into map
          if(unset.find(s) != unset.end()){
            return true;
          }

          for(int nextIndex = 1; nextIndex <= s.length(); nextIndex ++){
            // s can be segmented, substr C++ Method to get string [currentIndex, lastIndex]
            // we have to check out this, current string is present into the SET[map]
             string curr = s.substr(index, nextIndex);
             // why index+nextIndex = (utne tak mila gaya na bhai)
             if(unset.find(curr) != unset.end() && helper(index+nextIndex,s,unset)){
                return true;
             }
          }
          return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {

     // creation of unordered_set
        unordered_set<string> unset;
          for(auto it : wordDict){
            unset.insert(it);
          }
        int index = 0;

        // vector<int> dp(301, -1);
        return helper(index,s,unset);
    }
};

//------------------------------- Dp solution to reduce overlapping sub-problem -------------------------------
// Intuition
// Think like child, try all possible way to break down string, checking into wordDict
// if current-substring is present + call for remening part

// Algorithm [Think like child]
// 1. create the unorderset to easy search sub-string
// 2. break down, every possible way [each index]
// 3. if you found the current-String is set, Then call for remaning substring, to next char is present or not 

// case-1 full string can be present into map
// case-2 segment kar ke present ho into map

class Solution {
private:
    int dp[301];
    bool helper(int index, string s, unordered_set<string> & unset ){
          
          // base condition - if you have traversal the complete string, Then return true;
          if(index >= s.length()){
            return dp[index] = true;
          }

          // full string can be present into map
          if(unset.find(s) != unset.end()){
            return true;
          }

           
          if(dp[index] != -1) 
              return dp[index];

          for(int nextIndex = 1; nextIndex <= s.length(); nextIndex ++){
            // s can be segmented, substr C++ Method to get string [currentIndex, lastIndex]
            // we have to check out this, current string is present into the SET[map]
             string curr = s.substr(index, nextIndex);
             // why index+nextIndex = (utne tak mila gaya na bhai)
             if(unset.find(curr) != unset.end() && helper(index+nextIndex,s,unset)){
                return dp[index] =  true;
             }
          }
          return dp[index] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {

     // creation of unordered_set
        unordered_set<string> unset;
          for(auto it : wordDict){
            unset.insert(it);
          }

        memset(dp,-1,sizeof(dp));
        int index = 0;
        return helper(index,s,unset);
    }
};