class Solution {
public:
	int removeDuplicates(int A[], int n) {

		if (!A || n < 3)
			return n;


		int number = A[0];
		int cnt = 0;
		int i = 0;
		int curLen = 0;
		while ( i < n) {

			if (A[i] == number) {
				if (cnt < 2) {
					++cnt;
				}
				else {
					// we need swap
					while (i < n && A[i] == number)
						++i;
					if (i >= n)
						break;
					cnt = 1;
					number = A[i];
				}
			}
			else {
				cnt = 1;
				number = A[i];
			}

			A[curLen] = A[i];
			++curLen;
			++i;

		}

		return curLen;

	}
};