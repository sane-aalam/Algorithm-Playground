
// Dp on string

// point- 
//* you have reached s3 is completed traversed
/* base case - b - if s1 is finished and current 
        character of s2 doesn't matches with s3's current character. */
/* base case - c - if s2 is finished and current 
        character of s1 doesn't matches with s3's current character. */
//base case - d - If neither s1[i] nor s2[j] matches with s3[k], return false
class Solution {
private:
   int n,m,p;
   int dp[101][101][201];
   bool helper(int i, int j, int k, string s1, string s2, string s3){

        // traverse completed s3 string using a + b is the concatenation of strings a and b.
        if(k == p) 
             return true;

        // memorization for Memory Limit Exceeded
        if(dp[i][j][k] != -1){
            return dp[i][j][k];
        }

        if(i == n && s2[j] != s3[k]) 
            return false;
        if(j == m && s1[i] != s3[k]) 
             return false;
        if(s1[i] != s3[k] && s2[j] != s3[k]) 
              return false;

     // case-1 [string s1 char is equal to s3 char but string s2 char is not equal to string 3]
     // case-2 [s2 is equal s3] but [s1 is not equal to s3]
     // case-3 [both of possiblity can happens]

     // create the TREE-Diagram for better understanding [rivision time]
        bool result = false;
        if(s1[i] == s3[k] && s2[j] != s3[k]){
             result = helper(i+1,j,k+1,s1,s2,s3);
        }else if(s2[j] == s3[k] && s1[i] != s3[k]){
            result = helper(i,j+1,k+1,s1,s2,s3);
        }else{
            result = helper(i+1,j,k+1,s1,s2,s3) || helper(i,j+1,k+1,s1,s2,s3);
        }
        
        return  dp[i][j][k] = result;
   }
public:  
   // make array element is equal uski tarah same to same (pattern)
    bool isInterleave(string s1, string s2, string s3) {
         n = s1.size();
         m = s2.size();
         p = s3.size();

         memset(dp,-1,sizeof(dp));

         // Length is not equal
         if(n + m != p) 
              return false;

         return helper(0,0,0,s1,s2,s3);
    }
};