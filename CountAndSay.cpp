class Solution {
public:
	string countAndSay(int n) {
		if (n == 1)
			return "1";
		string prevStr = "1";
		string nextStr;
		++n;
		int size;
		int cnt;
		char c;
		for (int i = 2; i < n;++i) {
			size = prevStr.size();
			nextStr.clear();
			for (int j = 0; j < size;) {
				cnt = 1;
				c = prevStr[j];
				while (j < (size-1) && prevStr[j] == prevStr[j+1]) {
					++cnt;
					++j;
				}
				nextStr += (cnt+'0');
				nextStr += c;
				++j;
			}
			prevStr = nextStr;
		}
		return prevStr;
	}
};