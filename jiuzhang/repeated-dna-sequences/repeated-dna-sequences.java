/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班，
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

public class Solution {
    public int encode(String s) {
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == "A") {
                sum = sum * 4;
            } else if (s.charAt(i) == "C") {
                sum = sum * 4 + 1;
            } else if (s.charAt(i) == "G") {
                sum = sum * 4 + 2;
            } else {
                sum = sum * 4 + 3;
            }
        }
        return sum;
    }
    public List findRepeatedDnaSequences(String s) {
        HashSet hash = new HashSet<Integer>();
        HashSet dna = new HashSet<String>();
        for (int i = 9; i < s.length(); i++) {
            String subString = s.substring(i - 9, i + 1);
            int encoded = encode(subString);
            if (hash.contains(encoded)) {
                dna.add(subString);
            } else {
                hash.add(encoded);
            }
        }
        List result = new ArrayList<String>();
        for (String d: dna) {
            result.add(d);
        }
        return result;
    }
}
