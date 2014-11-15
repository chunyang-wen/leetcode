class Solution {
public:
    int singleNumber(int A[], int n) {
        
        int outLen = sizeof(int) * 8;
        int cnt;
        int i;
        int bitMask;
        int num = 0;
        
        while (outLen--) {

			cnt = 0;
			bitMask = (1<<outLen);
			for (int i = 0; i < n; ++i) {
				cnt += ((A[i] & bitMask)!=0?1:0);
			}

			num |= ((cnt%3) ? bitMask:0);
		}

        
        return num;
        
    }
};