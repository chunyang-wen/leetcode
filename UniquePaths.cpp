class Solution {
public:
    int uniquePaths(int m, int n) {
        
        if (m < 1 || n < 1)
            return 0;
        
        int i = 1;
        double path = 1;
        m = m - 1;
        n = n - 1;
        if (m < n) {
           swap(m,n);
        }
        n = n+1;
        while (i < n) {
            path *= (m+i)*1.0/i;
            ++i;
        }
        return (int)path;
    }
private:
    void swap(int &a, int &b) {
        if (a == b)
            return;
        a ^= b;
        b ^= a;
        a ^= b;
    }
};