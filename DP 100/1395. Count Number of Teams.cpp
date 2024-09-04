
/*
There are n soldiers standing in a line. Each soldier is assigned a unique rating value.

You have to form a team of 3 soldiers amongst them under the following rules:

Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).
*/

// Bruthforce solution 
class Solution {
public:
    int numTeams(vector<int>& rating) {
        //  bruthforce 
        int n = rating.size();
        int count = 0;

        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                for(int k = j+1; k<n; k++){
                    // if it can be valid Team
                    // 4 < 5 && 5 < 6 (4,5,6) can be valid team
                    // 3 > 4 && 4 > 5 (5,4,2) can ve valid team
                    if((rating[i] < rating[j] && rating[j] < rating[k]) or
                     (rating[i] > rating[j] && rating[j] > rating[k])){
                        count++;
                     }
                }
            }
        }

        return count;
    }
};

// optimizatoin solution using DP

// increment order me can be created Teams
// Decrement order me can be created Teams 
// (5,4,1)
// (2,3,4) 
// we have to write two function to count number of teams

// Intution to solve this problem 
// on the basic of prev Element is part of teams
// it can be not part of team

// increment order me can be created Teams
// Decrement order me can be created Teams 
// (5,4,1)
// (2,3,4) 
// we have to write two function to count number of teams

// Intution to solve this problem 
// on the basic of prev Element is part of teams
// it can be not part of team

class Solution {
private:
    int incrementOrderTeams(int index, int prev, int count, int n, vector<int> & rating){
        if(count == 3) return 1;
        
        if(index >= n){
            return 0;
        }
        int pick = 0;
        int notpick = 0;
        // stiver appraoch[dp](take or not take)
        // currentElement > prevElement is greater,Then it can be part of Teams
        if(prev == -1 or rating[index] > rating[prev]){
            pick = incrementOrderTeams(index+1, index,count+1,n,rating);
        }
        notpick = incrementOrderTeams(index+1, prev,count,n,rating);
        
        // step-3 sum up all teams 
        int NumberTeams = pick + notpick;
        return NumberTeams;
    }
     int decrementOrderTeams(int index, int prev, int count, int n, vector<int> & rating){
        // base condtino 
        // Lecture-7 recursion [can be one team created]
        if(count == 3) 
            return 1;
        if(index >= n){
            return 0;
        }
        int pick = 0;
        int notpick = 0;
        // stiver appraoch[dp](take or not take)
        // step-1 it can be part of subsquence
        // currentElement < prevElement is smaller,Then it can be part of Teams
        if(prev == -1 or rating[index] < rating[prev]){
            pick = decrementOrderTeams(index+1, index,count+1,n,rating);
        }
        notpick = decrementOrderTeams(index+1, prev,count,n,rating);
        
        // step-3 sum up all teams 
        int NumberTeams = pick + notpick;
        return NumberTeams;
    }
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int result = 0;
        int count1 = 0; // base conditon hits
        int count2 = 0;
        result = result + incrementOrderTeams(0,-1,count1,n,rating);
        result = result + decrementOrderTeams(0,-1,count2,n,rating);
        return result;
    }
};

// recursion + memo

// increment order me can be created Teams
// Decrement order me can be created Teams 
// (5,4,1)
// (2,3,4) 
// we have to write two function to count number of teams

// Intution to solve this problem 
// on the basic of prev Element is part of teams
// it can be not part of team

// to fix the error 
// prev+1 (off-set) - to manage negative index value

class Solution {
private:
    int dp1[1002][1002][4];
    int dp2[1002][1002][4];
    int incrementOrderTeams(int index, int prev, int count, int n, vector<int> & rating){
        if(count == 3) return 1;
        
        if(index >= n){
            return 0;
        }

        // memorization using DP1
        if(dp1[index][prev+1][count] != -1){
            return dp1[index][prev+1][count];
        }

        int pick = 0;
        int notpick = 0;
        // stiver appraoch[dp](take or not take)
        if(prev == -1 or rating[index] > rating[prev]){
            pick = incrementOrderTeams(index+1, index,count+1,n,rating);
        }
        notpick = incrementOrderTeams(index+1, prev,count,n,rating);
        
        // step-3 sum up all teams 
        int NumberTeams = pick + notpick;
        return dp1[index][prev+1][count] = NumberTeams;
    }
     int decrementOrderTeams(int index, int prev, int count, int n, vector<int> & rating){
        // base condtino 
        // Lecture-7 recursion [can be one team created]
        if(count == 3) 
            return 1;
        if(index >= n){
            return 0;
        }

        // memorization using DP1
        if(dp2[index][prev+1][count] != -1){
            return dp2[index][prev+1][count];
        }

        int pick = 0;
        int notpick = 0;
        // stiver appraoch[dp](take or not take)
        // step-1 it can be part of subsquence
        if(prev == -1 or rating[index] < rating[prev]){
            pick = decrementOrderTeams(index+1, index,count+1,n,rating);
        }
        notpick = decrementOrderTeams(index+1, prev,count,n,rating);
        
        // step-3 sum up all teams 
        int NumberTeams = pick + notpick;
        return  dp2[index][prev+1][count] = NumberTeams;
    }
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int result = 0;
        int count1 = 0; // base conditon hits
        int count2 = 0;

        // filling the dp array using -1
        memset(dp1,-1,sizeof(dp1));
        memset(dp2,-1,sizeof(dp2));

        result = result + incrementOrderTeams(0,-1,count1,n,rating);
        result = result + decrementOrderTeams(0,-1,count2,n,rating);
        return result;
    }
};