"""
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
"""

class Solution:    
    """
    @param candidates: Given the candidate numbers
    @param target: Given the target number
    @return: All the combinations that sum to target
    """
    def combinationSum2(self, candidates, target): 
        # write your code here
        candidates.sort()        
        self.ans, tmp, use = [], [], [0] * len(candidates)        
        self.dfs(candidates, target, 0, 0, tmp, use)        
        return self.ans    
    def dfs(self, can, target, p, now, tmp, use):        
        if now == target:            
            self.ans.append(tmp[:])            
            return        
        for i in range(p, len(can)):            
            if now + can[i] <= target and (i == 0 or can[i] != can[i-1] or use[i-1] == 1):                
                tmp.append(can[i])
                use[i] = 1                
                self.dfs(can, target, i+1, now + can[i], tmp, use)                
                tmp.pop()                
                use[i] = 0

