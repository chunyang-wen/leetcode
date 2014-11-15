class Solution {
public:
	vector<vector<int> > generate(int numRows) {
		vector<vector<int> > res;
		vector<int> a(1,1);
		if (0==numRows)
			return res;
		res.push_back(a);
		if (1==numRows)
			return res;
		a.push_back(1);
		res.push_back(a);
		if (2==numRows)
			return res;

		int numOfEle = 0;
		for (int i = 3; i < numRows+1; ++i) {
			numOfEle = i;
			a = vector<int>(numOfEle,1);
			res.push_back(a);
			for (int j = 2; j < numOfEle; ++j) {
				res[i-1][j-1] = res[i-2][j-2] + res[i-2][j-1];
			}

		}
		return res;
	}
};