/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector > &triangle) {
        // write your code here
        if (triangle.size() == 0)
            return 0;
            
        vector f(triangle[triangle.size()-1].size());
        
        f[0] = triangle[0][0];
        for(int i = 1; i < triangle.size(); i++)
            for(int j = triangle[i].size() - 1; j >= 0; j--)
                if (j == 0)
                    f[j] = f[j] + triangle[i][j];
                else if (j == triangle[i].size() - 1)
                    f[j] = f[j-1] + triangle[i][j];
                else
                    f[j] = min(f[j-1], f[j]) + triangle[i][j];
                    
        int ret = INT_MAX;
        for(int i = 0; i < f.size(); i++)
            ret = min(ret, f[i]);
        return ret; 
    }
};


