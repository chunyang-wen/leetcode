class Solution {
public:
    int reverse(int x) {
        if (0 == x)
            return 0;
        while (0 == x % 10) // remove last digits of 0s
            x /= 10;
        int y = 0;
        while (x) {
            y = y*10 + x % 10;
            x /= 10;
        }
        return y;
    }
};