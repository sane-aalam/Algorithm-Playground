class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        vector<pair<int,int>> store;
        int n = profits.size();

        for(int i = 0; i<n; i++){
            store.push_back({capital[i],profits[i]});
        }
        sort(store.begin(),store.end());

        priority_queue<int> q; 
        int i = 0;

        //p-1 When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.
        //p-2 Pick a list of at most k distinct projects from given projects to maximize your final capital
        //  LeetCode design the best way to maximize its total capital after finishing at most k distinct projects.
        // Kth maximum element same to same problem 

        while(k){
            while(i < n && store[i].first <= w ){
                q.push(store[i].second);
                i++;
            }
            if(q.empty()) 
                break;
            w += q.top();
            q.pop();
            k--;
        }
        return w;
    }
};