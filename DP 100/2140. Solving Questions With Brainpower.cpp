

/*
You are given a 0-indexed 2D integer array questions where questions[i] = [pointsi, brainpoweri].

The array describes the questions of an exam, where you have to process the questions in order (i.e., starting from question 0) and make a decision whether to solve or skip each question. 
Solving question i will earn you pointsi points but you will be unable to solve each of the next brainpoweri questions. 
If you skip question i, you get to make the decision on the next question.
*/

// solve the problem + next call(on the based of the brainpower value + 1)
// skip the problem 
// keep it simple 

class Solution {
private:
    long long helper(int index, int n, vector<vector<int>> & q, vector<long long>&dp){

        if(index >= n){
            return 0;
        }
        // memorization [recursive calls]
        if(dp[index] != -1){
            return dp[index];
        }

        long long solve_problem = q[index][0] + helper(index+q[index][1] +  1, n, q,dp);
        long long skip_problem = 0 + helper(index+1,n, q, dp);

        // maximum points you can earn for the exam.
        dp[index] = max(solve_problem, skip_problem);
        return dp[index];
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int index = 0;
        int n = questions.size();
        vector<long long> dp(n+1,-1);
        return helper(index,n,questions,dp);
    }
};