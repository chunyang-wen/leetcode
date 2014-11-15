// http://www.cnblogs.com/TenosDoIt/p/3771254.html
// we can use dfs/bfs
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res(1,"");
        string numap[] = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        for(int i = 0; i < digits.size(); i++)
        {
            vector<string>tmp;
            for(int j = 0; j < res.size(); j++)
                for(int k = 0; k < numap[digits[i] - '0'].size(); k++)
                    tmp.push_back(res[j] + numap[digits[i] - '0'][k]);
            res = tmp;
        }
         
        return res;
    }
};