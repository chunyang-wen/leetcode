/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

#include 

using namespace std;

class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that"s next permuation
     */
    vector nextPermutation(vector<int> &nums) {
        int i = nums.size() - 2;  
        while (i >= 0 && nums[i] >= nums[i + 1]) {  
            i--;  
        }  
        if (i < 0) {  
            reverse(nums.begin(), nums.end() - 1);  
        }  
        else {  
            int j = i + 2;  
            while (j  nums[i]) {  
                j++;  
            }  
            j--;  
              
            nums[i] ^= nums[j];  
            nums[j] ^= nums[i];  
            nums[i] ^= nums[j];  
              
            reverse(nums.begin() + i + 1, nums.end() - 1);  
        }  
        return nums;
    }
    private:  
    void reverse(vector::iterator i1, vector<int>::iterator i2) {  
        while (i1 < i2) {  
            *i1 ^= *i2;  
            *i2 ^= *i1;  
            *i1 ^= *i2;  
       
            i1++;  
            i2--;  
        }  
    }
};

