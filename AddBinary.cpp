class Solution {
public:
    string addBinary(string a, string b) {
        if (a.empty())
            return b;
        if (b.empty())
            return a;
            
        bool carry = false;
        

        int lenA = a.size();
        int lenB = b.size();
        
        int i(lenA-1),j(lenB-1);
        
        string str="";
        
        while (i >= 0 && j >= 0) {
            
            if (a[i] == '1' && b[j] == '1') {
                if (carry)
                    str += "1";
                else
                    str += "0";
                carry = true;
                --i;
                --j;
                continue;
                
            }
            
            if (a[i] == '1' || b[j] == '1') {
                if (carry) {
                    str += "0"; 
                    carry = true;
                }
                else {
                    str += "1";
                }
                --i;--j;
                continue;
            }
            
            if (carry) {
                carry = false;
                str += "1";
            }
            else
                str += "0";
                
            --i;
            --j;
            
        }
        
        while (i >= 0) {
            if (a[i] == '1' && carry) {
                
                str += "0";
                carry = true;
                --i;
                continue;
                
            }
            
            if (a[i] == '1' || carry) {
                str += "1";
                carry = false;
                --i;
                continue;
            }
            
            str += "0";
            --i;
        }
        
        while (j >= 0) {
            if (b[j] == '1' && carry) {
                
                str += "0";
                carry = true;
                --j;
                continue;
                
            }
            
            if (b[j] == '1' || carry) {
                str += "1";
                carry = false;
                --j;
                continue;
            }
            
            str += "0";
            --j;
        }
        
        if (carry) {
            str += "1";
        }
        
        reverse(str.begin(),str.end());
        
        return str;
            
        
    }
};