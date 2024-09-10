class Solution {
private:
    // simple and clear DFS algorithm used 
    void dfs(int node, vector<int> & visited,vector<vector<int>>& rooms){
         
         // node = room (current room you have to mark visited)
         visited[node] = 1;
         // explore all connected Nodes + these nodes are not already visited s
         for(auto connectedRoom : rooms[node]){
            if(visited[connectedRoom] == 0){
                // call DFS algorithm
                dfs(connectedRoom,visited,rooms);
            }
         }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

// algorithm to solve this problem
// rooms is equal to give Adjlist
// if you are able to visited each nodes, which means you can visited all the rooms, return true;
// otherwise return false;

        int N = rooms.size();
        // creation of visited Node using N, to make sure you have visited all rooms
        vector<int> visited(N,0);
        // rooms are locked except for room 0 to N-1
        int startRoom = 0;
        dfs(startRoom,visited,rooms);

        for(auto eachRoom : visited){
            if(eachRoom == 0 ){
                return false;
            }
        }
        return true;
    }
};