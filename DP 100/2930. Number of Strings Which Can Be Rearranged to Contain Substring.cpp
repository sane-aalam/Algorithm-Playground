
// ----------------------Most peoples confused [lack of understading of recursion] -----------------------
// How it will works
// How it will be done
// How this will happing
// Lack of trust of recusion fuction
// So, you have to understand recursive leaf of faith 
// step1 (recursive) -> step2 (DP)

// problem statemnet (Hits)
// A good string must contain at least one l, one t, and two (e) Means you can get 1 string which as substring 
// Socho Ek case
// Jab tumhe 'one l mil gaya
// Jab Tumhe 'two E mil gayi
// Jab Tumhe 'one T mil gayi 
// uske baad jitne bhi milige ek bar hi count me aayige 
// no need to go behide the limit (1,2,1)

class Solution {
private:
     // good string can be (one-l) and (one-t) and (two-e)
     // count the nubmer of string which can be contain (leet) as substring
     // to generate the all the substring + sum of all the substring
    int dp[100001][2][3][2];
     int mod = 1000000007;
     int helper(int index, int l, int e, int t, int n){
         // base case -
         // return the control of program,where the fuction is envoked 
         if(index == n){
            // which means you have genarate the 1 strings which have substring(leet)
            if(l == 1 and e == 2 && t == 1){
                return 1;
            }
            return 0;
         }

         if(dp[index][l][e][t] != -1){
            return dp[index][l][e][t];
         }

         long long ways = 0;
         // it contains only lowercase English ('a' to 'z')
         for(char ch = 'a'; ch <= 'z'; ch++){
            // there are three case can be ::
            // it can be l
            // it can be e
            // it can be t 
            if(ch == 'l'){
                // count (L) increase by 1, same for (E)(T)
                // Why min(becuase we only want minimum 2 (E)), no need to go deep 
             ways += helper(index+1,1,e,t,n) % mod;
            }else if(ch == 'e'){
             // clear code
             int LimitTwo = min(e+1,2);
             ways += helper(index+1,l,LimitTwo,t,n) % mod;
            }else if(ch == 't'){
             ways += helper(index+1,l,e,1,n) % mod;
            }else{
             ways += helper(index+1,l,e,t,n) % mod;
            }
         }
         return dp[index][l][e][t] = ways % mod;
     }
public:
    int stringCount(int n) {
         int index = 0;

         // to count the nubmer of L,E,T, When we are generating the substing which have these char's
         int l = 0;
         int e = 0;
         int t = 0;
         // helper(0-N) 
         // have trust it will give answer 

        // there are 4 variable are changed
        // we need to 4-D dp, we have to create 4-d array 
        // fill the entire the dp array using -
         memset(dp,-1,sizeof(dp));

         int ans = helper(index,l,e,t,n);
         return ans;
    }
};