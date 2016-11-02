/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */


struct Block {
  int max, min;
};

class Solution {
public:
    int maximumGap(vector& nums) {
        int n = nums.size();
      
        if (nums.size() < 2) {
            return 0;
        }
        int min = nums[0];
        int max = nums[0];
        for (int i = 1; i < nums.size(); i++) {
           min = min < nums[i] ? min : nums[i];
           max = max > nums[i] ? max : nums[i];
        }
        if (max == min) {
          return 0;
        }
        int block_size = (max - min - 1) / n + 1;
        cout << block_size << endl;
        vector blocks(n);
        for (int i = 0; i < n; i++) {
          blocks[i].max = blocks[i].min = -1;
        }
        for (int i = 0; i < n; i++) {
          int block_id = (nums[i] - min) / block_size;
          if (blocks[block_id].max == -1) {
            blocks[block_id].min = blocks[block_id].max = nums[i];
          } else {
            blocks[block_id].min = blocks[block_id].min < nums[i] ? blocks[block_id].min : nums[i];
            blocks[block_id].max = blocks[block_id].max > nums[i] ? blocks[block_id].max : nums[i];
          }
        }
      
        int maxGap = -1;
        int lastNumber = blocks[0].max;
        for (int i = 1; i < n; i++) {
          if (blocks[i].min == -1) {
            continue;
          }
          maxGap = maxGap > blocks[i].min - lastNumber ? maxGap : blocks[i].min - lastNumber;
          lastNumber = blocks[i].max;
        }
        return maxGap;
    }
};

