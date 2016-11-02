/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    const vector keyboard { " ", "", "abc", "def", // "0","1","2",...
            "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

    vector letterCombinations (const string &digits) {
        if (digits == "") return {};
        vector result;
        dfs(digits, 0, "", result);
        return result;
    }

    void dfs(const string &digits, size_t cur, string path,
            vector &result) {
        if (cur == digits.size()) {
            result.push_back(path);
            return;
        }
        for (auto c : keyboard[digits[cur] - "0"]) {
            dfs(digits, cur + 1, path + c, result);
        }
    }
};

