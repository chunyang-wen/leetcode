/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    /**
     * Get all distinct N-Queen solutions
     * @param n: The number of queens
     * @return: All distinct solutions
     * For example, A string "...Q" shows a queen on forth position
     */
    vector > solveNQueens(int n) {
        // write your code here
        vector > result;
        if( n <= 0 )
        {
            return result;
        }
        vector cols;
        search(n, cols, result);
        return result;
    }
    
    void search(int n, vector &cols, vector<vector<string> > &result)
    {
        if(cols.size() == n)
        {
            result.push_back(drawResult(cols, n));
            return;
        }
        for(int col = 0; col < n; col++)
        {
            if(!isValid(cols, col))
            {
                continue;
            }
            cols.push_back(col);
            search(n, cols, result);
            cols.pop_back();
        }
    }
    bool isValid(vector &cols, int col)
    {
        int row = cols.size();
        for(int i = 0; i < row; ++i)
        {
            if(cols[i] == col)
            {
                return false;
            }
            if(i - cols[i] == row - col)
            {
                return false;
            }
            if(i + cols[i] == row + col)
            {
                return false;
            }
        }
        return true;
    }
    
    vector drawResult(vector<int> &cols, int n)
    {
        vector result;
        for(int i = 0; i < cols.size(); ++i)
        {
            string temp(n, ".");
            temp[cols[i]] = "Q";
            result.push_back(temp);
        }
        return result;
    }
};


