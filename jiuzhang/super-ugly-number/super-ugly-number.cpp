/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    /**
     * @param n a positive integer
     * @param primes the given prime list
     * @return the nth super ugly number
     */
    int nthSuperUglyNumber(int n, vector& primes) {
        int len = primes.size();  
        vector times(len, 0);  
        vector uglys(n, INT_MAX);  
        uglys[0] = 1;  
        for (int i = 1; i < n; ++i) {  
            for (int j = 0; j < len; ++j)  
               uglys[i] = min(uglys[i],uglys[times[j]] * primes[j]);
  
            for(int j = 0; j < len; ++j)  
                if (uglys[i] == uglys[times[j]] * primes[j]) {  
                    ++times[j];  
                }
        }
        return uglys[n-1];
    }
};
