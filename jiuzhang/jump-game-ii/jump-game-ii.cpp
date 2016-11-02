/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    int jump(vector A) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = A.size();
        int minstep = 0;
        int ldist = 0;
        int hdist = 0;
        if (n == 1) return 0;
        while(ldist <= hdist) {
            ++minstep;
            int lasthdist = hdist;
            for(int i = ldist; i <= lasthdist; ++i) {
                int possibledist = i + A[i];
                if (possibledist >= n-1)
                    return minstep;
                if (possibledist > hdist) {
                    hdist = possibledist;
                }
            }
            ldist = lasthdist + 1;
        }
        return 0;
    }
};

