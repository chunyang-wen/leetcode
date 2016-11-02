/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班，
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

public class Solution {
    public String reverseVowels(String s) {
        int[] pos = new int[s.length()];
        int cnt = 0;
        HashSet vowel = new HashSet<Character>();
        vowel.add("a");
        vowel.add("e");
        vowel.add("i");
        vowel.add("o");
        vowel.add("u");
        vowel.add("A");
        vowel.add("E");
        vowel.add("I");
        vowel.add("O");
        vowel.add("U");
        
        for (int i = 0; i < s.length(); i++) {
            if (vowel.contains(s.charAt(i))) {
                pos[cnt] = i;
                cnt++;
            }
        }
        
        char[] ans = new char[s.length()];
        ans = s.toCharArray();
        for (int i = 0; i < cnt; i++) {
            ans[pos[i]] = s.charAt(pos[cnt - i - 1]);
        }
        return String.valueOf(ans);
    }
}
