/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */ 
    int uniquePathsWithObstacles(vector > &obstacleGrid) {
        // write your code here
        int m = obstacleGrid.size();
        if(m<=0){
            return 0;
        }
        int n = obstacleGrid[0].size();
        if(n<=0){
            return 0;
        }
        if(obstacleGrid[0][0]==1){
            return 0;
        }
        
        int map[101][101];
        map[0][0]=1;
        for(int i=1;i<m;i++){
            if(obstacleGrid[i][0]==1)
                map[i][0]=0;
            else
                map[i][0]=map[i-1][0];
        } 
        for(int i=1;i<n;i++){
             if(obstacleGrid[0][i]==1)
                map[0][i]=0;
            else
                map[0][i]=map[0][i-1];
        } 
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==1){
                    map[i][j]=0;
                }
                else
                    map[i][j]=map[i-1][j]+map[i][j-1];
            }
            
        return map[m-1][n-1];
    }
};

