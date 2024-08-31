
// Stiver [steps to solve any dp problem]
// 1. Express everything is terms of indexes
// 2. explore all possiblity
// 3. find maximum 

// recusion + memorizatoin 

class Solution {
private:
    int play(int index,vector<int>& arr, int n, vector<int> & dp ){
        if(index >= n) return 0;
        if(dp[index] != -1) return dp[index];
        int result = arr[index] - play(index+1,arr,n,dp);
        // make sure before calling next index is present or not
        if(index+2 <= n){
            result = max(result,arr[index]+arr[index+1]- play(index+2,arr,n,dp));
        }
        if(index+3 <= n){
            result = max(result,arr[index]+ arr[index+1] + arr[index+2] - play(index+3,arr,n,dp));
        }
        return dp[index] = result;
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int index = 0;
        int n = stoneValue.size();
        vector<int> dp(n+1,-1);
        int win = play(index,stoneValue,n,dp);
        if(win > 0) return "Alice";
        if(win < 0) return "Bob";
        return "Tie";
    }
};


// Tabulation [n-1 to 0 index fill dp array]

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n+1);
        
        for(int index = n-1; index >= 0; index--){
             int result = stoneValue[index] - dp[index+1];
             if(index+2 <= n){
                    result = max(result,stoneValue[index]+stoneValue[index+1]- dp[index+2]);
                }
            if(index+3 <= n){
                    result = max(result,stoneValue[index]+ stoneValue[index+1] + stoneValue[index+2] - dp[index+3]);
            }
            dp[index] = result;
        }

        int win = dp[0];
        if(win > 0) return "Alice";
        if(win < 0) return "Bob";
        return "Tie";
    }
};

// best code - space optimization 
// tc - 0(n)
// sc - 0(1)

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

    // space optmization 
    // we don't need to use dp array
    // we can just used [prev1,prev2,prev3] value to calculate the currentValue
    // just pointer-famous [you have learned into takeuforward lecture]
        int curr = 0;
        int prev1 = 0;
        int prev2 = 0;
        int prev3 = 0;

        for(int index = n-1; index >= 0; index--){
             int result = stoneValue[index] - prev1;
             if(index+2 <= n){
                    result = max(result,stoneValue[index]+stoneValue[index+1]- prev2);
                }
            if(index+3 <= n){
                    result = max(result,stoneValue[index]+ stoneValue[index+1] + stoneValue[index+2] - prev3);
            }
            curr = result;
            prev3 = prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        int win = curr;
        // Alice-bob [difference value represent the result of the problem]
        if(win > 0) return "Alice";
        if(win < 0) return "Bob";
        return "Tie";
    }
};