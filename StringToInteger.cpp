class Solution {
public:
	int atoi(const char *str) {

		while (str && (*str) == ' ') ++str;

		if (!str)
			return 0;

		if (isalpha(*str))
			return 0;

		bool isNeg = false;    
		if ((*str) == '-') {
			isNeg = true;
			++str;
		}
		else if ((*str) == '+')
			++str;

		int num = 0;

		int prev = num;

		while ((*str) != ' ' && (*str) != '\0') {

			if (!((*str)<='9' && (*str) >= '0'))
				return num;



			num *= 10;

			if (num != 0) {
				double x = num*1.0/prev;
				if (int(x) != 10) {
					if (isNeg)
						return INT_MIN;
					else
						return INT_MAX;
				}
			}

			if (isNeg) {
				num -= ((*str)-'0');
			}
			else {
				num += ((*str)-'0');
			}

			if (isNeg) {
				if (num > 0 ||(prev*10-num) != ((*str)-'0')) {
					return INT_MIN;
				}
			}
			else if (num < 0 || (num - prev*10) != ((*str)-'0')) {
				return INT_MAX;
			}

			++str;
			prev = num;

		}

		return num;
	}
};