/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector &prices) {
        // write your code here
        if (prices.empty()) return 0;
        int i=prices.size()-1, ans=0, maxp=prices[i];
        for (--i; i>=0; --i){
            ans=max(ans, maxp-prices[i]);
            maxp=max(maxp, prices[i]);
        }
        return ans;
    }
};


