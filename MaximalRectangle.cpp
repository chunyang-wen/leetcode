class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int row = matrix.size();
        if(row == 0)return 0;
        int column = matrix[0].size();
        int height[column+1], res = 0;
        memset(height, 0, sizeof(height));
        stack<int> S;
        for(int i = 0; i < row; i++)
        {
            stack<int>().swap(S);//清空栈
            bool flag = false;//防止同一height[j]被多次更新
            for(int j = 0; j <= column; j++)
            {
                if(j < column && flag == false)
                {//更新当前行第j列的height值
                    if(matrix[i][j] == '1')
                    {
                        if(i-1 >=0 && matrix[i-1][j] == '1')
                            height[j]++;
                        else height[j] = 1;
                    }
                    else height[j] = 0;
                }
                if (S.empty() || height[j] > height[S.top()])
                {
                    S.push(j);
                    flag = false;
                }
                else
                {
                     int tmp = S.top();
                     S.pop();
                     res = max(res, height[tmp] * (S.empty() ? j : j-S.top()-1));
                     j--; //保持此次循环中j不变
                     flag = true;//height[j]已经更新，无需再次更新
                }
            }
        }
        return res;
    }
};