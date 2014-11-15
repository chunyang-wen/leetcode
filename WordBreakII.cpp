// http://www.cnblogs.com/TenosDoIt/p/3385644.html
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict)
    {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<string> result;
        if(dict.empty())
            return result;
        const int len = s.size();
        bool canBreak[len]; //canBreak[i] = true 表示s[0~i]是否能break
        memset(canBreak, 0, sizeof(bool)*len);
        bool **pre = new bool *[len];//如果s[k..i]是字典中的单词,则pre[i][k]=true
        for(int i = 0; i < len; i++)
        {
            pre[i] = new bool[len];
            memset(pre[i], 0 , sizeof(bool)*len);
        }

        for(int i = 1; i <= len; i++)
        {
            if(dictContain(dict, s.substr(0, i)))
            {
                canBreak[i-1] = true;
                pre[i-1][0] = true;
            }
            if(canBreak[i-1] == true)
            {
                for(int j = 1; j <= len - i; j++)
                {
                    if(dictContain(dict,s.substr(i, j)))
                    {
                        canBreak[j+i-1] = true;
                        pre[j+i-1][i] = true;
                    }
                }
            }
        }
        //return false;
        vector<int> insertPos;
        getResult(s, pre, len, len-1, insertPos, result);
        return result;
    }

    bool dictContain(unordered_set<string> &dict, string s)
    {
        unordered_set<string>::iterator ite = dict.find(s);
        if(ite != dict.end())
            return true;
        else return false;
    }

    //在字符串的某些位置插入空格，返回新字符串
    string insertBlank(string s,vector<int>pos)
    {
        string result = "";
        int base = 0;
        for(int i = pos.size()-1; i>=0; i--)
        {
            if(pos[i] == 0)continue;//开始位置不用插入空格
            result += (s.substr(base, pos[i]-base) + " ");
            base = pos[i];
        }
        result += s.substr(base, s.length()-base);
        return result;
    }

    //从前驱路径中构造结果
    void getResult(string s, bool **pre, int len, int currentPos,
                   vector<int>insertPos,
                   vector<string> &result)
    {
        if(currentPos == -1)
        {
            result.push_back(insertBlank(s,insertPos));
            //cout<<insertBlank(s,insertPos)<<endl;
            return;
        }
        for(int i = 0; i < len; i++)
        {
            if(pre[currentPos][i] == true)
            {
                insertPos.push_back(i);
                getResult(s, pre, len, i-1, insertPos, result);
                insertPos.pop_back();
            }
        }
    }
};