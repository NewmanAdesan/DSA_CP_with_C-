/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. 
You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously 
(i.e., you must sell the stock before you buy again).

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later,
as you are engaging multiple transactions at the same time. You must sell before buying again.

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0


*/



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // using Technique of refrance array and a bit
        // of dynamic programming
        // Note: the logic is not that trivial
        // pay attention!
        int n = prices.size();
        int result = 0;
        
        int left_max[n];
        left_max[0] = 0;
        int min_buy = prices[0];
        for(int i = 1; i<n; i++){
            if (prices[i] < min_buy){
                min_buy = prices[i]; }
            left_max[i] = max( prices[i] - min_buy,left_max[i-1] );
        } 
        
        
        int right_max[n];
        right_max[n-1] = 0;
        int max_sell = prices[n-1];
        for(int i = n-2; i>=0; i--){
            if (prices[i] > max_sell){
                max_sell = prices[i]; }
            right_max[i] = max(max_sell - prices[i],right_max[i+1]);
        }
        
        
        // this is the key part of the logic
        for(int i = 0; i<n-1; i++){
            result = max(result, left_max[i] + right_max[i+1]);
        }
        
        
        // for edge case like {1,2,3,4,5}
        result = max(result, left_max[n-1]);
        
        return result;
         

    }
};
