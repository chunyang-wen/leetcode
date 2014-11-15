// http://www.cnblogs.com/lichen782/p/leetcode_Largest_Rectangle_in_Histogram.html
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        height.push_back(0);//数组末尾插入dummy元素0
        int len = height.size(),res = 0;
        stack<int> S;//注意栈内保存的是数组height的下标索引
        for (int i = 0; i < len; i++) 
        {
             if (S.empty() || height[i] > height[S.top()]) S.push(i);
             else
             {
                 int tmp = S.top();
                 S.pop();
                 res = max(res, height[tmp] * (S.empty() ? i : i-S.top()-1));
                 i--;
             }
        }
        height.pop_back();//删除dummy
        return res;
    }
};