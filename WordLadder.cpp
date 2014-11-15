// http://www.cnblogs.com/TenosDoIt/p/3443512.html
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        //BFS遍历找到的第一个匹配就是最短转换,空字符串是层与层之间的分隔标志
        queue<string> Q;
        Q.push(start); Q.push("");
        int res = 1;
        while(Q.empty() == false)
        {
            string str = Q.front();
            Q.pop();
            if(str != "")
            {
                int strLen = str.length();
                for(int i = 0; i < strLen; i++)
                {
                    char tmp = str[i];
                    for(char c = 'a'; c <= 'z'; c++)
                    {
                        if(c == tmp)continue;
                        str[i] = c;
                        if(str == end)return res+1;
                        if(dict.find(str) != dict.end())
                        {
                            Q.push(str);
                            dict.erase(str);
                        }
                    }
                    str[i] = tmp;
                }
            }
            else if(Q.empty() == false)
            {//到达当前层的结尾，并且不是最后一层的结尾
                res++;
                Q.push("");
            }
        }
        return 0;
    }
};