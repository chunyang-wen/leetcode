class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int i = 0;
        int len = prices.size();
        bool hasStocks = false;
        int prev = -1;
        int profit = 0;
        while (i < len - 1) {
            if (prices[i] < prices[i+1]) {
                if (!hasStocks) {
                    hasStocks = true;
                    prev = prices[i];
                }
            }
            else {
                if (hasStocks) {
                    hasStocks = false;
                    if (prev != -1)
                        profit += (prices[i] - prev);
                    prev = -1;
                }
            }
            ++i;
        }
        
        if (prev != -1) {
            profit += (prices[i]-prev);
            prev = -1;
        }
        
        return profit;
    }
};