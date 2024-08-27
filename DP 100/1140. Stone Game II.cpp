
   // Game Theory [approach to solve any problem]
   // There are two player [follow this appraoch]
    // Alice(you) -> do your best
    // Bob(enemy) -> do wrost for him 

class Solution {
public:
    int dp[2][102][102];
    int helper(int person, int index, int m, int n, vector<int> & piles){

        // base case [array is exceed limits]
        if(index >= n){
            return 0;
        }

        // memorization 
        if(dp[person][index][m] != -1){
            return dp[person][index][m];
        }

        int stones = 0;
        int result = (person == 1)?-1:INT_MAX;

        // Traversal the array on the basic of (1 <= X <= 2M.)
        for(int x = 1; x<= min(2*m,n-index); x++){
                // take the stones
                stones += piles[index + x - 1];

                // maximum stones in alice's turn (alice for 1 and bob for 0) 
                if(person == 1){
                    result = max(result, stones + helper(0,index+x,max(x,m),n,piles));
                // minimise stones in Bob's turn
                }else{
                    result = min(result, helper(1,index+x, max(x,m),n,piles));
                }
        }
        // store the result into dp 
        return dp[person][index][m] = result;
    }
    int stoneGameII(vector<int>& piles) {
        int person = 1;
        int index = 0;
        int m = 1;
        int n = piles.size(); 

        memset(dp,-1,sizeof(dp));

        int maximumAliceEarn =  helper(person,index,m,n,piles);
        return maximumAliceEarn;
    }
};