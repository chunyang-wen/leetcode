// https://oj.leetcode.com/problems/subsets


// we use recursive calls to generate the combinations.
// currently, there are no duplicates in array S.

class Solution {
	public:
		vector<vector<int> > subsets(vector<int> &S) {
			vector<vector<int> > res;

			vector<int> num; // record each combination
			int len = S.size() + 1;

			sort(S.begin(), S.end());

			for (int i = 0; i < len; ++i) {
				combination(S,num,0,0,i,res);
			}

			return res;
		}

	private:
		void combination(vector<int> &s, vector<int> &num,
				int start, int curk, int k,
				vector<vector<int> > &res) {
			
			if (curk >= k) {// enough number is chosen
				res.push_back(num);
				return;
			}

			int len = s.size();

			for (int i = start; i < len; ++i) {
				num.push_back(s[i]);
				++curk;
				combination(s,num,i+1,curk,k,res);
				num.pop_back();
				--curk;
			}
		}
};

