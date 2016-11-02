/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班，
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

public class Solution {
    public void solveSudoku(char[][] board){
        solve(board);
    }

    public boolean solve(char[][] board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++){
                if(board[i][j] != "."){
                    continue;
                }
                for(int k = 1; k <= 9; k++){
                    board[i][j] = (char) (k + "0");
                    if (isValid(board, i, j) && solve(board)){
                        return true;
                    }
                    board[i][j] = ".";
                }
                return false;
            }
        }
        return true;
    }
    
    
     public boolean isValid(char[][] board, int a, int b){
        Set contained = new HashSet<Character>();
        for(int j=0;j<9;j++){
            if(contained.contains(board[a][j])) return false;
            if(board[a][j]>"0" && board[a][j]<="9")
                contained.add(board[a][j]);
        }
            
        
    
        contained = new HashSet();
        for(int j=0;j<9;j++){
            if (contained.contains(board[j][b])) {
                return false;
            }
            if (board[j][b]>"0" && board[j][b]<="9") {
                contained.add(board[j][b]);
            }
        }
        
    
        contained = new HashSet();
        for (int m = 0; m < 3; m++) {
            for (int n = 0; n < 3; n++){
                int x = a / 3 * 3 + m, y = b / 3 * 3 + n;
                if (contained.contains(board[x][y])) {
                    return false;
                }
                if (board[x][y] > "0" && board[x][y] <= "9") {
                        contained.add(board[x][y]);
                }
            } 
        }
    
        return true;
    }
}


