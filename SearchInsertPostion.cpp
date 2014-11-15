class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if (!A || n < 0)
            return -1;
        // implement binary search in sorted array
        int low = 0;
        int high = n;
        int mid;
        while (low < high) {
            mid = (high-low)/2 + low;
            if (A[mid] == target)
                return mid;
            else if (A[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        return low;
    }
};