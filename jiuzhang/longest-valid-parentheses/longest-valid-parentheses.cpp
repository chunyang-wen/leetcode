/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    int longestValidParentheses(string s) {
        // 1 is (, -1 is ), 2,4,6,8.. denote the length of a
        // legal substring with valid parentheses
        vector stack;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == "(") {
                stack.push_back(1);
            } else {
                if (stack.size() > 0 && stack[stack.size() - 1] == 1) {
                    stack[stack.size() - 1] = 2;
                } else if (stack.size() > 1 && stack[stack.size() - 1] > 1 && stack[stack.size() - 2] == 1) {
                    stack[stack.size() - 2] = stack[stack.size() - 1] + 2;
                    stack.pop_back();
                } else {
                    stack.push_back(-1);
                }
                while (stack.size() > 1 && stack[stack.size() - 1] > 1 && stack[stack.size() - 2] > 1) {
                    stack[stack.size() - 2] += stack[stack.size() - 1];
                    stack.pop_back();
                }
            }
        }
        
        int result = 0;
        for (int i = 0; i < stack.size(); i++) {
            if (stack[i] < 2) {
                continue;
            }
            result = max(result, stack[i]);
        }
        return result;
    }
};
