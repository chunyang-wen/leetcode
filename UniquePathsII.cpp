// http://www.cnblogs.com/TenosDoIt/p/3704091.html
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int>dp(n+1, 0);
        dp[1] = (obstacleGrid[0][0] == 0) ? 1 : 0;
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                if(obstacleGrid[i-1][j-1] == 0)
                    dp[j] = dp[j] + dp[j-1];
                else dp[j] = 0;
        return dp[n];
    }
};