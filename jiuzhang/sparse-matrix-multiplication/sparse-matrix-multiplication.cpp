/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
   
    vector> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int na = A.size();
        int ma = A[0].size();
        int mb = B[0].size();
        vector> ans(na, vector<int>(mb, 0));
        for (int i = 0; i < na; i ++) {
            for (int k = 0 ; k < ma; k++) {
                if (A[i][k] != 0) {
                    for (int j = 0; j < mb; j++) {
                        ans[i][j] += (A[i][k] * B[k][j]);    
                    }
                }
            }
        }
        return ans;
    }
};

// 超时的常规做法
class Solution {
public:
   
    vector> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int na = A.size();
        int ma = A[0].size();
        int mb = B[0].size();
        vector> ans(na, vector<int>(mb, 0));
        for (int i = 0; i < na; i ++) {
            for (int j = 0; j < mb; j++) {
                for (int k = 0 ; k < ma; k++) {
                    ans[i][j] += (A[i][k] * B[k][j]);    
                }
            }
        }
        return ans;
    }
};
