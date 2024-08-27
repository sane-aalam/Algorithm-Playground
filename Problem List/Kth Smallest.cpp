class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
         priority_queue<int> maxHeap;
        for(int index = 0; index < arr.size(); index++){
            maxHeap.push(arr[index]);
            if(maxHeap.size() > k){
                maxHeap.pop();
            }
        }
        return maxHeap.top();
    }
};