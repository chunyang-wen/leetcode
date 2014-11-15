class Solution {
public:
    void sortColors(int A[], int n) {
        // 3-way quick sort
        int start = 0;
        int cur = 0;
        int end = n-1;
        int tmp;
        while (cur <= end) {
            
            switch(A[cur]) {
                case 0:
                    // switch with start
                    tmp = A[cur];
                    A[cur] = A[start];
                    A[start] = tmp;
                    ++start;
                    ++cur;
                    break;
                case 1:
                    ++cur;
                    break;
                
                case 2:
                    // switch cur and end
                    tmp = A[end];
                    A[end] = A[cur];
                    A[cur] = tmp;
                    --end;
                    break;
                    
            }
        }
    }
};