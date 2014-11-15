// http://www.cnblogs.com/TenosDoIt/p/3771122.html
class Solution {
public:
    int longestValidParentheses(string s) {
        const int len = s.size();
        stack<int> sta;
        int res = 0;
        sta.push(-1);//为了处理边界条件，在栈底添加-1
        for(int i = 0; i < len; i++)
        {
            if(s[i] == '(')
                sta.push(i);
            else
            {
                int topIndex = sta.top();
                if(topIndex >= 0 && s[topIndex] == '(')//s[i]可以和s[a]匹配
                {
                    sta.pop();
                    if(res < i - sta.top())res = i - sta.top();
                }
                else sta.push(i);
            }
        }
        return res;
    }
};