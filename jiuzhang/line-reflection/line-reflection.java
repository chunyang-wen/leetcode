/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班，
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

public class Solution {
    public boolean isReflected(int[][] points) {
        int max = 0, min = 0;
        HashMap> hashmap = new HashMap<>();
        for (int i = 0; i < points.length; i++) {
            max = Math.max(points[i][0], max);
            min = Math.min(points[i][0], min);
            if (!hashmap.containsKey(points[i][1])) {
                HashSet hashset = new HashSet<>();
                hashset.add(points[i][0]);
                hashmap.put(points[i][1], hashset);
            } else {
                hashmap.get(points[i][1]).add(points[i][0]);
            }
        }
        for (int i = 0; i < points.length; i++) {
            if (!hashmap.containsKey(points[i][1]) || !hashmap.get(points[i][1]).contains(max + min - points[i][0])) {
                return false;
            }
        }
        return true;
    }
}
