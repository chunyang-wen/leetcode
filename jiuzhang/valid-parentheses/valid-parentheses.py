"""
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
"""

class Solution(object):
    """
    题意：输入一个只包含括号的字符串，判断括号是否匹配
    模拟堆栈，读到左括号压栈，读到右括号判断栈顶括号是否匹配
    """
    def isValidParentheses(self, s):
        stack = []
        for ch in s:
            # 压栈
            if ch == "{" or ch == "[" or ch == "(":
                stack.append(ch)
            else:
                # 栈需非空
                if not stack:
                    return False
                # 判断栈顶是否匹配
                if ch == "]" and stack[-1] != "[" or ch == ")" and stack[-1] != "(" or ch == "}" and stack[-1] != "{":
                    return False
                # 弹栈
                stack.pop()
        return not stack
