class Solution {
public:
    int numTrees(int n) {
        if (n < 0)
            return -1;
        if (n < 2)
            return 1;
        int num[20] = {0};
        num[0] = 1;
        num[1] = 1;
        for (int i = 2; i < n + 1; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                num[i] += num[j] * num[i-1-j];
            }
        }
        return num[n];
    }
};