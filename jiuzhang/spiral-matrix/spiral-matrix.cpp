/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    /**
     * @param matrix a matrix of m x n elements
     * @return an integer array
     */
    vector spiralOrder(vector<vector<int>>& matrix) {
        // Write your code here
        step[0][0] = 0;
        step[0][1] = 1;
        step[1][0] = 1;
        step[1][1] = 0;
        step[2][0] = 0;
        step[2][1] = -1;
        step[3][0] = -1;
        step[3][1] = 0;
        ret.clear();
        memset(canUse, true, sizeof(canUse));
        dfs(matrix, 0, 0, -1);
        
        return ret;
    }
private:
    int step[4][2];
    vector ret;
    bool canUse[100][100];
public:
    void dfs(vector > &matrix, int direct, int x, int y)
    {
        for(int i = 0; i < 4; i++)
        {
            int j = (direct + i) % 4;
            int tx = x + step[j][0];
            int ty = y + step[j][1];
            if (0 <= tx && tx < matrix.size() && 0 <= ty && ty < matrix[0].size() && canUse[tx][ty])
            {
                canUse[tx][ty] = false;
                ret.push_back(matrix[tx][ty]);                
                dfs(matrix, j, tx, ty);               
            }            
        }
    }
};
