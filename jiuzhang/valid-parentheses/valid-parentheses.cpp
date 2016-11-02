/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    /*
    题意：输入一个只包含括号的字符串，判断括号是否匹配
    模拟堆栈，读到左括号压栈，读到右括号判断栈顶括号是否匹配
    */
    bool isValidParentheses((string s) {
        int len = s.length();
        vector stack;
        for (int i = 0; i < len; i++) {
            // 左括号压栈
            if (s[i] == "(" || s[i] == "[" || s[i] == "{") stack.push_back(s[i]);
            else {
                // 右括号出栈
                if (stack.empty()) return false;
                char top = stack[stack.size() - 1];
                if (s[i] == ")" && top != "(")
                    return false;
                if (s[i] == "]" && top != "[") 
                    return false;
                if (s[i] == "}" && top != "{") 
                    return false;
                stack.pop_back();
            }
        }
        // 栈中无多余左括号
        if (stack.size() > 0) return false;
        return true;
    }
};
