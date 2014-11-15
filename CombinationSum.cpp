// backtracking
class Solution {
private:
    vector<vector<int> > res;
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());//为了输出结果递增，因此先对数组排序
        vector<int> tmpres;
        helper(candidates, 0, target, tmpres);
        return res;
    }
     
    //从数组candidates[index,...]寻找和为target的组合
    void helper(vector<int> &candidates, const int index, const int target, vector<int>&tmpres)
    {
        if(target == 0)
        {
            res.push_back(tmpres);
            return;
        }
        for(int i = index; i < candidates.size() && target >= candidates[i]; i++)
            if(i == 0 || candidates[i] != candidates[i-1])//由于每个数可以选取多次，因此数组中重复的数就不用考虑
            {
                tmpres.push_back(candidates[i]);
                helper(candidates, i, target - candidates[i], tmpres);
                tmpres.pop_back();
            }
    }
};