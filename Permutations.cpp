class Solution {
public:
	vector<vector<int> > permute(vector<int> &num) {
		vector<vector<int> >res;
		// res.push_back(num);
		int curNum = 0;
		permuteHelper(num, 0, num.size(),res, curNum);
		return res;
	}

private:
	void permuteHelper(vector<int> &num, int start, int end, vector<vector<int> > &res, int &curNum) {
		if (curNum >= end) {
			res.push_back(num);
			return;
		}
		for (int j = start; j < end; ++j) {
			swap(num[start], num[j]);
			++curNum;
			permuteHelper(num,start+1,end, res,curNum);
			--curNum;
			swap(num[start], num[j]);
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