/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班，
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

// O(n) memory, if you want O(1)memory take a look at the c++ version
public class Solution {
    public boolean increasingTriplet(int[] nums) {
        if (nums.length < 2)
            return false;
        int n = nums.length;
        boolean []has_first_small = new boolean[n];
        int smallest = nums[0];
        has_first_small[0] = false;
        for (int i = 0; i < n; i ++) {
            if (smallest < nums[i]) {
                has_first_small[i] = true;
            }
            smallest = Math.min(smallest, nums[i]);
        }
        
        int biggest = nums[n-1];
        for (int i = n-2; i >=0; i--) {
            if(has_first_small[i] == true) {
                if (nums[i] < biggest) {
                    return true;
                }
                biggest = Math.max(biggest, nums[i]);
            }
        }
        return false;
    }
}
