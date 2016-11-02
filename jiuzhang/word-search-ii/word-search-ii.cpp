/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

struct Node {
    Node * ch[26];
    string str;
    Node() {
        for (int i = 0; i < 26; ++i)
            ch[i] = NULL;
            str = "";
    }
};

class Solution {
public:
    vector results;
    Node * root;
    void insert(Node* p, string s) {
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            if (p->ch[s[i]-"a"] == NULL)
                p->ch[s[i]-"a"] = new Node();
            p = p->ch[s[i]-"a"];
        }   
        p->str = s;
    }
    void search(vector > &board, vector<vector<bool> > &mask, Node* p, int x, int y) {
        if (p->str != "") {
            results.push_back(p->str);
            p->str = "";
        }

        mask[x][y] = false;
        if (y + 1 ch[board[x][y+1]-"a"] != NULL) {
           search(board,mask, p->ch[board[x][y+1]-"a"], x, y+1);
        }

        if (x + 1 ch[board[x+1][y]-"a"] != NULL) {
           search(board,mask, p->ch[board[x+1][y]-"a"], x+1, y);
        }

        if (y - 1 >= 0 && mask[x][y-1] && p->ch[board[x][y-1]-"a"] != NULL) {
           search(board,mask, p->ch[board[x][y-1]-"a"], x, y-1);
        }

        if (x - 1 >= 0 && mask[x-1][y] && p->ch[board[x-1][y]-"a"] != NULL) {
           search(board,mask, p->ch[board[x-1][y]-"a"], x-1, y);
        }
        mask[x][y] = true;
    }
    /**
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
    vector wordSearchII(vector<vector<char> > &board, vector<string> &words) {
        // write your code here
        root = new Node();
        int len = words.size();
        for (int i = 0; i < len; ++i) { 
            insert(root, words[i]);
        }
        vector > mask(board.size(), vector<bool>(board[0].size(), true));
        if (board.size() < 1) return results;
        for (int i = 0; i <board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
               if (root->ch[board[i][j]-"a"] != NULL) {
                    search(board, mask, root->ch[board[i][j]-"a"], i, j);
                }
            }
        }
        return results;
    }
};
