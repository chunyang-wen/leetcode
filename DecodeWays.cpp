class Solution {
public:
    int numDecodings(string s) {
        if(s.empty())
            return 0;
        if(s[0] == '0')
            return 0;
        int n = s.length();
        vector<int> count(n+1, 0);
        count[0] = 1;
        count[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            if('1' <= s[i-1] && s[i-1] <= '9')
                count[i] = count[i-1];
            if(s[i-2] == '1')
                count[i] += count[i-2];
            else if(s[i-2] == '2' && '0' <= s[i-1] && s[i-1] <= '6')
                count[i] += count[i-2];
        }
        return count[n];
    }
};