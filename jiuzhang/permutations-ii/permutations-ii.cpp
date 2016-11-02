/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
private:
    void helper(vector > &results,
                vector &permutation,
                vector &nums,
                bool used[]) {
        if (nums.size() == permutation.size()) {
            results.push_back(permutation);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) {
                continue;
            }
            if (i > 0 && used[i - 1] == false && nums[i] == nums[i-1]) {
                continue;
            }

            used[i] = true;
            permutation.push_back(nums[i]);
            helper(results, permutation, nums, used);
            permutation.pop_back();
            used[i] = false;
        }
    }

public:
    vector > permuteUnique(vector<int> &nums) {
        vector > results;
        vector permutation;
        bool used[nums.size()];

        for (int i = 0; i < nums.size(); i++) {
            used[i] = false;
        }

        sort(nums.begin(), nums.end());

        helper(results, permutation, nums, used);
        return results;
    }
};
