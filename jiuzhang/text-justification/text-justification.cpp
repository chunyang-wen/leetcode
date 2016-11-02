/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    string get_space(int num) {
        string now;
        while(num > 0) {
            now += " ";
            num--;
        }
        return now;
    }
    vector fullJustify(vector<string>& words, int maxWidth) {
        vector ans;
        if(words.size() == 0)
            return ans;
        
        int i = 0, j = 0, k;
        while(i < words.size()) {
            int now = words[i].size();
            for (j = i + 1; j < words.size(); j++){
                if (now + 1 + words[j].size() > maxWidth) {
                    break;
                }
                now = now + 1 + words[j].size();
            }
            int space = 0, extra = 0;
            string res;
            
            if (j == i + 1 || j == words.size()) {
                res = words[i];
                for (k = i + 1; k < j; k++) {
                    res = res + " " + words[k];
                }
                space =  maxWidth - now;   
                res += get_space(space);
            } else {
                int spaceSlot = j - i - 1;
                space = (maxWidth - now) / spaceSlot + 1;
                extra = (maxWidth - now) % spaceSlot;
                
                for(k = i; k < j - 1; k++) {
                    res += words[k];
                    res += get_space(space);
                    if (extra > 0) {
                        res += " ";
                        extra --;
                    }
                }
                res += words[k];
            }
            i = j; 
            ans.push_back(res);
        }
        return ans;
    }
};
