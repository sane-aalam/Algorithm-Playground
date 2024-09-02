

// ✅ Recursion soltuion
// Try to express everything in terms of indees
// Explore all possiblity
// find maximum 

// We have 3 possible choices for every index idx in rods array.
// Choice 1: take rods[idx] in stand1
// Choice 2: take rods[idx] in stand2
// Choice 3: reject rods[idx]
// So from this thought process we can think of a recursive solution that explores all these choices to find out the best answer. And because of the constraints of the problem the pure recursion will give TLE and so we will also optimise it later with memoization.


// Code - Don't submit this. It will give TLE ❌
class Solution {
private:
    int bluid(int l1, int l2, int index,vector<int>& rods){

        // base conditon
        if(index >= rods.size()){
            if(l1 == l2){
                return l1;
            }else{
                return 0;
            }
        }

        // 3 choice we have
        int op1 = bluid(l1+rods[index], l2, index+1, rods);
        int op2 = bluid(l1, l2+rods[index], index+1, rods);
        int op3 = bluid(l1, l2, index+1, rods);
        return max(op1,max(op2,op3));
    }
public:
    int tallestBillboard(vector<int>& rods) {
        int l1 = 0;
        int l2 = 0;
        int index = 0;
        return bluid(l1,l2,index,rods);
    }
};

// ❌  only few test cases passed so need to memorization
// but here there are 3 variable change, let's do memorization of our code
// 3 variable memorization gives our space compleixty error (❌)

// Explain it details
// you know basic Recusion solution gives you TLE ❌
// we have to memorization but 3d memoriztion also hou TLE ❌
// we should used 2d memoriztion to solve + manage the offset(add offset 5000),to make positive value, according to test cases ✅

// ✅ new way of think 3D memorization into 2D memorizatoin our code
// ✅ Diffence + offset teset cases for managemening the negative value
// ✅ Code - Accepted 
// l1 - l2 == 0, means equal length of both
// difference = (l1 - l2 ) should be zero
// difference + l2 = l1;
// difference - l1 = l2;


// Math way to think the solution ) 
// A - B = difference (10th class)
// l1 - l2 == 0, means equal length of both
// difference = (l1 - l2 ) should be zero
// difference + l2 = l1;
// difference - l1 = l2;
// There are three possible paths
// op1 = diff + rods[index]
// op2 = diff - rods[index]
// op3 = diff (reject kar diya)
// that is beauty of recursion!
// super question


class Solution {
private:
    int bluid(int index, int diff,vector<int>& rods,vector<vector<int>> &dp){
         
         // base conditon
         if(index == rods.size()){
            if(diff == 0){
                return 0;
            }else{
                return -1e9;
            }
         }

        // add offset (5000)
        if(dp[index][diff + 5000] != -1) {
            return dp[index][diff + 5000];
        }

        // explore all possible paths - there are three possible paths(takefirst,takesecond,nottake)
        // should track the current rods value, whenever we are taking first time
        int createRodFirst = rods[index] + bluid(index+1,diff+rods[index],rods,dp);
        int createRodSecond = bluid(index+1,diff-rods[index],rods,dp);
        int notRodTake = bluid(index+1, diff, rods,dp);

        // store the recusive calls
        return  dp[index][diff + 5000] = max(createRodFirst,max(createRodSecond,notRodTake));
    }
public:
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        vector<vector<int>> dp(n+1,vector<int>(10001,-1));

        int diff = 0;
        int index = 0;
        return bluid(index,diff,rods,dp);
    }
};







