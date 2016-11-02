/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    vector > ans;
    vector > findLadders(string start, string end, unordered_set<string> &dict) {
        dict.insert(end);
        int dsize = dict.size(), len = start.length();
        unordered_map > next;
        unordered_map vis;
        queue q;
        vector path;
        ans.clear();
        q.push(start);
        vis[start] = 0;
        while (!q.empty()) {
            string s = q.front(); q.pop();
            if (s == end) break;
            int step = vis[s];
            vector snext;
            for (int i = 0; i < len; i++) {
                string news = s;
                for (char c = "a"; c <= "z"; c++) {
                    news[i] = c;
                    if (c == s[i] || dict.find(news) == dict.end()) continue;
                    auto it = vis.find(news);
                    if (it == vis.end()) {
                        q.push(news);
                        vis[news] = step + 1;
                    }
                    snext.push_back(news);
                }
            }
            next[s] = snext;
        }
        path.push_back(start);
        dfspath(path, next, vis, start, end);
        return ans;
    }
    void dfspath(vector &path,  unordered_map<string, vector<string> > &next,
                 unordered_map &vis, string now, string end){
        if (now == end) ans.push_back(path);
        else {
            auto vec = next[now];
            int visn = vis[now];
            for (int i = 0; i < vec.size(); i++) {
                if (vis[vec[i]] != visn + 1) continue;
                path.push_back(vec[i]);
                dfspath(path, next, vis, vec[i], end);
                path.pop_back();
            }
        }
    }
};
