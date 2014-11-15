class Solution {
private:
    vector<vector<int> >res;
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> tmpres;
        helper(candidates, 0, target, tmpres, 0);
        return res;
    }
     
    //从数组candidates[index,...]寻找和为target的组合,times为前一个数字candidates[index-1]重复出现的次数
    void helper(vector<int> &candidates, const int index, const int target, vector<int>&tmpres, int times)
    {
        if(target == 0)
        {
            res.push_back(tmpres);
            return;
        }
        for(int i = index; i < candidates.size() && target >= candidates[i]; i++)
        {
            if(i > 0 && candidates[i] == candidates[i-1])times++;
            else times = 1;
            if(times == 1 || (tmpres.size() >= times-1 && tmpres[tmpres.size()-times+1] == candidates[i]))
            {
                tmpres.push_back(candidates[i]);
                helper(candidates, i+1, target - candidates[i], tmpres, times);
                tmpres.pop_back();
            }
        }
    }
};