/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector insert(vector<Interval>& intervals, Interval newInterval) {
        vector ans;
        if(intervals.size() == 0) {
            ans.push_back(newInterval);
            return ans;
        } 
        int ins_pos = 0;
        for (Interval now : intervals) {
            if(now.end < newInterval.start) {
                ins_pos++;
                
                ans.push_back(now);
            } else if(newInterval.end < now.start) {
                ans.push_back(now);
            } else {
                newInterval.start = min(newInterval.start, now.start);
                newInterval.end = max(newInterval.end, now.end);
            }
        }
        ans.insert(ans.begin() + ins_pos, newInterval);
        return ans;
    }
};
