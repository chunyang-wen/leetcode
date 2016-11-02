"""
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
"""

class Solution:
    def _format(self, line, maxWidth):
        if len(line) == 1:
            return line[0] + " " * (maxWidth - len(line[0]))
        length = sum([len(w) for w in line])
        s, gaps = line[0], len(line) - 1
        for index, w in enumerate(line[1:]):
            if index < (maxWidth - length) % gaps:
                s = s + " " + " " * ((maxWidth - length) / gaps) + w
            else:
                s = s + " " * ((maxWidth - length) / gaps) + w
        return s
        
    def _formatLast(self, line, maxWidth):
        s = " ".join(line)
        return s + " " * (maxWidth - len(s))
    
    # @param {string[]} words
    # @param {integer} maxWidth
    # @return {string[]}
    def fullJustify(self, words, maxWidth):
        line, length = [], 0
        results = []
        for w in words:
            if length + len(w) + len(line) <= maxWidth:
                length += len(w)
                line.append(w)
            else:
                results.append(self._format(line, maxWidth))
                length = len(w)
                line = [w]
        if len(line):
            results.append(self._formatLast(line, maxWidth))
        return results
        
