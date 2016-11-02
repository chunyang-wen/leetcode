/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    // 字符串转int，注意判断超出Int范围
    int myAtoi(string str) {
        if (str == "") return 0;
        // 去首尾空格
        str.erase(0, str.find_first_not_of(" "));
        str.erase(str.find_last_not_of(" ") + 1);
        
        int i = 0, len = str.length(), sign = 1;
        while ( i < len && str[i] == " ") i++;
        if (i == len) return 0;
        if (str[i] == "+") {
            sign = 1;
            i++;
        } else 
            if (str[i] == "-") {
                sign = -1;
                i++;
            }
        // 转换结果可能超出int范围，使用long long作为转换后接收变量的类型
        long long ret = 0;
        for (; i < len; i++) {
            if (str[i]  "9") break;
            ret = ret * 10 + (str[i] - "0");
            if (ret > INT_MAX) break;
        }
        ret *= sign;
        if (ret > INT_MAX) return INT_MAX;
        if (ret < INT_MIN) return INT_MIN;
        return ret;
    }
};
