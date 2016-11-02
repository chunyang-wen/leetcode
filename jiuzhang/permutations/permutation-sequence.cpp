// https://oj.leetcode.com/problems/permutation-sequence

// Give a number n, return the nth permutation
// We use a greedy method


class Solution {
	public:
		string getPermutation(int n, int k) {

			string str="";

			// we use greedy method to find
			// specified number
			int cnt = 1;
			int bitmask = 0;
			int num;
			int m = n;
			while (k) {
				num = k - fact(m-1);
				if (num > 0) {
					k = num;
					++cnt;
				}
				else if (num < 0) {
					// if cnt is not used
					// add it to the string
					for (int i = 1; i <=n; ++i) {
						if (!(bitmask & (1<<i))) {
							--cnt;
							if (!cnt) {
								str += (i+'0');
								bitmask |= (1<<i);
								break;
							}
						}
					}
					--m;cnt=1;
				}
				else {
					// perfect, we need to find the last
					// permutation of current number (not used!)
					// if cnt is not used, add it to the string
					for (int i = 1; i <= n; ++i) {
						if (!(bitmask & (1<<i))) {
							--cnt;
							if (!cnt) {
								str += (i+'0');
								bitmask |= (1<<i);
								break;
							}
						}
					}

					for (int i = n; i >= 1; --i) {
						if (!(bitmask &(1<<i))) {
							str += (i + '0');
							bitmask |= (1<<i);
						}
					}
					break;
				}
			}
			return str;
		}

	private:
		int fact(int n) {
			int sum = 1;
			for (int i = 2; i <= n; ++i) {
				sum *= i;
			}
			return sum;
		}
};
