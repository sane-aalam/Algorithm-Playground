class Solution {

//   comp: Binary function, functor or lambda expression that compares two elements in the range
//   Lamda function take two parameters
 static bool compFunction(pair<int,int>f, pair<int, int>s) {
        if(f.second < s.second) 
              return true;
        else if(f.second > s.second) 
              return false;
        else {
            if(f.first > s.first) 
                return true;
            else 
                return false;
        }
    }
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> ans;
        map<int,int> mp;
        
        // store the fequency of element into map
        for(int i = 0; i<nums.size(); i++){
            int currentElement = nums[i];
            mp[currentElement]++;
        }

        vector<pair<int,int>> vectorContainer;
        // map[frequecy, element] push into vectorContainer;
        for(auto it : mp){
            vectorContainer.push_back({it.first,it.second});
        }

        // sort the vector using comp function 
        // comp: Binary function, functor or lambda expression that compares two elements in the range
        sort(vectorContainer.begin(),vectorContainer.end(),compFunction);

        // store into result(ans) according to feq
        for(int i = 0; i<vectorContainer.size(); i++){
            // frequency tak (3) agar 3 fequncy hai 3 bar push kar do
            for(int j = 0; j<vectorContainer[i].second; j++){
                int num = vectorContainer[i].first;
                ans.push_back(num);
            }
        }
        return ans;
    }
};