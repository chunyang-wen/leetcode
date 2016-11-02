/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

// sort & merge
class Solution {
public:
    /**
     * @param nums1 an integer array
     * @param nums2 an integer array
     * @return an integer array
     */
    vector intersection(vector<int>& nums1, vector<int>& nums2) {
        // Write your code here
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector intersect;
        vector::iterator it1 = nums1.begin(), it2 = nums2.begin();
        while ((it1 != nums1.end()) && (it2 != nums2.end()))
        {
            if (*it1 < *it2) it1++;
            else if (*it1 > *it2) it2++;
            else 
            {
                intersect.push_back(*it1); 
                it1++; it2++;
            }
        }

        auto last = unique(intersect.begin(), intersect.end());
        intersect.erase(last, intersect.end());
        return intersect;
    }
};
