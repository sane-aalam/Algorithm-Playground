
// step by step solve this problem
// every Index you have choice 
//    first choice you have this currentElement * 2
//    second choice you have this curretnElement * 3
//    third choice you have this currentElement * 5
//    *jahan choice hay, wahan dp hai 
// ! dry run pending or this problem 


class Solution {
public:
    int nthUglyNumber(int n) {
        
        // let's directly memorize our code
        vector<int> dp(n+1,0);

        // at least on price factors can be happend
        dp[0] = 1;
        int x = 0;
        int y = 0;
        int z = 0;

        for(int i = 1; i<=n; i++){
            // all choices we have 
            int first_choice = dp[x] * 2;
            int second_choice = dp[y] * 3;
            int thrid_choice = dp[z] * 5;

            // minimum first put into the dp
            dp[i] = min(first_choice,min(second_choice,thrid_choice));
            if(dp[i] == first_choice) x++;
            if(dp[i] == second_choice) y++;
            if(dp[i] == thrid_choice) z++;
        }
        return dp[n-1];
    }
};