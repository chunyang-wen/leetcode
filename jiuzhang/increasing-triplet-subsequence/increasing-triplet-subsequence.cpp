/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

// O(1) memory
class Solution {
public:
    bool increasingTriplet(vector& nums) {
        int first = INT_MAX, second = INT_MAX;
        for(int now : nums){
            if(now <= first) {  // keep update the first smallest
                first = now;
                continue; // we don"t need this actually
            }
            if(first < now && now <= second) { // update the second smallest when we have first smallest
                second = now;
                continue;  // we don"t need this actually
            } 
            if( now > second) { // we have three smallest
                return true;
            }
        }
        return false;
    }
};
