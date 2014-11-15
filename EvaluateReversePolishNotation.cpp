class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        int result = 0;
        int op1,op2;
        stack<int> number;
        stack<char> op;
        int i = 0;
        int len = tokens.size();
        while (i < len) {
            switch(tokens[i][0]) {
                case '+':
                    // break;
                case '-':
                    // break;
                    // break;
				if (tokens[i].size() > 1) {
					number.push(atoi(tokens[i].c_str()));
					break;
				}
                case '*':
                    // break;
                case '/':
                    op2 = number.top();
                    number.pop();
                    op1 = number.top();
                    number.pop();
                    switch (tokens[i][0]) {
                        case '+':
                            number.push(op1+op2);
                            break;
                        case '-':
                            number.push(op1-op2);
                            break;
                        case '*':
                            number.push(op1*op2);
                            break;
                        case '/':
                            number.push(op1/op2);
                            break;
                    }
                    break;
                default:
                    number.push(atoi(tokens[i].c_str()));
                    break;
            }
            ++i;
        }
        result = number.top();
        number.pop();
        return result;
    }
};