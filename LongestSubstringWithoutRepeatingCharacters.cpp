// http://www.cnblogs.com/TenosDoIt/p/3736725.html
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> bitmap(128, -1);
        int res = 0;
        int start = 0, lastStart = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(bitmap[s[i]] != -1)
            {
                res = max(res, i-start);
                lastStart = start;
                start = bitmap[s[i]] + 1;
                for(int j = lastStart; j < bitmap[s[i]]; j++)
                    bitmap[s[j]] = -1;
            }
            bitmap[s[i]] = i;
        }
        res = max(res, (int)s.size()-start);//不要忘了最后的判断
        return res;
    }
};