class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        
        
        if (!needle || (*needle) == '\0')
            return haystack;
        if (!haystack || (*haystack) == '\0')
            return NULL;
        char * cur = haystack;
        char * nee = needle;
        while ((*haystack) != '\0') {
            
            while((*haystack != '\0') && (*haystack != *needle))
                ++haystack;
            
            cur = haystack;
            
            while (((*needle) != '\0') && ((*haystack) != '\0') && (*haystack) == (*needle)) {
                ++needle;
                ++haystack;
            }
            
            if ((*needle) == '\0')
                return cur;
            
            if ((*haystack) == '\0')
                break;
            needle = nee;
            haystack = ++cur;
            
            
        }
        
        return NULL;
    }
};