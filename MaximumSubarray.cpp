class Solution {
public:
    int maxSubArray(int A[], int n) {
        int maxSum = A[0];
        int curSum = 0;
        for (int i = 0; i < n; ++i) {
            curSum += A[i];
            if (curSum > maxSum)
                maxSum = curSum;
            if (curSum < 0)
                curSum = 0;
                
        }
        return maxSum;
    }
};