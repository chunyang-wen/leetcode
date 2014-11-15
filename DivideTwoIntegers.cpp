class Solution {
public:
    int divide(int dividend, int divisor) {
        unsigned int divd = dividend, divs = divisor;//使用unsigned防止-2147483648符号取反后溢出
        if(divisor < 0)divs = -divs;//负数全部转化为正数
        if(dividend < 0)divd = -divd;
         
        int res = 0;
        while(divd >= divs)
        {
            long long a = divs;//使用long long防止移位溢出
            int i;
            for(i = 1; a <= divd; i++)
                a <<= 1;
            res += (1 << (i-2));
            divd -= (divs << (i-2));
        }
         
        return (dividend>0 ^ divisor>0) ? -res : res;
    }
};