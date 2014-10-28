// https://oj.leetcode.com/problems/permutations

// There no duplicates in the array.
// We use switch method to get permutations.


class Solution {
	public:
		vector<vector<int> > permute(vector<int> &num) {
			vector<vector<int> res;

			int curNum = 0;
			permuteHelper(num,0,num.Size(),res,curNum);

			return res;
		}

	private:
		void permuteHelper(vector<int> &num, int start, int end,
				vector<vector<int> > &res, int &curNum) {

			if (curNum >= end) {
				res.push_back(num);
				return;
			}


			for (int j = start; j < end; ++j) {

				swap(num[start], num[j]);
				// Here start changes to curNum!!!
				// because we swapped nodes, we only need
				// to find next index with corresponding to
				// curNum.
				permuteHelper(num,curNum,end,end,res,curNum);
				--curNum;
				swap(num[start],num[j]);
			}
		}

		void swap(int &a, int &b) {
			if (a == b)
				return;
			a ^= b;
			b ^= a;
			a ^= b;
		}
};
