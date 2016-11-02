/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

#include 
#include 
using namespace std;

class Solution {
public:
	/**
	 * @param gas: a vector of integers
	 * @param cost: a vector of integers
	 * @return: an integer
	 */
	int canCompleteCircuit(vector &gas, vector<int> &cost) {
		auto const L = gas.size();
		auto sum = accumulate(gas.begin(), gas.end(), 0) - accumulate(cost.begin(), cost.end(), 0);
		if (sum < 0)
			return -1;
		int a = 0;
		for (int i = 0; i < L; i++) {
			if (gas[i] - cost[i] >= 0) {
				a = i;
				break;
			}
		}
		int b = a;
		auto diff = [&gas, &cost](int x) {return gas[x] - cost[x];};
		int gas_remain = diff(a);
		while ((b + 1) % L != a) {
			if (diff((b + 1) % L) + gas_remain >= 0) {
				b = (b + 1) % L;
				gas_remain += diff(b);
			} else if (diff((L + a - 1) % L) + gas_remain >= 0) {
				a = (L + a - 1) % L;
				gas_remain += diff(a);
			} else {
				return -1;
			}
		}
		return a;
	}
};

