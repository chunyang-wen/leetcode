"""
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
"""

class Solution:
    # @param {integer} num
    # @return {string}
    def parse(self, digit, index):
        NUMS = {
            1: "I",
            2: "II",
            3: "III",
            4: "IV",
            5: "V",
            6: "VI",
            7: "VII",
            8: "VIII",
            9: "IX",
        }
        ROMAN = {
            "I": ["I", "X", "C", "M"],
            "V": ["V", "L", "D", "?"],
            "X": ["X", "C", "M", "?"]
        }
        
        s = NUMS[digit]
        return s.replace("X", ROMAN["X"][index]).replace("I", ROMAN["I"][index]).replace("V", ROMAN["V"][index])
        
    def intToRoman(self, num):
        s = ""
        index = 0
        while num != 0:
            digit = num % 10
            if digit != 0:
                s = self.parse(digit, index) + s
            num = num / 10
            index += 1
        return s
            
            
