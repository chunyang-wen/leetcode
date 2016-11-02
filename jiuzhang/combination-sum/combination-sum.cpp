/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
private:
    const int index_count;
    vector > results;
public:
    Solution() : index_count(10000) {};
    void backtrace(int target, int sum, vector &candidates, int index[], int n)
    {
        if (sum > target) {
            return;    
        }
        if (sum == target)
        {
            vector result;
            for (int i = 1; i <= n; ++i)
            {
                result.push_back(candidates[index[i]]);    
            }
            results.push_back(result);
            return;
        }
        for (int i = index[n]; i < candidates.size(); ++i)
        {
            index[n+1] = i;
            backtrace(target, sum+candidates[i], candidates, index, n+1);
        }
    }
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    vector > combinationSum(vector<int> &candidates, int target) {
        // write your code here
        sort(candidates.begin(), candidates.end());
        int m = 0, n = candidates.size();
        for (int i = 1; i < n; ++i)
            if (candidates[i] != candidates[m])
                candidates[++m] = candidates[i];
        candidates.resize(m + 1);

        int *index = new int[index_count];
        memset(index, 0, sizeof(int)*index_count);
        
        results.clear();
        backtrace(target, 0, candidates, index, 0);

        delete[] index;

        return results;
    }
};
