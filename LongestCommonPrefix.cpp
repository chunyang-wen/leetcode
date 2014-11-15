class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        
        if (strs.empty())
            return "";
        if (strs.size() < 2) {
            return strs[0];
        }
        
        
        // sort
        sort(strs.begin(),strs.end());
        
        
        // compare adajacent
        string LMP = strs[0];
        string curLMP = "";
        int curLMPIndex = 0;
        int len = strs.size() - 1;
        int i = 0;
        int sizeLeft,sizeRight;
        while (i < len) {
            curLMP = "";
            curLMPIndex = 0;
            sizeLeft = strs[i].size();
            sizeRight = strs[i+1].size();
            while ((curLMPIndex < sizeLeft && curLMPIndex < sizeRight) && (strs[i][curLMPIndex] == strs[i+1][curLMPIndex])) {
                curLMP += strs[i][curLMPIndex];
                ++curLMPIndex;
            }
            
            if(curLMP.size() < LMP.size()) LMP = curLMP;
            
            if (LMP.empty())
                return "";
            
            ++i;
        }
        return LMP;
    }
};