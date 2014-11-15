class Solution {
public:
	string multiply(string num1, string num2) {
		string str="";

		int len1 = num1.size();
		int len2 = num2.size();

		// get the position of dot
		int i = len1-1,j=len2-1;
		while (i>= 0 && num1[i] != '.') --i;
		i = i > 0 ?len1-1-i:0;
		while (j>= 0 && num2[j] != '.') --j;
		j = j > 0?len2-1-j:0;


		if (len1 < len2) {
			for (int i = 0; i < len1; ++i) {
				if (num1[i] == '.')
					continue;
				str = add(str, multiplySingle(num2,num1[i]-'0'));
				if (i < (len1 - 1))
					str = multiplySingle(str, 10);
			}
		}
		else {
			for (int i = 0; i < len2; ++i) {
				if (num2[i] == '.')
					continue;
				str = add(str, multiplySingle(num1,num2[i]-'0'));
				if (i < (len2 -1))
					str = multiplySingle(str, 10);

			}
		}
		len1 = 0;
		len2 = str.size();
		while (len1 < len2 && str[len1] == '0')
			++len1;
		str = str.substr(len1);

		if (str == "") {
			str += "0";
			return str;
		}

		len1 = str.size() - (i+j);
		string::iterator iBeg = str.begin();
		while (len1-- > 0) ++iBeg;
		if(i+j > 0 && !str.empty())
			str.insert(iBeg,'.');
		return str;
	}

	string multiplySingle(string num1, char num2) {
		string str="";
		int carry = 0;
		int len1 = num1.size()-1;
		int m1,m2 = num2;
		while (len1 >= 0) {
			if (num1[len1] == '.') {
				--len1;
				continue;
			}
			m1 = num1[len1] - '0';
			carry = m1 * m2 + carry;
			str += (carry%10 + '0');
			carry /= 10;
			--len1;
		}

		while (carry) {
			str += (carry%10 + '0');
			carry /= 10;
		}
		reverse(str.begin(), str.end());
		return str;

	}

	string add(string num1, string num2) {
		string str="";
		int carry = 0;
		int len1 = num1.size()-1;
		int len2 = num2.size()-1;
		int m1,m2;
		while (len1 >= 0 && len2 >= 0) {
			m1 = num1[len1] - '0';
			m2 = num2[len2] - '0';
			carry = m1 + m2 + carry;
			str += (carry%10 + '0');
			carry /= 10;
			--len1;
			--len2;
		}

		while (len1 >= 0) {
			m1 = num1[len1] - '0';
			carry = m1 + carry;
			str += (carry%10 + '0');
			carry /= 10;
			--len1;
		}

		while (len2 >= 0) {
			m1 = num2[len2] - '0';
			carry = m1 + carry;
			str += (carry%10 + '0');
			carry /= 10;
			--len2;
		}

		while (carry) {
			str += (carry%10 + '0');
			carry /= 10;
		}
		reverse(str.begin(), str.end());
		return str;

	}
};