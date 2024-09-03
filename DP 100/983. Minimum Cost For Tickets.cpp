// According to problem statement 
// we have three choices -
/*
    a 1-day pass is sold for costs[0] dollars,
    a 7-day pass is sold for costs[1] dollars, and
    a 30-day pass is sold for costs[2] dollars.
*/

// Jahan choice wahan DP (Fun ways note making)
// plan1 = cost[0] + solve(index+1);
// plan2 or plan3 you have to search that excat point of the array (days) which you have travel
// you have BinarySearch to search (Lower-bound STL) short way to search the element

// instant of using binary search
// just we are using STL
// there are 3 possible choice, we have 
// make sure (seaching limit of the days) using bianry search 
// int oneDaysIndex = upper_bound(days.begin(), days.end(), days[index]+0)-days.begin();


class Solution {
private:
    int dp[365];
    int solver(int index,vector<int> & days, vector<int> & costs){
        // trips is finished
        // base condition 
        if(index >= days.size()){
            return 0;
        }

        if(dp[index] != -1){
            return dp[index];
        }

        // choice-1 a 1-day pass is sold for costs[0] dollars,
        int one = costs[0] + solver(index+1,days,costs);

        // choice-2 a 7-day pass is sold for costs[1] dollars, and
        int SevenDaysIndex = lower_bound(days.begin(), days.end(), days[index] + 7) - days.begin();
        int week = costs[1] + solver(SevenDaysIndex, days, costs);

        // choice-3 a 30-day pass is sold for costs[2] dollars.
        int thirtyDaysIndex = lower_bound(days.begin(), days.end(), days[index] + 30) - days.begin();
        int month = costs[2] + solver(thirtyDaysIndex,days,costs);

        // return mininum cost)
        int minimumCost =  min({one,week,month});
        return dp[index] = minimumCost;
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
         int index = 0;
         memset(dp,-1,sizeof(dp));
         return solver(index,days, costs);
    }
};

