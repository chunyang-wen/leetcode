/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector &A, int target) {
        // find first position >= target
        if (A.size() == 0) {
            return 0;
        }
        
        int start = 0, end = A.size() - 1;
        while (start + 1 < end) {
            int mid = (end - start) / 2 + start;
            if (A[mid] >= target) {
                end = mid;
            } else {
                start = mid;
            }
        }
        
        if (A[start] >= target) {
            return start;
        }
        if (A[end] >= target) {
            return end;
        }
        
        return A.size();
    }
};
