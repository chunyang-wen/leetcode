class Solution {
public:
	void nextPermutation(vector<int> &num) {

		// find first increasing pair backwards
		// find first number bigger than the lower
		if (num.size() < 2)
		    return;
		int len = num.size()-1;
		int i,j;
		while (len >= 1) {
			if (num[len] > num[len-1])
				break;
			--len;
		}
		
		if (0 == len) {
			reverse(num.begin(), num.end());
			return;
		}

		i = len-1;
		j = len;

		len = num.size() - 1;
		while (len >= 0) {
			if (num[len] > num[i])
				break;
				--len;
		}

		// swap i and len
		num[i] ^= num[len];
		num[len] ^= num[i];
		num[i] ^= num[len];

		// reverse j to end
		vector<int>::iterator iBeg = num.begin();
		advance(iBeg, j);
		reverse(iBeg, num.end());
	}
};