class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int k = m + n;
        while (k-- > 0)
            A[k] = (n == 0 || (m > 0 && A[m-1] > B[n-1])) ?  A[--m] : B[--n];
    }
};