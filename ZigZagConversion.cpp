class Solution {
public:
	string convert(string s, int nRows) {

		// easy case
		if (s.size() <= nRows || 1== nRows)
			return s;

		int j;
		string str="";
		int len = s.size();
		vector<string> strVec(nRows);
		int strInd = 0;
		bool up = true;
		j = 0;
		while (j < len) {
			strVec[strInd] += s[j];

			if (up) {
				++strInd;
				if (strInd >= nRows) {
					strInd -= 2;
					up = false;
				}
			}
			else {
				--strInd;
				if (strInd < 0) {
					strInd += 2;
					up = true;
				}
			}

			++j;
		}

		j = 0;
		while (j < nRows) {
			str += strVec[j];
			++j;
		}

		return str;

	}
};