/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

// version 1: O(n^2)
class Solution {
public:
    int maximalRectangle(vector > &matrix) {
        if (matrix.size() == 0) {
            return 0;
        }
        
        int n = matrix.size();
        int m = matrix[0].size();
        vector heights(m);
        int result = 0;
        
        for (int i = 0; i < n; i++) {
            // get new height
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == "0") {
                    heights[j] = 0;
                } else {
                    heights[j] = heights[j] + 1;
                }
            }
            
            stack myStack;
            for (int j = 0; j <= m; j++) {
                int height = j < m ? heights[j] : -1;
                while (!myStack.empty() && heights[myStack.top()] >= height) {
                    int h = heights[myStack.top()]; myStack.pop();
                    int w = myStack.empty() ? j : j - myStack.top() - 1;
                    result = max(result, h * w);
                }
                myStack.push(j);
            }
        }
        
        return result;
    }
};

// version 2, O(n^3)
class Solution {
public:
    int getMaxLength(vector &r1, vector<char> &r2) {
        // r1 = r1 and r2
        int lastIndex = -1;
        int maxLength = 0;
        for (int i = 0; i < r1.size(); i++) {
            r1[i] = (r1[i] == "1" && r2[i] == "1") ? "1" : "0";
            if (r1[i] == "0") {
                if (lastIndex == -1) {
                    continue;
                }
                maxLength = max(maxLength, i - lastIndex);
                lastIndex = -1;
            } else {
                if (lastIndex == -1) {
                    lastIndex = i;
                } else {
                    continue;
                }
            }
        }
        if (lastIndex != -1) {
            maxLength = max(maxLength, (int)(r1.size()) - lastIndex);
        }
        return maxLength;
    }
    
    int maximalRectangle(vector > &matrix) {
        if (matrix.size() == 0) {
            return 0;
        }
        
        int n = matrix.size();
        int m = matrix[0].size();
        vector row;
        
        int result = 0;
        for (int i = 0; i < n; i++) {
            row = matrix[i];
            for (int j = i; j < n; j++) {
                int maxLength = getMaxLength(row, matrix[j]);
                result = max(result, maxLength * (j - i + 1));
            }
        }
        
        return result;
    }
};
