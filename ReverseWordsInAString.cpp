class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        string::iterator iBeg = s.begin();
        string::iterator iCur = iBeg;
        string::iterator iEnd = s.end();
        
        while (iBeg != iEnd) {
            while (iBeg != iEnd && *iBeg != ' ')
                ++iBeg;
            reverse(iCur, iBeg);
            while (iBeg != iEnd && *iBeg == ' ') ++iBeg;
            
            if (iBeg == iEnd) break;
            
            iCur = iBeg;
            ++iBeg;
        }
        
        // remove extra spaces, which I think it is not correct with problem definitions
        int len = s.size();
        int i = 0;
        int j = 0;
        while (i < len && s[i] == ' ') ++i;
        
        if (i >= len) { s=""; return;}
        
        s[j] = s[i]; ++j;++i;
        for (; i < len; ++i) {
            if (s[i] == ' ' && s[j-1] == ' ')
                continue;
            else {
                s[j++] = s[i];
            }
            
        }
        
        if (s[j-1] == ' ')
            j = j - 1;
        
        s = s.substr(0,j);
        
        
    }
};