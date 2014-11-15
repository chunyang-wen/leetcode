class Solution {
public:
    int climbStairs(int n) {
        if (n < 2)
            return 1;
        int a = 1;
        int b = 1;
        int res;
        for (int i = 2; i < n + 1; ++i) {
            res = a + b;
            a = b;
            b = res;
        }
        return res;
    }
};