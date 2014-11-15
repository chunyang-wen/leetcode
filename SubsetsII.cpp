class Solution {
public:
	vector<vector<int> > subsetsWithDup(vector<int> &S) {
		unordered_map<int,int> bag;
		unordered_map<int,int>::iterator iEnd = bag.end();
		int len = S.size();
		int i=0;

		// create the bags for all the value;
		while (i < len) {
			if (bag.find(S[i]) == iEnd) {
				bag[S[i]] = 1;
			}
			else
				++bag[S[i]];
			++i;
		}

		vector<vector<int> > res;
		vector<int> num;
		len = S.size()+1;
		sort(S.begin(), S.end());
		vector<int>::iterator uEnd = unique(S.begin(),S.end());
		S.erase(uEnd,S.end());
		for(int i = 0; i < len; ++i) {
			combination(bag,S,num,0,0,i,res);
		}

		return res;

	}
private:
	void combination(unordered_map<int,int> &bag, vector<int> &S,vector<int> &num, int start,int curk,int k, vector<vector<int> > &res) {
		if (curk >= k) {
			res.push_back(num);
			return;
		}

		int i,m,n;
		int len = S.size();
		for (i = start;i < len; ++i) {

			m = 0;
			n = bag[S[i]];
			while (m < n) {
				num.push_back(S[i]);
				--bag[S[i]];
				++curk;
				combination(bag,S,num,i+1,curk,k,res);
				++m;
				if (curk >= k) {
					
					break;
				}

			}
			curk -= m;
			bag[S[i]] = n;
			while (m--)
				num.pop_back();

		}
	}
};
