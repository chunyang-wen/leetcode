/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班，
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

#### 参考程序 - Java



	public class Solution {

		public int addDigits(int num) {

			if (num == 0) {

			    return 0;

			}

			int ans = 0;

			for (; num != 0; ) {

			    int digit = num % 10;

			    ans = (ans * 10 + digit) % 9;

			    num /= 10;

			}

			return ans == 0 ? 9 : ans;

		}

	}

