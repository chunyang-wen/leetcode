"""
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
"""

class Solution(object):
    """ 
    O(nm)
    n, m, k = len(s), len(words[0]), len(words)
    暴力做法，枚举开始位置，判断之后长度m*k的子串是否由给定字符串集合组成，最坏复杂度为O(nmk)。
    对于长度为m的字符串，0与m位置开始的区别，只在于少了s[0:m]，多了s[m*k+1:(m+1)*k]，所以产生了许多
    冗余操作。我们根据开始位置0~m-1分类，扫描字符串s，使用一个滑动窗口记录当前匹配了那些字符串，当下一个
    字符串不在words中，清空窗口(任意包含该串的均不合法)，如果记录的出现次数超过了words中数量，表示需要滑动窗口，
    窗口中单词数量等于k时，更新答案。
    """
    def findSubstring(self, s, words):
        hash = {}
        res = []
        wsize = len(words[0])
        
        for str in words:
            if str in hash:
                hash[str] += 1
            else:
                hash[str] = 1
        for start in range(0, len(words[0])):
            slidingWindow = {}
            wCount = 0
            for i in range(start, len(s), wsize):
                word = s[i : i + wsize]
                if word in hash:
                    if word in slidingWindow:
                        slidingWindow[word] += 1
                    else:
                        slidingWindow[word] = 1
                    wCount += 1
                    while hash[word] < slidingWindow[word]:
                        pos = i - wsize * (wCount - 1)
                        removeWord = s[pos : pos + wsize]
                        print i, removeWord
                        slidingWindow[removeWord] -= 1
                        wCount -= 1
                else:
                    slidingWindow.clear()
                    wCount = 0
                if wCount == len(words):
                    res.append(i - wsize * (wCount - 1))
                    
        return res
