class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int len = s.length();
        vector<bool> dp(len + 1,false);
        dp[len] = true;

        for (int i = len - 1; i >= 0; i--) {
            for (int j = i; j < len; j++) {
                string str = s.substr(i,j - i + 1);
                if (dict.find(str) != dict.end() && dp[j + 1]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};