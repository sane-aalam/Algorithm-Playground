// 664. Strange Printer

class Solution {
public:
    int n;
    int dp[101][101];
    int rec(string&s , int l , int r){
        if(l==r) return 1;
        if(l>r)  return 0;

        if(~dp[l][r])
          return dp[l][r];

        // find the index value
        // until you have got the same char 'aaaa'
        // basic - call for same char 
        // gredy - pahle hum sare "aaba" 
        int i = l+1;
        while(i<=r && s[i]==s[l]) 
           i++;

        if(i == r+1) 
            return dp[l][r]=  1;

        int basic = 1 + rec(s , i , r);

        int greedy = INT_MAX;

        for(int j = i ; j<=r ; j++){
            if(s[j]==s[l]){
                // 1 + kyo ni kara is the main catch
                // wo alredy ho jayega 
                // aaba (1) (1) (1) = but you have done only times for all a's 
                int ans = rec(s, i , j-1) + rec(s , j , r);
                greedy = min(ans , greedy);
            }
        }
        return dp[l][r] = min(greedy , basic);
    }
    int strangePrinter(string s) {
        memset(dp,-1,sizeof(dp));
        n = s.size();
        return rec(s,  0 , n-1);
    }
};