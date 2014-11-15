class Solution {
public:
    string minWindow(string S, string T) {
        int lens = S.size(), lent = T.size();
        int srcCnt[256] = {0};//T中每个字母的个数
        int foundCnt[256] = {0};//当前找到T中每个字母的个数
        for(int i = 0; i < lent; i++)
            srcCnt[T[i]]++;
        int hasFound = 0;//已经找到的字母数目
        int winStart = -1, winEnd = lens;//窗口的左右边界
        //两个指针start和i一起扫描
        for(int i = 0, start = 0; i < lens; i++)
            if(srcCnt[S[i]] != 0)
            {
                foundCnt[S[i]]++;
                if(foundCnt[S[i]] <= srcCnt[S[i]])hasFound++;
                if(hasFound == lent)
                {//找到了一个满足的窗口
                    while(srcCnt[S[start]] == 0 ||
                          foundCnt[S[start]] > srcCnt[S[start]])
                    {
//缩减窗口
                        if(srcCnt[S[start]] != 0)
                            foundCnt[S[start]]--;
                        start++;
                    }
                    if(winEnd - winStart > i - start)
                    {
                        winStart = start;
                        winEnd = i;
                    }
                    foundCnt[S[start]]--;
                    start++;
                    hasFound--;
                }
            }
        return winStart != -1 ? S.substr(winStart, winEnd - winStart +1) : "";
    }
};