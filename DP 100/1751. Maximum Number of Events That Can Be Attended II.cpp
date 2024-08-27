
// Hard problem breakdown into subproblem

// The main idea is to ensure that the index we are currently on can be taken into consideration.
// Intuitively, the first index can always be taken, and then we ensure that we move only to a valid next index.
// Other parts of the solution are simple take/notTake and memoization.

// Hard to easy [become] - steps to requrie 
// point-1 : You are given an array of events where events[i] = [startDayi, endDayi, valuei]
// point-2 : if you attend this event, you will receive a value of valuei.
// point-3 : you are also given value k, if you have attend the events, reduce the value of k 
// point-4 : return [the maximum number of events you can attend ] 

// should make sure [Interval base problem]
// if you have attend event on time[1,2]
// so next event , you can not attend on the time [1,2], only possible[3,4,5]..

// Note that the end day is inclusive: that is, you cannot attend two events where one of them starts and the other ends on the same day.

class Solution {
private:
    int solve(int index, vector<vector<int>> & events, int k,vector<vector<int>> & dp){
        if(index == events.size()){
            return 0;
        } 

        // point-3 you are also given value k,
        // there is no events k == 0
        // not possible to perfrom the events 
        if(k <= 0) return 0;

        // memorization of recursive calls 
        if(dp[index][k] != -1){
            return dp[index][k];
        }

        // store the startTime,EndTime, value 
        int startTime = events[index][0];
        int endTime = events[index][1];
        int value = events[index][2];


        // for next events, attending, find the next correct position to take events
        // current endTime < next day [start Time] [greater]
        // Then only you can take Events 
        int i;
        for( i = index+1; i < events.size(); i++){
            if(events[i][0] > endTime){
                break;
            }
        }

        // House robber-1 [pick or not pick the events on the basic of interval]
        int notAttendEvent = 0 + solve(index+1,events,k,dp);
        int attendedEvent = value + solve(i,events,k-1,dp);
        return dp[index][k] = max(notAttendEvent,attendedEvent);
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        //sort events by startTimes
        sort(events.begin(),events.end());

        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        int index = 0;
        int maximumSum =  solve(index,events,k,dp);
        //  the maximum sum of values that you can receive by attending events.
        return maximumSum;
    }
};