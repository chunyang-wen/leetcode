/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int maxProduct(vector& nums) {
        // write your code here
        vector f, g;
        f.push_back(nums[0]);
        g.push_back(nums[0]);
        for (int i=1; i<nums.size(); ++i) {
            f.push_back(max(max(f[i-1]*nums[i], g[i-1]*nums[i]), nums[i]));
            g.push_back(min(min(f[i-1]*nums[i], g[i-1]*nums[i]), nums[i]));        
        }
        int m = f[0];
        for (int i=1; i<f.size(); ++i) m = max(m, f[i]);
        return m;
    }
};

