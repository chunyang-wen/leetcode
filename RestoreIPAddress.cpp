// http://www.cnblogs.com/TenosDoIt/p/3448588.html
// we should divide the problem into subproblems
// then we can conquer one by one.
class Solution { 
public:
    vector<string> restoreIpAddresses(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<string> res;
        string tmpres;
        restoreIpAddressesRecur(s, 0, 4, tmpres, res);
        return res;
    }
    //从s的start位置开始计算，ip地址还需要num个域（共4个域）
    //tmpres表示当前计算好的部分ip
    void restoreIpAddressesRecur(string &s, int start, int num, 
        string &tmpres, vector<string> &res)
    {
        int len = s.size();
        if(num == 0)
        {
            if(start == len)//已经计算好了一个ip
            {
                tmpres.erase(--tmpres.end());//去掉最后的“.”
                res.push_back(tmpres);
                tmpres.push_back('.');
            }
            return;
        }
        //不满足最小或最大长度关系
        if(len - start < num || len - start > num*3)return;
        int tmplen = tmpres.size();
        string tmpstr;
        for(int i = 1; i <= 3 && start + i <= len; i++)
        {//ip地址的一个域最多包含三个数字
            if(validRegion(s, start, start+i-1) == false)continue;
            tmpstr = s.substr(start, i) + ".";
            tmpres += tmpstr;
            restoreIpAddressesRecur(s, start+i, num-1, tmpres, res);
            tmpres.erase(tmplen, i+1);
        }
    }
    //判断ip地址的一个域是否合法
    bool validRegion(string &s, int istart, int iend)
    {
        if(iend > istart && s[istart] == '0')return false;
        int res = 0;
        for(int i = istart; i <= iend; i++)
            res = res*10 + (s[i] - '0');
        if(res >= 0 && res <= 255)return true;
        else return false;
    }
};