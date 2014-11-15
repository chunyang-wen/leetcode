class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> set;
        int len = num.size();
        for (int i=0;i < len; ++i) {
            set.insert(num[i]);
        }
        
        int maxLen = -1;
        int leftLen;
        int rightLen;
        int curLen;
        
        for (int i = 0; i < len; ++i) {
            if (set.find(num[i]) != set.end()) {
                leftLen = helperFunc(set, true, num[i]);
                rightLen = helperFunc(set, false,num[i]);
                if (leftLen + rightLen + 1 > maxLen)
                    maxLen = leftLen + rightLen + 1;
                set.erase(num[i]);
            }
        }
        
        return maxLen;
        
        
    }
    
private:
    int helperFunc(unordered_set<int> &set, bool goLeft, int value) {
        int len = 0;
        int step = 1;
        if (goLeft) {
           step = -1;
        }
        
        value += step;
        while (set.find(value) != set.end()) {
            ++len;
            set.erase(value);
            value += step;
        }
        return len;
        
    }
};