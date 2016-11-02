/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    string int_to_string(int j) {
        stringstream in;
        in << j;
        string temp;
        in >> temp;
        return temp;    
    }
    
    string genate(string s) {
        string now;
        int j = 0;
        for(int i = 0; i < s.size(); i += j) {
            for(j = 0; j + i < s.size(); j++) {
                if(s[i] != s[i+j]) {
                    break;
                } 
            }
            now = now + int_to_string(j) + s[i];
        }
        return now;
    }
    
    string countAndSay(int n) {
        string s("1");
        
        while(--n) {
            s = genate(s);
        }
        return s;
    }
};
