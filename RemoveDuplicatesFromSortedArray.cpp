class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // replace
        if (!A || n < 1) return 0;
        int prevEle = A[0];
        int cur = 1;
        for (int i = 1; i < n; ++i) {
            if (A[i] != prevEle) {
                // replace A[cur] with A[i]
                A[cur] = A[i];
                prevEle = A[i];
                ++cur;
            }
        }
        
        return cur;
    }
};