/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

bool cmp(pair&x, pair<int, int>&y) {
  return x.first != y.first ? x.first  y.second;
}

class Solution {
public:
  int maxEnvelopes(vector>& envelopes) {
    int n = envelopes.size();
    if (n == 0) {
        return 0;
    }
    
    sort(envelopes.begin(), envelopes.end(), cmp);
    vector dp(n), height(n+1, INT_MAX);
    for (int i = 0; i < n; i++) {
      int k = lower_bound(height.begin(), height.end(), envelopes[i].second) - height.begin() ;
      dp[i] = k;
      height[k] = envelopes[i].second;
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans = max(ans, dp[i]);
    }
    return ans + 1;
  }
};
