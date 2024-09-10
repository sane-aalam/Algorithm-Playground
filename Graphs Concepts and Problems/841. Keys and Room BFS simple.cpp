
// algorithm to solve this problem
// rooms is equal to give Adjlist
// if you are able to visited each nodes, which means you can visited all the rooms, return true;
// otherwise return false;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int N = rooms.size();
        // creation of visited Node using N, to make sure you have visited all rooms
        vector<int> visited(N,0);
        // rooms are locked except for room 0 to N-1
        int startRoom = 0;
        queue<int> q;
        q.push(startRoom);
        visited[startRoom] = 1;

        while(!q.empty()){
            int currentRoom = q.front();
            q.pop();

            for(auto connectedRoom : rooms[currentRoom]){
                // if connected room is not alredy visited,Then push into queue, mark visited
                if(visited[connectedRoom] == 0){
                    q.push(connectedRoom);
                    visited[connectedRoom] = 1;
                }
            }
        }
        
        for(auto eachRoom : visited){
            if(eachRoom == 0 ){
                return false;
            }
        }
        return true;
    }
};