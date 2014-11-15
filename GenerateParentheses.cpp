class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		if (n < 1)
			return res;
		int leftP = 0;
		int rightP = n;
		string str="";
		generateParenthesisHelper(leftP, rightP, res, str);

		return res;

	}

private:
	void generateParenthesisHelper(int leftP, int rightP, vector<string> &res, string &str) {

		// leave condition
		if (leftP > rightP)
			return;

		if (0 == rightP) {
			res.push_back(str);
			return;
		}

		if (leftP != 0) { // no left

			if (rightP > 0) { // we can still add left (
				str += '(';
				generateParenthesisHelper(leftP+1, rightP, res, str);
				str.pop_back();
			}

			str += ')';
			generateParenthesisHelper(leftP-1, rightP-1, res, str);
			str.pop_back();
		}
		else {
			str += '(';
			generateParenthesisHelper(leftP+1, rightP, res, str);
			str.pop_back();
		}
	}
};