/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector A) {
        int l = 1, r = A.size();
        while (l <= r) {
            int mid = (l + r) / 2;
            if (A[mid] > A[mid-1] && A[mid] > A[mid+1])
                return mid;
            if (A[mid] > A[mid-1])
                l = mid + 1;
            else    
                r = mid - 1;
        }
        return -1;
    }
};


