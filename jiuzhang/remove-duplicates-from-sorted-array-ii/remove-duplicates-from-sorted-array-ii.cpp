/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector &nums) {
        // write your code here
        vector  B;
        if(nums.size() == 0)
            return 0;
        int before = nums[0] - 1;
        int countb = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(before != nums[i])
            {
                 B.push_back(nums[i]);
                 countb = 1;
                 before = nums[i];
            }
            else if(countb < 2 )
            {
                 B.push_back(nums[i]);
                 countb++ ;
                 before = nums[i];
            }
        }
        int len = 0;
        for(int i = 0; i < B.size(); i++)
            nums[len++] = B[i];
        return len;
    }
};

