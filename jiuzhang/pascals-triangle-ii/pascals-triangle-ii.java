/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班，
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

public class Solution {
    public ArrayList getRow(int rowIndex) {
        ArrayList rst = new ArrayList<Integer>();
        rowIndex += 1;
        if (rowIndex == 0) {
            return rst;
        }

        rst.add(1);
        for (int i = 1; i < rowIndex; i++) {
            ArrayList tmp = new ArrayList<Integer>(i+1);
            for (int j = 0; j < i + 1; j++) {
                tmp.add(-1);
            }
            tmp.set(0, rst.get(0));
            tmp.set(i, rst.get(i - 1));
            for (int j = 1; j < i; j++) {
                tmp.set(j, rst.get(j - 1) + rst.get(j));
            }
            rst = tmp;
        }
        return rst;
    }
}
