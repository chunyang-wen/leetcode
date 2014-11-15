class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
                if(board[i][j] != '.')
                    fill(i, j, board[i][j] - '0');
        solver(board, 0);
    }
     
    bool solver(vector<vector<char> > &board, int index)
    {// 0 <= index <= 80，index表示接下来要填充第index个格子
        if(index > 80)return true;
        int row = index / 9, col = index - 9*row;
        if(board[row][col] != '.')
            return solver(board, index+1);
        for(int val = '1'; val <= '9'; val++)//每个为填充的格子有9种可能的填充数字
        {
            if(isValid(row, col, val-'0'))
            {
                board[row][col] = val;
                fill(row, col, val-'0');
                if(solver(board, index+1))return true;
                clear(row, col, val-'0');
            }
        }
        board[row][col] = '.';//注意别忘了恢复board状态
        return false;
    }
     
    //判断在第row行col列填充数字val后，是否是合法的状态
    bool isValid(int row, int col, int val)
    {
        if(rowValid[row][val] == 0 &&
           columnValid[col][val] == 0 &&
           subBoardValid[row/3*3+col/3][val] == 0)
           return true;
        return false;
    }
     
    //更新填充状态
    void fill(int row, int col, int val)
    {
        rowValid[row][val] = 1;
        columnValid[col][val] = 1;
        subBoardValid[row/3*3+col/3][val] = 1;
    }
     
    //清除填充状态
    void clear(int row, int col, int val)
    {
        rowValid[row][val] = 0;
        columnValid[col][val] = 0;
        subBoardValid[row/3*3+col/3][val] = 0;
    }
private:
    int rowValid[9][10];//rowValid[i][j]表示第i行数字j是否已经使用
    int columnValid[9][10];//columnValid[i][j]表示第i列数字j是否已经使用
    int subBoardValid[9][10];//subBoardValid[i][j]表示第i个小格子内数字j是否已经使用
};