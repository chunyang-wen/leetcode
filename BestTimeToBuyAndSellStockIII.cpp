// http://www.cnblogs.com/TenosDoIt/p/3436457.html
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        const int len = prices.size();
        if(len <= 1)return 0;
        int maxFromHead[len];
        maxFromHead[0] = 0;
        int minprice = prices[0], maxprofit = 0;
        for(int i = 1; i < len; i++)
        {
            minprice = min(prices[i-1], minprice);
            if(maxprofit < prices[i] - minprice)
                maxprofit = prices[i] - minprice;
            maxFromHead[i] = maxprofit;
        }
        int maxprice = prices[len - 1];
        int res = maxFromHead[len-1];
        maxprofit = 0;
        for(int i = len-2; i >=0; i--)
        {
            maxprice = max(maxprice, prices[i+1]);
            if(maxprofit < maxprice - prices[i])
                maxprofit = maxprice - prices[i];
            if(res < maxFromHead[i] + maxprofit)
                res = maxFromHead[i] + maxprofit;
        }
        return res;
    }
};