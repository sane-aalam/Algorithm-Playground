// remembering the past!
// 1. first you need to buy the stock
// 2. second you need to sell the stock
// 3. You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
// 4. you have to maintain the minimum price buy the stock, maximum price sell the stock on that day
// 5. why DP - past se sikhna
// 6  past ki value use karna for future maximum profit earn!

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyOnMinimumPrice = prices[0];
        int maximumProfitCanEarn = 0;

        for(int index = 1; index < prices.size(); index++){
            int cost = prices[index] - buyOnMinimumPrice;
            maximumProfitCanEarn = max(cost,maximumProfitCanEarn);
            buyOnMinimumPrice = min(buyOnMinimumPrice,prices[index]);
        }
        return maximumProfitCanEarn;
    }
};