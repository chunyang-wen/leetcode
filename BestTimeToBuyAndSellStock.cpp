class Solution {
public:
    int maxProfit(vector<int> &prices) {
        
        if (prices.empty())
            return 0;
        
        int profit = 0;
        
        // pre-processing
        int len = prices.size() - 1;
        int i = 0;
        
        while (i < len) {
            prices[i] = prices[i+1] - prices[i];
            ++i;
        }
        
        int maxSubSum = 0;
        i = 0;
        while (i < len) {
            profit += prices[i];
            
            if (profit > maxSubSum)
                maxSubSum = profit;
            if (profit < 0)
                profit = 0;
            ++i;
        }
        
        return maxSubSum;
        
        
    }
};