/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

#include 

using namespace std;

class Solution {
    /** 
     * param A : an integer ratated sorted array and duplicates are allowed
     * param target :  an integer to be search
     * return : a boolean 
     */
public:
    bool search(vector &A, int target) {
        // write your code here
        int ans = -1;
        int len = A.size();
        int cnt = 0;
        for ( int i = 0; i < len; ++i) {
            if (A[i] == target) {
                ans = i;
            }
            if (i != 0)
                if (A[i] < A[i-1])
                    cnt ++;
        }
        if (cnt  > 1)
            ans = -ans;
        return (ans>=0);
    }
};

