/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

#include 
bool cmp(const string s1, const string s2) {
    return (s1 + s2) > (s2 + s1);
}
class Solution {
public:
    /**
     [email&#160;protected]</a><script data-cfhash='f9e31' type="text/javascript">/* <![CDATA[ */!function(t,e,r,n,c,a,p){try{t=document.currentScript||function(){for(t=document.getElementsByTagName('script'),e=t.length;e--;)if(t[e].getAttribute('data-cfhash'))return t[e]}();if(t&&(c=t.previousSibling)){p=t.parentNode;if(a=c.getAttribute('data-cfemail')){for(e='',r='0x'+a.substr(0,2)|0,n=2;a.length-n;n+=2)e+='%'+('0'+('0x'+a.substr(n,2)^r).toString(16)).slice(-2);p.replaceChild(document.createTextNode(decodeURIComponent(e)),c)}p.removeChild(t)}}catch(u){}}()/* ]]> */</script> num: A list of non negative integers
     [email&#160;protected]</a><script data-cfhash='f9e31' type="text/javascript">/* <![CDATA[ */!function(t,e,r,n,c,a,p){try{t=document.currentScript||function(){for(t=document.getElementsByTagName('script'),e=t.length;e--;)if(t[e].getAttribute('data-cfhash'))return t[e]}();if(t&&(c=t.previousSibling)){p=t.parentNode;if(a=c.getAttribute('data-cfemail')){for(e='',r='0x'+a.substr(0,2)|0,n=2;a.length-n;n+=2)e+='%'+('0'+('0x'+a.substr(n,2)^r).toString(16)).slice(-2);p.replaceChild(document.createTextNode(decodeURIComponent(e)),c)}p.removeChild(t)}}catch(u){}}()/* ]]> */</script>: A string
     */
    string largestNumber(vector &num) {
        // write your code here
        vector s_num(num.size());
        stringstream stream;
        for (int i = 0; i < num.size(); ++i) {
            stream << num[i];
            stream >> s_num[i];
            stream.clear();
        }
        sort(s_num.begin(), s_num.end(), cmp);
        string tmp_res;
        for (int i = 0; i < s_num.size(); ++i) {
            tmp_res += s_num[i];
        }
        string res;
        bool flag = false;
        for (int i = 0; i < tmp_res.size(); ++i) {
            if (tmp_res[i] != "0") {
                res.push_back(tmp_res[i]);
                flag = true;
            } else if (flag) {
                res.push_back(tmp_res[i]);
            }
        }
        if (!flag) res.push_back("0");
        return res;
    }
};

