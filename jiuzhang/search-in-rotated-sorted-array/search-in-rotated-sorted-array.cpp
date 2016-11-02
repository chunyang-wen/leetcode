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
     * param A : an integer ratated sorted array
     * param target :  an integer to be searched
     * return : an integer
     */
private:
int find(vector &A, int l, int r, int target) {
        if (l > r) {
            return -1;
        }
        int idx = -1;
        if (A[l] <= A[r]) {
            int left = l, right = r, mid = 0;
            while (left <= right) {
                mid = (left + right) >> 1;
                if (A[mid] == target) {
                    idx = mid;
                    break;
                }
                else if (A[mid] > target) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
        }
        else {
            int mid = (l + r) >> 1;
            if (A[mid] == target) {
                idx = mid;
            }
            else {
                idx = find(A, l, mid - 1, target);
                idx = idx == -1 ? find(A, mid + 1, r, target) : idx;               
            }
        }        
        return idx;
}
public:
    int search(vector &A, int target) {
        // write your code here
        int n = A.size();
        return find(A,0,n-1,target);
    }
};

