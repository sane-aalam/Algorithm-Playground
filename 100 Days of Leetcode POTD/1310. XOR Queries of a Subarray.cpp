class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
         
         int n = arr.size();

         vector<int> prefix(n);
         prefix[0] = arr[0];

         for(int i = 1; i<n; i++){
            prefix[i] = prefix[i-1] ^ arr[i];
         }


         // processing all queries;
         int m = queries.size();
         vector<int> result(m);

         for(int i = 0; i<m; i++){
            // arr[lefti] XOR arr[lefti + 1] XOR ... XOR arr[righti] ).
            int left = queries[i][0];
            int right = queries[i][1];
            if(left == 0){
                result[i] = (prefix[right]);
            }else{
                result[i] = prefix[left - 1] ^ prefix[right];
            }
         }
         return result;
    }
};