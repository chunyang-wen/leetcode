class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if (!s)
            return 0;
        while ((*s) != '\0' && (*s) == ' ') ++s;
        if (!s)
            return 0;
        const char *start = s;
        const char *end = s;
        while((*s) != '\0') {
            if (*s == ' ') {
                end = s;
                while ((*s) != '\0' && (*s) == ' ') ++s;
                if ((*s) == '\0') {
                    // *space = '\0';
                    break;
                }
                start = s;
                continue;
            }
            ++s;
            end = s;
        }
        
        int len = 0;
        while(start != end) {++len;++start;}
        
        return len;
        
    }
};