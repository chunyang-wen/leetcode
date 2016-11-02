/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班，
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

// 方法一 搜索
public class Solution {
    public boolean canWin(String s) {
        boolean[] state = new boolean[s.length()];
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == "+") {
                state[i] = true;
            } else {
                state[i] = false;
            }
        }
        return search(state);
    }
    public boolean search(boolean[] state) {
        for (int i = 0; i < state.length - 1; i++) {
            if (state[i] && state[i + 1]) {
                state[i] = false;
                state[i + 1] = false;
                if (!search(state)) {
                    state[i] = true;
                    state[i + 1] = true;
                    return true;
                } else {
                    state[i] = true;
                    state[i + 1] = true;
                }
            }
        }
        return false;
    }
}


// 方法二 nim 博弈
public class Solution {
    public boolean canWin(String s) {
        int[] nim = new int[s.length() + 1];
        boolean[] happen = new boolean[s.length() + 1];
        for (int i = 2; i <= s.length(); i++) {
            for (int j = 0; j < i - j - 1; j++) {
                happen[nim[j] ^ nim[i - j - 2]] = true;
            }
            boolean nimEmpty = true;
            for (int j = 0; j <= s.length(); j++) {
                if (!happen[j] && nimEmpty) {
                    nimEmpty = false;
                    nim[i] = j;
                } else {
                    happen[j] = false;
                }
            }
        }
        int ans = 0;
        int len = 0;
        s = s + "-";
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == "+") {
                len++;
            } else {
                ans = ans ^ nim[len];
                len = 0;
            }
        }
        if (ans == 0) {
            return false;
        } else {
            return true;
        }
    }
}
