/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    bool isValidSudoku(const vector>& board) {
        bool used[9];
        for (int i = 0; i < 9; ++i) {
            fill(used, used + 9, false);
            for (int j = 0; j < 9; ++j) // 检查行
                if (!check(board[i][j], used))
                    return false;
            fill(used, used + 9, false);
            for (int j = 0; j < 9; ++j) // 检查列
                if (!check(board[j][i], used))
                    return false;
        }
        for (int r = 0; r < 3; ++r) // 检查9 个子格子
            for (int c = 0; c < 3; ++c) {
                fill(used, used + 9, false);
                for (int i = r * 3; i < r * 3 + 3; ++i)
                    for (int j = c * 3; j < c * 3 + 3; ++j)
                        if (!check(board[i][j], used))
                            return false;
            }
        return true;
    }
    bool check(char ch, bool used[9]) {
        if (ch == ".") return true;
        if (used[ch - "1"]) return false;
        return used[ch - "1"] = true;
    }
};

