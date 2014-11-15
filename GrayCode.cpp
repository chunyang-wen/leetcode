class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> gray;
        int i = 0;
        int len = 1<<n;
        while (i < len) {
            gray.push_back(i ^ (i>>1));
            ++i;
        }
        return gray;
    }
};