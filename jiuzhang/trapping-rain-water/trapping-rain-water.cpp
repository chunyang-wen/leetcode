/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    int trap(vector& heights) {
        int maxHeight = 0, maxIndex;
        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] > maxHeight) {
                maxHeight = heights[i];
                maxIndex = i;
            }
        }
        
        int sum = 0;
        maxHeight = 0;
        for (int i = 0; i < maxIndex; i++) {
            if (maxHeight > heights[i]) {
                sum += maxHeight - heights[i];
            }
            maxHeight = max(maxHeight, heights[i]);
        }
        
        maxHeight = 0;
        for (int i = heights.size() - 1; i > maxIndex; i--) {
            if (maxHeight > heights[i]) {
                sum += maxHeight - heights[i];
            }
            maxHeight = max(maxHeight, heights[i]);
        }
        
        return sum;
    }
};
