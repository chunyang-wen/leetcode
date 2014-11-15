class Solution {
public:
	vector<vector<int> > combine(int n, int k) {
		vector<int> num;
		vector<vector<int> > res;
		string str="";
		++n;
		for (int i = 1; i < n; ++i) {
			str += (i + '0');
		}
		--n;

		combineHelper(0,k,num,res,str,0);
		return res;
	}
private:
	void combineHelper(int curK, int K, vector<int> &num, vector<vector<int> > & res, string &str, int start) {
		if (curK >= K) {
			res.push_back(num);
			return;
		}

		int len = str.size();

		for (int i = start; i < len; ++i) {
			num.push_back(str[i]-'0');
			++curK;
			combineHelper(curK, K, num, res, str, i+1);
			num.pop_back();
			--curK;
		}
	}
};