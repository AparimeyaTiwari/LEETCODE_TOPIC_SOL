
/*
 You are given an array prices where prices[i] is the price of a given stock on the ith day.

 You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

 Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

  

 Example 1:

 Input: prices = [7,1,5,3,6,4]
 Output: 5
 Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
 Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
 Example 2:

 Input: prices = [7,6,4,3,1]
 Output: 0
 Explanation: In this case, no transactions are done and the max profit = 0.
  

 Constraints:

 1 <= prices.length <= 105
 0 <= prices[i] <= 104
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxpro = 0,l=0,r=0; //setting left and right pointers
        //right = sell and left = buy
        while(r<prices.size()){ //right will go at max to the last element of the array
            if(prices[r]-prices[l]>0){//if ele at r >ele at l then can book profit
                maxpro = max(maxpro,prices[r]-prices[l]);//comparing with max till now
            }
            else{
                l = r;//if ele at r<ele at l we can buy at cheaper rate, hence consider r as buy data
            }
            r++; //continuing
        }
        return maxpro;

    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];//setting minimum price present so far
        int pro = 0;
        for(int i = 0;i<prices.size();i++){
            if(prices[i]<mini){
                mini = prices[i];//if current ele smaller update
            }
            pro = max(pro,prices[i]-mini);//current profit is calculated here
        }
        return pro;
        /*
        NOTE: Here minimum element will be at position i or before
        Hence no need to check if the profit is possible or not(ie buy before sell)
        */
    }
};
