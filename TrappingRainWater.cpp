// http://www.cnblogs.com/TenosDoIt/p/3812880.html
class Solution {
public:
    int trap(int A[], int n) {
        vector<int> maxRH(n,0);
        int maxH = 0;
        int i;
        for (i = n-1; i >= 0; --i) {
            
            maxRH[i] = maxH;
            if (A[i] > maxH) {
                maxH = A[i];
            }
                
        }
        maxH = 0;
        int minHeight;
        int res = 0;
        for (i = 0; i < n; ++i) {
            minHeight = min(maxH, maxRH[i]);
            
            if (minHeight > A[i])
                res += (minHeight-A[i]);
            maxH = max(maxH, A[i]);
        }
        return res;
    }
};