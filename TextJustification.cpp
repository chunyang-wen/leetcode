class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string>res;
        int len = words.size(), i = 0;
        while(i < len)
        {
            //if(words[i].size() == 0){i++; continue;}
            int rowlen = 0, j = i;
            while(j < len && rowlen + words[j].size() <= L)
                rowlen += (words[j++].size() + 1);
            //j-i是该行放入单词的数目
            if(j - i == 1)
            {//处理放入一个单词的特殊情况
                res.push_back(words[i]);
                addSpace(res.back(), L - words[i].size());
                i = j; continue;
            }
            //charaLen是当前行字母总长度
            int charaLen = rowlen - (j - i);
            //平均每个单词后的空格,j < len 表示不是最后一行
            int meanSpace = j < len ? (L - charaLen) / (j - i - 1) : 1;
            //多余的空格
            int leftSpace = j < len ? (L - charaLen) % (j - i - 1) : L - charaLen - (j - i -1);
            string tmp;
            for(int k = i; k < j - 1; k++)
            {
                tmp += words[k];
                addSpace(tmp, meanSpace);
                if(j < len && leftSpace > 0)
                {
                    tmp.push_back(' ');
                    leftSpace--;
                }
            }
            tmp += words[j - 1];//放入最后一个单词
            if(leftSpace > 0)addSpace(tmp, leftSpace); //对最后一行
            res.push_back(tmp);
            i = j;
        }
        return res;
    }
     
    void addSpace(string &s, int count)
    {
        for(int i = 1; i <= count; i++)
            s.push_back(' ');
    }
};