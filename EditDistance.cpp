class Solution {
public:
	int minDistance(string word1, string word2) {

		if (word1.empty())
			return word2.size();
		if (word2.empty())
			return word1.size();

		int i = 0,j = 0;

		int len1 = word1.size()+1;
		int len2 = word2.size()+1;

		int minDistance = 0;

		vector<vector<int> > arr(len1, vector<int>(len2,0));

		for (i = 1; i < len1;++i) {
			arr[i][0] = i;
		}

		for (j = 1; j < len2;++j) {
			arr[0][j] = j;
		}

		int sub = 0;

		for (i = 1; i < len1; ++i) {
			for (j = 1; j < len2; ++j) {
				sub = 1;
				if (word1[i-1] == word2[j-1]) {
					sub = 0;
				}
				arr[i][j] = minofThree(arr[i-1][j] + 1, arr[i][j-1]+1, arr[i-1][j-1] + sub);
			}
		}

		return arr[len1-1][len2-1];

	}
private:
	int minofThree(int a, int b ,int c) {
		return min(min(a,b),c);
	}
};