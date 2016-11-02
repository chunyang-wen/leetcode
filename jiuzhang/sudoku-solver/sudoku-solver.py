"""
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
"""

# Actually this is a very optimized algorithm
# Every time put a number in a grid, this algorithm always choose the grid which has the least choices
# Also, use bit_flags to make the algorithm more faster than dictionary

class BitFlag:
    def __init__(self):
        self.bit_flags = 0
        
    def set_bit(self, bit, val):
        self.bit_flags |= (1 << bit)
        if not val:
            self.bit_flags ^= (1 << bit)

    def get_bit(self, bit):
        return ( self.bit_flags & (1 << bit) )!= 0


class Solution:
    # @param {character[][]} board
    # @return {void} Do not return anything, modify board in-place instead.
    def solveSudoku(self, board):
        self.rows = [BitFlag() for i in range(9)]
        self.cols = [BitFlag() for i in range(9)]
        self.grid = [BitFlag() for i in range(9)]
        
        emptys = 0
        for x in range(9):
            for y in range(9):
                if board[x][y] == ".":
                    emptys += 1
                    continue
                self.setChar(board, x, y, ord(board[x][y]) - ord("1"))
        self.found = False
        self.dfs(board, emptys)
        
    def setChar(self, board, x, y, bit):
        c = chr(bit + ord("1"))
        board[x][y] = c
        z = x / 3 * 3 + y / 3
        self.rows[x].set_bit(bit, True)
        self.cols[y].set_bit(bit, True)
        self.grid[z].set_bit(bit, True)
    
    def setEmpty(self, board, x, y):
        z = x / 3 * 3 + y / 3
        bit = ord(board[x][y]) - ord("1")
        board[x][y] = "."
        self.rows[x].set_bit(bit, False)
        self.cols[y].set_bit(bit, False)
        self.grid[z].set_bit(bit, False)
        
    def dfs(self, board, emptys):
        if emptys == 0:
            self.found = True
            return
        
        eligible = []
        for x in range(9):
            for y in range(9):
                if board[x][y] != ".":
                    continue
                z = x / 3 * 3 + y / 3
                bits = [bit for bit in range(9)
                        if not any([self.rows[x].get_bit(bit),
                                    self.cols[y].get_bit(bit),
                                    self.grid[z].get_bit(bit)])]
                if len(bits) == 0:
                    return
                eligible.append((x, y, bits))

        if len(eligible) == 0:
            return
        
        eligible = sorted(eligible, key=lambda x: len(x[2]))
        x, y, bits = eligible[0]
        for bit in bits:
            self.setChar(board, x, y, bit)
            self.dfs(board, emptys - 1)
            if self.found:
                return
            self.setEmpty(board, x, y)
