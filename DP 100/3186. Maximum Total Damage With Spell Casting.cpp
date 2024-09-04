
// recursion [solution]
// 1. sort the array for easy to compare [num[i] == num[i+1]]
// 2. use map [for storing the fqurency of the element]
// 3. pick or not pick [stiver dp series appraoch used]

class Solution {
private:
    long long solve(int index, vector<int> & arr, map<int,int> mp){

       if(index >= arr.size()){
          return 0;
       }  

       long long notpick = 0;
       long long pick = 0;
       notpick = solve(index+1,arr,mp);

       // pick currentElement on the basic of difference 
       int nextindex = index+1;
       while(nextindex < arr.size() && arr[nextindex] - arr[index] <= 2){
         nextindex++;
       } 
       pick = arr[index] * mp[arr[index]] + solve(nextindex,arr,mp);
       return max(pick,notpick);
    }
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int,int> mp;
        for(auto it : power){
            mp[it]++;
        }

        vector<int> arr;
        for(auto it : mp){
            arr.push_back(it.first);
        }
        
        return solve(0,arr,mp);
    }
};


// memorization of using changable variable
// only one variable changable 

class Solution {
private:
    long long solve(int index, vector<int> & arr,
                 map<int,int> & mp,vector<long long> & dp){

       if(index >= arr.size()){
          return 0;
       }  

       if(dp[index] != -1){
        return dp[index];
       }

       long long notpick = 0;
       long long pick = 0;

       // step-1 not take the current element 
       notpick = solve(index+1,arr,mp,dp);

       // step-2 take the current element on the basic of condition 
       int nextindex = index+1;
       while(nextindex < arr.size() && arr[nextindex] - arr[index] <= 2){
         nextindex++;
       } 
       pick = (1ll)*arr[index] * mp[arr[index]] + solve(nextindex,arr,mp,dp);

       return dp[index] = max(pick,notpick);
    }
public:
    long long maximumTotalDamage(vector<int>& power) {
        // Map (used to store the fequency)
        map<int,int> mp;
        for(auto it : power){
            mp[it]++;
        }

        vector<int> arr;
        for(auto it : mp){
            arr.push_back(it.first);
        }

        int n = power.size();
        vector<long long> dp(n+1,-1);
        return solve(0,arr,mp,dp);
    }
};



