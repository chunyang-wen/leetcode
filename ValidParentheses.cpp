class Solution {
public:
    bool isValid(string s) {
        stack<char> ps;
        int i = 0;
        int len = s.size();
        while (i < len) {
            switch (s[i]) {
                case '[':
                case '{':
                case '(':
                    ps.push(s[i]);
                    break;
                case ']':
                    if (ps.empty() || ps.top() != '[') {
                        return false;
                    }
                    else
                        ps.pop();
                    break;
                case '}':
                if (ps.empty() || ps.top() != '{') {
                        return false;
                    }
                    else
                        ps.pop();
                    break;
                case ')':
                if (ps.empty() || ps.top() != '(') {
                        return false;
                    }
                    else
                        ps.pop();
                    break;
            }
            ++i;
        }
        return ps.empty();
    }
};