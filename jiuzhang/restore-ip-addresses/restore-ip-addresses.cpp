/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    /**
     * @param s the IP string
     * @return All possible valid IP addresses
     */
    
    bool ok(string x) {
        if (x.size() != 1 && x[0] == "0") return 0;
        int res = 0;
        for (auto i : x) {
            res = res * 10 + i - "0";
        }
        return res < 256;
    }
    
    vector restoreIpAddresses(string& s) {
        // Write your code here
        vector res;
        for (int i = 1; i <= 3; i++) {
            for (int j = 1; j <= 3; j++) {
                for (int k = 1; k <= 3; k++) {
                    for (int l = 1; l <= 3; l++) {
                        if (i + j + k + l == s.size()) {
                            string a(s.begin() + 0, s.begin() + i),
                                   b(s.begin() + i, s.begin() + i + j),
                                   c(s.begin() + i + j, s.begin() + i + j + k),
                                   d(s.begin() + i + j + k, s.begin() + i + j + k + l);
                            if (ok(a) && ok(b) && ok(c) && ok(d)) {
                                res.push_back(a + "." + b + "." + c + "." + d);
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};
