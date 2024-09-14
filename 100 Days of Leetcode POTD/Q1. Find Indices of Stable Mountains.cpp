class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold) {
        
        int n = height.size();
        vector<int> result;
        for(int i = 1; i<n; i++){
            int currentIndex = i;
            int prevIndex = i-1;

            int prevElement = height[prevIndex];
            if(prevElement > threshold){
                result.push_back(currentIndex);
            }
        }
        return result;
    }
};