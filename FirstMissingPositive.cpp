class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        
        int temp;
        int i;
        for (i = 0; i < n; ++i) {
            // swap 
            if (A[i] <= 0) {
                continue;
            }
            if (A[i] != i + 1) {
                
                if (A[i] - 1 >= n)
                    continue;
                
                temp = A[A[i]-1];
                if (temp == A[i] )
                    continue;
                A[A[i]-1] = A[i];
                A[i] = temp;
                --i;
            }
        }
        
        for (i = 0; i < n;++i)
            if (A[i] != i + 1)
                return i + 1;
                
        return i + 1;
        
    }
};