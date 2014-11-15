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
    vector<Interval> merge(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), IntervalCMP());
        int len = intervals.size();
        vector<Interval> res;
        int start;
        int end;
        for (int i = 0; i < len; ++i) {
            if (intervals[i].start > intervals[i].end)
                continue;
            start = intervals[i].start;
            end = intervals[i].end;
            while ((i < len - 1) && end >= intervals[i+1].start) {
                if (end < intervals[i+1].end)
                    end = intervals[i+1].end;
                    ++i;
            }
            res.push_back(Interval(start,end));
            if ((i == len - 1) && end >= intervals[len-1].end)
                break;
        }
        return res;
    }
private:
    struct IntervalCMP {
        bool operator()(const Interval &left, const Interval &right) {
            return left.start < right.start;
        }
    };
};