class Solution {
public:
    bool isPalindrome(long long x) {
        if (x < 0) return false;
        long long d = 10, e = 10;
        while (x / d) d *= 10;
        while (d > e)
        {
            if ((x % d) / (d / 10) != (x % e) / (e / 10))
                return false;
            d /= 10;
            e *= 10;
        }
        return true;
    }
};