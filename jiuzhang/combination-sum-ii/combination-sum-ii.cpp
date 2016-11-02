/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
	/**
	 * @param num: Given the candidate numbers
	 * @param target: Given the target number
	 * @return: All the combinations that sum to target
	 */
    vector > combinationSum2(vector<int> &num, int target) {
		// write your code here
        sort(num.begin(), num.end());
        vector stack, rec; int sum=0, cur=0;
        vector > ans;
        while (cur<num.size() && num[cur]+sum<=target) {
			stack.push_back(num[cur]);
			rec.push_back(cur);
			sum+=num[cur++];
		}
		if (sum==target) ans.push_back(stack);
		while (rec.size()!=0) {
			cur=rec.back(); int x=num[cur];
			sum-=x; stack.pop_back(); rec.pop_back();
			for (++cur; cur<num.size(); ++cur)
				if (num[cur]!=x || sum+num[cur]>target) break;
			if (cur<num.size() && num[cur]!=x)
				while (cur<num.size() && num[cur]+sum<=target) {
					stack.push_back(num[cur]);
					rec.push_back(cur);
					sum+=num[cur++];
				}
			if (sum==target) ans.push_back(stack);
		}
		return ans;
    }
};

