/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班，
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

public class Solution {
  private boolean canSurvive(int health, int[][] dungeon) {
    int n = dungeon.length, m = dungeon[0].length;
    int[][] f = new int[n][m];

    f[0][0] = dungeon[0][0] + health;
    if (f[0][0] <= 0) {
      return false;
    }
    
    for (int i = 1; i < n; i++) {
      f[i][0] = f[i - 1][0] == Integer.MIN_VALUE
                ? Integer.MIN_VALUE
                : f[i - 1][0] + dungeon[i][0];
      if (f[i][0] <= 0) {
        f[i][0] = Integer.MIN_VALUE;
      }
    }
    for (int i = 1; i < m; i++) {
      f[0][i] = f[0][i - 1] == Integer.MIN_VALUE
                ? Integer.MIN_VALUE
                : f[0][i - 1] + dungeon[0][i];
      if (f[0][i] <= 0) {
        f[0][i] = Integer.MIN_VALUE;
      }
    }
    
    for (int i = 1; i < n; i++) {
      for (int j = 1; j < m; j++) {
        f[i][j] = Math.max(f[i - 1][j], f[i][j - 1]);
        if (f[i][j] == Integer.MIN_VALUE) {
          continue;
        }
        f[i][j] += dungeon[i][j];
        if (f[i][j] <= 0) {
          f[i][j] = Integer.MIN_VALUE;
        }
      }
    }
    
    return f[n - 1][m - 1] > 0;
  }
  
  public int calculateMinimumHP(int[][] dungeon) {
    int start = 1, end = Integer.MAX_VALUE - 1;
    while (start + 1 < end) {
      int mid = (end - start) / 2 + start;
      if (canSurvive(mid, dungeon)) {
        end = mid;
      } else {
        start = mid;
      }
    }
    if (canSurvive(start, dungeon)) {
      return start;
    }
    return end;
  }
}
