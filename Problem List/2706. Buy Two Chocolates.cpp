class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
         
         int n = prices.size();

         // TakeUfoward Lecture-1 
         // find first maximum or second maximum code based 
         // same to same for minium for 
         int minPrice = INT_MAX;
         int secondMinPrice = INT_MAX;

         for(int i = 0; i<n; i++){
            if(prices[i] < minPrice){
                secondMinPrice = minPrice;
                minPrice = prices[i];
            }else{
                secondMinPrice = min(prices[i],secondMinPrice);
            }
         }
         
         if(minPrice + secondMinPrice > money){
            return money;
         }
        int total = minPrice + secondMinPrice;
        return money - total;
    }
};