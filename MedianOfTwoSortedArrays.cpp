class Solution {
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		// in order to get log(n) complexity, we need binary search;

		if ((m + n) & 0x01) {
			// total number is odd

			int k = (m + n + 1)/2;
			return findKthInSortedArrays(A,0,m-1,B,0,n-1,k);

		}
		else {
			// total number is even

			int k1 = (m+n)/2;
			int k2 = k1 + 1;

			return findKthInSortedArrays(A,0,m-1,B,0,n-1,k1) /2.0 + findKthInSortedArrays(A,0,m-1,B,0,n-1,k2)/2.0;

		}

	}
private:
    
    //Notice ： K > 0  
int findKthInSortedArrays(int A[], int aBeg, int aEnd, int B[], int bBeg, int bEnd, int k)  
{  
    if (aBeg > aEnd)  
    {  
        return B[bBeg + k - 1];  
    }  
    if (bBeg > bEnd)  
    {  
        return A[aBeg + k - 1];  
    }  
      
    //取中间位置  
    int aMid = aBeg + (aEnd - aBeg)/2;    
    int bMid = bBeg + (bEnd - bBeg)/2;  
      
    //从A和B的开始位置到两个数组中间位置的元素个数  
    int halfLen = aMid - aBeg + bMid - bBeg + 2;  
      
    if (A[aMid] < B[bMid])  
    {  
        if (halfLen > k)  
        {  
            // 此时在合并的数组中A[aBeg...aMid]和元素一定在B[bMid]的左侧，  
            // 即此时第k大的元素一定比B[bMid]这个元素小（严格来说不大于）  
            // 故以后没有必要搜索 B[bMid...bEnd]这些元素  
            return findKthInSortedArrays(A, aBeg, aEnd, B, bBeg, bMid - 1, k);  
        }  
        else  
        {  
            // 此时在合并的数组中A[aBeg...aMid]元素一定在B[bMid]的左侧，  
            // 所以前K个元素中一定包含A[aBeg...aMid]（可以使用反证法来证明这点）。  
            // 但是无法判断A[amid+1...aEnd]与B[bBeg...bEnd]之间的关系，帮需要对他们进行判断  
            // 此时K就剩下除去A[aBeg...aMid]这些元素，个数为k - (aMid - aBeg + 1)  
            return findKthInSortedArrays(A, aMid + 1, aEnd, B, bBeg, bEnd, k - (aMid - aBeg + 1));  
        }  
    }  
    else  
    {  
        //注释与上面相似  
        if (halfLen > k)  
        {  
            return findKthInSortedArrays(A, aBeg, aMid - 1, B, bBeg, bEnd, k);  
        }  
        else  
        {  
            return findKthInSortedArrays(A, aBeg, aEnd, B, bMid + 1, bEnd, k - (bMid - bBeg + 1));  
        }  
    }  
}  
	int findKthInoSortedArrays(int A[], int mS,int mE, int B[], int nS, int nE, int k) {

		int mid1; //  = (mE-mS)/2 + mS;
		int mid2; //  = (nE-nS)/2 + nS;

		int lenA = mE;
		int lenB = nE;

		while (mS < mE && nS < nE) {
			mid1 = (mE-mS)/2 + mS;
			mid2 = (nE-nS)/2 + nS;

			if (mid1 + mid2 > k - 1) {
				if (A[mid1] > B[mid2]) {
					mE = mid1;
				}
				else {
					nE = mid2;
				}
			}
			else {
				if (A[mid1] > B[mid2]) {
					nS = mid2 + 1;
				}
				else {
					mS = mid1 + 1;
				}
			}
		}

		if (mS >= mE) {
			// in Array B

			if (lenA == k)
				return A[lenA-1];

			return B[k - lenA - 1];
		}

		if (nS >= nE) {
			// in Array A
			if (lenB == k)
				return B[lenB-1];
			return A[k - lenB - 1];
		}

	}
};