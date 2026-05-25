/*
LeetCode 121 - Best Time to Buy and Sell Stock

Problem summary:
You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve by buying and selling the stock once.
You must buy before you sell. If you cannot achieve any profit, return 0.

Example:
prices = [7,1,5,3,6,4] -> Output: 5 (buy at 1, sell at 6)
prices = [7,6,4,3,1] -> Output: 0 (no profit possible)
prices = [2,4,1] -> Output: 2 (buy at 2, sell at 4)

Approach used in this implementation (Greedy):
- Track two variables:
  - min_price: the minimum price seen so far (best day to buy up to current day)
  - profit: the maximum profit achievable so far
- For each price in the array:
  - Update min_price to be the minimum of current price and previous min_price
  - Calculate profit if we sell at current price: prices[i] - min_price
  - Update profit to be the maximum of current profit and calculated profit
- Return the maximum profit

Why this works:
- To maximize profit, we need to sell at a high price and buy at a low price before it.
- By tracking the minimum price seen so far, we ensure we're always buying at the lowest price up to the current day.
- The maximum profit is determined by the maximum difference between any price and the minimum price before it.

Algorithm walkthrough (prices = [7,1,5,3,6,4]):
i=0, price=7: min_price=7, profit=0
i=1, price=1: min_price=1, profit=max(1-1, 0)=0
i=2, price=5: min_price=1, profit=max(5-1, 0)=4
i=3, price=3: min_price=1, profit=max(3-1, 4)=4
i=4, price=6: min_price=1, profit=max(6-1, 4)=5
i=5, price=4: min_price=1, profit=max(4-1, 5)=5
Result: 5

Time & Space complexity:
- Time: O(n), single pass through the prices array
- Space: O(1), only using two variables
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int profit = 0;
        for(int i = 0 ; i < prices.size() ; i++){
            min_price = min(prices[i] , min_price);
            profit = max(prices[i] - min_price , profit);
        }
        return profit;
    }
};