class Solution {
public:
	vector<vector<string> > solveNQueens(int n) {
		vector<int> queens(n,1);
		for(int i = 0; i<n; ++i)
			queens[i] = i;
		vector<bool> col(n,false);
		vector<vector<int> > res;
		// queens stay at 0~n-1
		solveQueensHelper(res,queens,0);

		// get all my resutlt;
		int size = res.size();
		vector<vector<string> > result;
		string str(n,'.');
		for (int i=0;i<size;++i) {

			vector<string> board(n,str);
			for(int j=0;j<n;++j) {
				board[j][res[i][j]] = 'Q';
			}
			result.push_back(board);
		}
		return result;
	}
private:
	bool check(vector<int> &queens) {
		int n = queens.size();
		vector<bool> col(n,false);
		for (int i = 0; i<n-1; ++i) {
			for (int j = i+1; j<n; ++j) {
				if (i-j == queens[i]-queens[j] || i-j == queens[j]-queens[i])
					return false;
			}
		}

		return true;
	}
	void solveQueensHelper(vector<vector<int> > &res, vector<int> &queens, int curSize) {
		if (curSize == queens.size()) {
			if(check(queens)) {
				res.push_back(queens);
			}
			return ;
		}
		int n = queens.size();
		for (int i = curSize; i < n; ++i) {
			swap(queens[curSize],queens[i]);
			++curSize;
			solveQueensHelper(res,queens,curSize);
			--curSize;
			swap(queens[curSize],queens[i]);

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