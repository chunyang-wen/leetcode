/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector &height) {
        // write your code here
        if(height.size() == 0) return 0;
        int res = 0;
        vector tmp = height;
        tmp.push_back(0);  // Important
 
        stack s;
        for(int i = 0; i < tmp.size(); i++)
        {
            if(s.empty() || (!s.empty() && tmp[i] >= tmp[s.top()])) s.push(i);
            else{
                while(!s.empty() && tmp[s.top()] > tmp[i])
                {
                    int idx = s.top(); s.pop();
                    int width = s.empty() ? i : (i-s.top()-1);
                    res = max(res, tmp[idx] * width);
                }
                s.push(i);  // Important
            }
        }
        return res;
    }
};


