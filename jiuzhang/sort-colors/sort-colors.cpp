/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution{
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2 
     * @return: nothing
     */    
    void sortColors(vector &nums) {
        int left = 0, right = nums.size() - 1;
        int middle = 0;
        
        // should be <= not <
        while (middle <= right) {
            if (nums[middle] == 0) {
                swap(nums[middle], nums[left]);
                left++;
                middle++;
            } else if (nums[middle] == 1) {
                middle++;
            } else {
                swap(nums[middle], nums[right]);
                right--;
            }
        }
    }
};
