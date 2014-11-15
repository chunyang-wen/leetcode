class Solution {
public:
    int maxProduct(int A[], int n) {
        if (!A) {
            return 0;
        }
        int lMinPrev = 1;
        int lMaxPrev = 1;
        int lMax = INT_MIN;
        int curProduct = 1;
        for (int i = 0; i< n; ++i) {
            
            curProduct  = maxThree(lMinPrev*A[i], lMaxPrev*A[i], A[i]);
            lMinPrev = minThree(lMinPrev*A[i], lMaxPrev*A[i], A[i]);
            lMaxPrev = curProduct;
            
            if (curProduct > lMax) {
                lMax = curProduct;
            }
        }
        
        return lMax;
    }
private:
    int maxThree(int a, int b ,int c) {
        return max(max(a,b),c);
    }
    int minThree(int a, int b,int c) {
        return min(min(a,b),c);
    }
};