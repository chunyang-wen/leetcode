/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    /**
     * @param A : An integer array
     * @return : two integers
     */
    vector singleNumberIII(vector<int> &A) {
        // write your code here
        int x = 0, len = A.size(), pos;
        for (int i = 0; i < len; ++i)
            x ^= A[i];
        for (int i = 0; i < 32; ++i)
            if (x & (1 << i)) {
                pos = i;    
                break;            
            }
        vector results(2);
        for (int i = 0; i < len; ++i)
        if (A[i] & (1 << pos))
            results[0] ^= A[i];
        else
            results[1] ^= A[i];
        return results;
    }
};

