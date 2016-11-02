/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class node {
public: 
    node(){}
    node(int x, int v) {
        id = x;
        value = v;
    }
    int id, value;
};

bool cmp(const node &a, const node &b)  {
    return a.value < b.value;
}

class Solution {
public:
    
    int minCostII(vector>& costs) {
        if(costs.size() == 0) {
            return 0;
        }
        int n = costs.size();
        int k = costs[0].size();
        int ans[n+1][k];
        memset(ans, 0, sizeof(ans));
        vector now(3), last(3);
        now[0] = node(0, INT_MAX);
        now[1] = node(0, INT_MAX);
            
        for (int i = 1; i <= n; i++) {
            last = now;
            now[0] = node(0, INT_MAX);
            now[1] = node(0, INT_MAX);
            for (int j = 0; j < k ; j++) {
                if(j == last[0].id) {
                    ans[i][j] = ans[i-1][last[1].id] + costs[i-1][j]; 
                } else {
                    ans[i][j] = ans[i-1][last[0].id] + costs[i-1][j];
                }
                now[2] = node(j, ans[i][j]);
                sort(now.begin(), now.end(), cmp);
            }
        }
        
        return now[0].value;
    }
};
