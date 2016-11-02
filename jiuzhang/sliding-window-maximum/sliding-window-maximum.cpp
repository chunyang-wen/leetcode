/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The maximum number inside the window at each moving.
     */
    
    void inQueue(deque &Q, int num) {
        while (!Q.empty() && Q.back() < num) {
            Q.pop_back();
        }
        Q.push_back(num);
    }
    
    void outQueue(deque &Q, int num) {
        if (Q.front() == num) {
            Q.pop_front();
        }
    }
    
    vector maxSlidingWindow(vector<int> &nums, int k) {
        deque Q;
        vector result;
        
        for (int i = 0; i < k - 1; i++) {
            inQueue(Q, nums[i]);
        }
        
        for (int i = k - 1; i < nums.size(); i++) {
            inQueue(Q, nums[i]);
            result.push_back(Q.front());
            outQueue(Q, nums[i - k + 1]);
        }
        
        return result;
    }
};


