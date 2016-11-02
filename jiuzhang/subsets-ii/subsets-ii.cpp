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
    vector > result;
    bool equls( vector a, vector<int> b){
        if (a.size() != b.size())
            return false;
        int cnt = a.size();
        for (int i = 0; i < cnt;++i)
            if (a[i]!=b[i]) return false;
        return true;
    }
    void dfs(vector tmp, int x , vector<int> nums) {
        if (x == nums.size()) {
            int cnt = result.size();
            for ( int i = 0; i  < cnt ; ++i)
                if ( equls(result[i], tmp) )
                        return ;
            result.push_back(tmp);
            return ;
        }
        dfs(tmp, x + 1, nums);
        tmp.push_back(nums[x]);
        dfs(tmp, x + 1, nums);
    }
    vector > subsetsWithDup(vector<int> &nums){
        sort(nums.begin(), nums.end());
    	vector tmp;
    	dfs(tmp, 0 , nums) ;
    	// write your code here
    	return result;
    }
};

