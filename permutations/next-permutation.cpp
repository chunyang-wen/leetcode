// https://oj.leetcode.com/problems/next-permutation

// basic idea:
// 3 index: i,j,k
// start from back: find first num[i] < num[j]
// start from back: find first num[k] > num[i]
// swap(num[i], num[k])
// reverse(num[j], end)

class Solution{
	public:
		void nextPermutation(vector<int> &num) {
			
			if (num.size() < 2)
				return;

			int len = num.size() -1;
			int i,j,k;
			while (len >= 1) {
				if (num[len] > num[len-1])
					break;
				--len;
			}

			if (0 == len) {
				reverse(num.begin(),num.end());
				return;
			}

			i = len-1;
			j = len;
			k = num.size() - 1;

			while (k >= 0) {
				if (num[k] > num[i]) {
					break;
				}
				--k;
			}

			//swap i and k
			num[i] ^= num[k];
			num[k] ^= num[i];
			num[i] ^= num[k];

			//reverse j to end
			vector<int>::iterator iBeg = num.begin();
			advance(iBeg,j);
			reverse(iBeg,num.end());
		}
};
