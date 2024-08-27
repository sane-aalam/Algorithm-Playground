class Solution {
private:
    int solve(int start, int end, vector<int> & nums, vector<vector<int>>& dp){
        if(start == end){
            return nums[start];
        }

        if(start > end){
            return 0;
        }

        if(dp[start][end] != -1){
            return dp[start][end];
        }

        // Trust on yourself recursive function,just like you trust yourself
        // you are the master of your mind!
        
        // what we are doing 
        // takePlayer = [player1 value le liye] - [player2 value ki value] subtraction 
        
        int TakePlayerFirst = nums[start] - solve(start+1,end,nums,dp);
        int TakePlayerSecond = nums[end] - solve(start,end-1, nums,dp);
        return dp[start][end] =  max(TakePlayerFirst,TakePlayerSecond);
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;

       vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

// The game ends when there are no more elements in the array.
// Return true if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, and you should also return true. You may assume that both players are playing optimally.
       if(solve(start,end,nums,dp) >= 0){
       // player 1 will be winner then return true
           return true;
       }else{
       // player 1 will never be the winner and you need to return false.
            return false;
       }
    }
};