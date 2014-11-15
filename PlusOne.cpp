class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        if (digits.empty())
            return vector<int>(1,1);
        int len = digits.size();
        int i = 0;
        int carry = 1;
        
        reverse(digits.begin(), digits.end());
        
        while ((i < len) && carry) {
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
            ++i;
        }
        
        if (carry)
            digits.push_back(carry);
            
        reverse(digits.begin(), digits.end());
        
        return digits;
    }
};