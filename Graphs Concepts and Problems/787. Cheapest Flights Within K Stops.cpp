class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adjlist[n];

       // (edges, wegiht of one place to other place)
        for(auto it: flights){
           int u = it[0];
           int v = it[1];
            int w = it[2];
            
            adjlist[u].push_back({v,w});
        }

        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        vector<int> dis(n);
        for(int i = 0; i<n; i++){
            dis[i] = INT_MAX;
        }

        dis[src] = 0;

        while(!q.empty()){
            int stops = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();

            if(stops> k) continue;

            for(auto x : adjlist[node]){
                int adnode = x.first;
                int weight = x.second;
 // if current weight is smaller,we have already wieghts and also stops is smaller and equal (within stops)
                if(cost + weight < dis[adnode]){
                    dis[adnode] = cost + weight;
                    q.push({stops+1,{adnode,cost+weight}});
                }
            }
        }
        // if you have reach to source to destination return -1
        if(dis[dst] == INT_MAX) return -1;
        // otherwise you have reached 
        else return dis[dst];
    }
};