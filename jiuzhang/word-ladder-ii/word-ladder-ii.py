"""
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
"""

class Solution(object):
    # @param start, a string
    # @param end, a string
    # @param dict, a set of string
    # @return a list of lists of string
    def findLadders(self, start, end, dict):
        # Write your code here
        dict.add(start)
        dict.add(end)

        def buildPath(path,word):
            if len(preMap[word]) == 0:
                result.append([word] + path)
                return
            path.insert(0,word)
            for w in preMap[word]:
                buildPath(path,w)
            path.pop(0)

        length = len(start)
        preMap = {}
        for word in dict:
            preMap[word] = []
        result = []
        cur_level = set()
        cur_level.add(start)

        while True:
            pre_level = cur_level
            cur_level = set()
            for word in pre_level:
                dict.remove(word)
            for word in pre_level:
                for i in range(length):
                    left = word[:i]
                    right = word[i+1:]
                    for c in "abcdefghijklmnopqrstuvwxyz":
                        if c != word[i]:
                            nextWord = left + c + right
                            if nextWord in dict:
                                preMap[nextWord].append(word)
                                cur_level.add(nextWord)
            if len(cur_level) == 0:
                return []
            if end in cur_level:
                break
        buildPath([],end)
        return result
