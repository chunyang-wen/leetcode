class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        
        return isValidRow(board) && isValidColumn(board) && isValidRectangle(board);
        
    }
    
private:
    bool isValidRow(vector<vector<char> > &board) {
        int N = board.size(); // N*N
        
        for (int i = 0; i < N; ++i) {
            vector<char> test(N+1, 0);
            for (int j = 0; j < N; ++j) {
                if (board[i][j] != '.') {
                    if (test[board[i][j]-'0'] != 0)
                        return false;
                    test[board[i][j]-'0'] = 1;
                }
            }
        }
        return true;
    }
    
    bool isValidColumn(vector<vector<char> > &board) {
        int N = board.size(); // N*N
        
        for (int i = 0; i < N; ++i) {
            vector<char> test(N+1, 0);
            for (int j = 0; j < N; ++j) {
                if (board[j][i] != '.') {
                    if (test[board[j][i]-'0'] != 0)
                        return false;
                    test[board[j][i]-'0'] = 1;
                }
            }
        }
        return true;
    }
    
    bool isValidRectangle(vector<vector<char> > &board) {
        
        int N = board.size();
        int gap = (int)(sqrt(N));
        
        for (int i = 0; i < N; i+= gap) {
            for (int j = 0; j < N; j += gap) {
                vector<char> test(N+1,0);
                for (int m = i; m < i + gap; ++m) {
                    for (int n = j; n < j + gap; ++n ) {
                        if (board[m][n] != '.') {
                            if (test[board[m][n]-'0'] != 0)
                                return false;
                            test[board[m][n]-'0'] = 1;
                        }
                    }
                }
            }
        }
        
        return true;
        
        
    }
};