class Solution {
public:
    double pow(double x, int n) {
        double ret = 1.0;
        bool isNeg = n < 0 ? (n = -n, true):false;
        
        while (n) {
            if (n%2 == 1) ret *= x;
            
            x *= x; n /= 2;
        }
        
        return isNeg?1/ret:ret;
    }
        
};