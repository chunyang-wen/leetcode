/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    int maxProfit(int k, vector &prices) {
        if (prices.empty())
            return 0;

        int ans = 0;
        if (k >= prices.size() / 2)
        {
            for (int i = 1; i < prices.size(); ++i) {
                if (prices[i] - prices[i - 1] > 0) {
                    ans += prices[i] - prices[i - 1];
                }
            }
        } else {
            vector local(k+1);
            vector global(k+1);
            
            for (int i = 0; i < prices.size() - 1; ++i) {
                int increase = prices[i + 1] - prices[i];
    
                for (int j = k; j >= 1; --j) {
                    local[j] = max(global[j - 1] + max(increase, 0), local[j] + increase);
                    global[j] = max(global[j], local[j]);
                }
            }
            ans = global[k];
        }
        return ans;
    }
   
};
