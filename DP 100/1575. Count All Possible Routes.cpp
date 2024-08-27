
//?** Hard problem breakDown 
// point-1 integers start, finish and fuel 
// point-2 want to reach start to finish point, reduce some fuel when you will move
// point-3  if you are at city i, you can pick any city j such that j != i and 0 <= j < locations.length
// point-4 reduces the amount of fuel you have by |locations[i] - locations[j]|
// point-5 you are allowed to visit any city more than once (including start and finish), you can start with again 0-index, run loop to traverse again

// ? points to convert into code
// we have choose,  count of all possible routes
// let's apply recursion + memorization of this problems

// ? Takeufoward Lecture-7 [recursion playList]
// count all possible subsequence 
// is possible return 1
// otherwise return 0

class Solution {
private:
 long dp[101][201], mod = 1e9 + 7;
   long helper(int currIndex, int & end, int fuel, vector<int> & locations){

        // There is no fuel remanining 
        if(fuel < 0) 
           return 0;
        // if(currIndex == end) return 1;

        //! When you have reached the conditon start == end
        //! rechedDistniation variable return 1, 0 
        bool rechedDestination = currIndex == end;

        if(dp[currIndex][fuel] != -1){
            return dp[currIndex][fuel];
        }

        long countRoutesAll = 0;

        for(int i = 0; i < locations.size(); i++){
    //* point-3  if you are at city i, you can pick any city j such that j != i and 0 <= j < locations.length  
    //* point-4 reduces the amount of fuel you have by |locations[i] - locations[j]|   
             int reduceAmountFuel = abs(locations[currIndex] - locations[i]);
             if(i != currIndex){
                // explore all possible ways to reach start to end index 
                countRoutesAll += helper(i,end, fuel- reduceAmountFuel, locations) % mod;
             }
        }
        return dp[currIndex][fuel] = rechedDestination + countRoutesAll % mod;
   }
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
          memset(dp,-1,sizeof(dp));
          return helper(start,finish, fuel, locations);
    }
};
