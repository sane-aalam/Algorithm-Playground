class Solution {
public:
    int minimumDistributions = INT_MAX;
    
    void solve(int currentIndex, vector<int> & cookies,vector<int> & children,int k ){
        
        // base condtion 
        if(currentIndex == cookies.size()){
            // current children me maxElement pick
            // ans store the maximum Element of children array using STL (fast way to get maximum element)
            int ans = *max_element(begin(children), end(children));
            // minimum ditribution (we want to minimum result);
            minimumDistributions = min(minimumDistributions,ans);
            return;
        }
        
       //  standard template of backtracking concpet - pick or Not pick (Great Approach to solve easy to hard)
       //  take the currentIndex cookies 
       int candy = cookies[currentIndex];
        
       for(int index = 0; index < k; index++){
           // allocate the candy to children 
           children[index] += candy;
           // explore the path
           solve(currentIndex+1,cookies,children,k);   // call for next index element 
           // de-allocate the candy to children
           children[index] -= candy;
       }
    }
public:
    int distributeCookies(vector<int>& cookies, int k) { 

    // create the arary children allocation to cookies 
     vector<int> children(k);   
      int startIndex = 0;
      solve(startIndex,cookies,children,k);
      return minimumDistributions;
    }
};

