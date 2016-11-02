/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    /**
     * @param nums1 an integer array of length m with digits 0-9
     * @param nums2 an integer array of length n with digits 0-9
     * @param k an integer and k <= m + n
     * @return an integer array
     */
    vector maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        // Write your code here
        int len1 = nums1.size(), len2 = nums2.size();
        vector results;
        for (int k1 = max(k - len2, 0); k1 <= min(k, len1); ++k1)
            results = max(results, maxNumber(maxNumber(nums1, k1), maxNumber(nums2, k - k1)));
        return results;
    }

    vector maxNumber(vector<int> nums, int k) {
        int drop = nums.size() - k;
        vector results;
        for (int num : nums) {
            while (drop && results.size() && results.back() < num) {
                results.pop_back();
                drop--;
            }
            results.push_back(num);
        }
        results.resize(k);
        return results;
    }

    vector maxNumber(vector<int> nums1, vector<int> nums2) {
        vector results;
        while (nums1.size() + nums2.size()) {
            vector& now = nums1 > nums2 ? nums1 : nums2;
            results.push_back(now[0]);
            now.erase(now.begin());
        }
        return results;
    }
};

