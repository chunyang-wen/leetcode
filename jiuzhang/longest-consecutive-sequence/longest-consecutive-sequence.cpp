/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    int longestConsecutive(vector& nums) {
        unordered_map hash;
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]] = true;
        }
        
        int max = 0;
        for (int i = 0; i < nums.size(); i++) {
            int up = nums[i];
            while (hash.find(up) != hash.end()) {
                hash.erase(up);
                up++;
            }
            int down = nums[i] - 1;
            while (hash.find(down) != hash.end()) {
                hash.erase(down);
                down--;
            }
            if (up - down - 1 > max) {
                max = up - down - 1;
            }
        }
        return max;
    }
};
