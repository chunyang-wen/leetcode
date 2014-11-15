class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty())
            return true;
        string strAlpha;
        int i = 0;
        int len = s.size();
        while (i < len) {
            if (isalnum(s[i]))
                strAlpha += tolower(s[i]);
            ++i;
        }
        
        string strAlphaCopy = strAlpha;
        reverse(strAlphaCopy.begin(),strAlphaCopy.end());
        return strAlphaCopy == strAlpha;
    }
};