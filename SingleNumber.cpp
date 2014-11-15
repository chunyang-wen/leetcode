class Solution {
public:
    int singleNumber(int a[], int n) {
        if (n < 1)
            return -1;
        while (--n)
        {
            a[n-1] ^= a[n];
        }
        return a[n];
    }
};