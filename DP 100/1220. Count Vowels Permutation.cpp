        // Cases - just write down using recursion 
        // Case 1. Each vowel 'a' may only be followed by an 'e'.
        // Case 2. Each vowel 'e' may only be followed by an 'a' or an 'i'.
        // Case 3. Each vowel 'i' may not be followed by another 'i'.
        // Case 4. Each vowel 'o' may only be followed by an 'i' or a 'u'.
        // Case 5. Each vowel 'u' may only be followed by an 'a'.
class Solution {
private: 
  int mod = 1e9+7;
   long long int solve(int index, char ch, int n,vector<vector<int>> & dp, unordered_map<char,int> & mp){
    
     if(index == n) 
           return 1;

     long long countVowels = 0;

     if(dp[mp[ch]][index] != -1){
        return dp[mp[ch]][index] % mod;
     }

     // power of recursive TREE
     // Recursive leaf of faith on the basic of conditions according to question
     if(ch == 'a'){
        countVowels += solve(index+1,'e',n,dp,mp);
     }else if(ch == 'e'){
        countVowels += solve(index+1,'a',n,dp,mp);
        countVowels += solve(index+1,'i',n,dp,mp);
     }else if(ch == 'i'){
        countVowels += solve(index+1,'a',n,dp,mp);
        countVowels += solve(index+1,'e',n,dp,mp);
        countVowels += solve(index+1,'o',n,dp,mp);
        countVowels += solve(index+1,'u',n,dp,mp);
     }else if(ch == 'o'){
        countVowels += solve(index+1,'i',n,dp,mp);
        countVowels += solve(index+1,'u',n,dp,mp);
     }else{
        countVowels += solve(index+1,'a',n,dp,mp);
     }
     return dp[mp[ch]][index] = countVowels % mod;
    }
public:
    int countVowelPermutation(int n) {
    
    // map to convert char to int for using in dp vector for memoization purpose
        unordered_map<char, int> mp;
        mp['a'] = 0;
        mp['e'] = 1;
        mp['i'] = 2;
        mp['o'] = 3;
        mp['u'] = 4;
        
        vector<vector<int>> dp(5, vector<int>(n+1, -1));

        // Try all possible ways (a,e,i,o,u)
        long long allPossibleWays =  
        solve(1,'a',n,dp,mp) + solve(1,'e',n,dp,mp) + solve(1,'i',n,dp,mp) + solve(1,'o',n,dp,mp)
                        + solve(1,'u',n,dp,mp);

        // Since the answer may be too large, return it modulo 10^9 + 7.
        return allPossibleWays % mod;
    }
};