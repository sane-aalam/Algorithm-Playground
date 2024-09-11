
// Word Ladder-1 problem same to same problem hay 
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank){

    // to checkout this curr string is not alredy visited or not
    // easy to maintain, search into set, using (st.find())
       set<string> setMp;
       for(auto it : bank) 
            setMp.insert(it);

    // try all possible ways
       vector<char> v = {'A', 'C', 'G', 'T'};

    // create queue DSA, push start node into the queue
      queue<string> q;
       q.push(startGene);

      int minimumOpreation = 0;

    // perform BFS algorithm 
       while(!q.empty()){
            int n = q.size();
            while(n--){
                string front = q.front();
                q.pop();

                if(front == endGene){
                    return minimumOpreation;
                }

                // Try all possible ways [ACGT]
                 for(int i = 0; i < front.size(); i++){
                    for(int j = 0; j < v.size(); j++){
                        // AAAACCCC
                        // AAACCCCC
                        // AACCCCCC
                        // try all possible to put (A,C,G,T)
                         char x = front[i]; // pick the current string
                         front[i] = v[j]; // replace each char one by,

                         // is present into set, push into queue, remove it into setMp,
                         if(setMp.find(front) != setMp.end()){
                             q.push(front);
                             setMp.erase(front);
                         }
                         front[i] = x;
                    }
                 }
            }
            minimumOpreation++;
       }
       return -1;
    }
};