class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        
        int temp;
        for (int i = 0; i < n; ++i) {
            if (A[i] == elem) {
                // swap with current end
                A[i] = A[n-1];
                --i;
                --n;
            }
        }
        return n;
    }
};