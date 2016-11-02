/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班，
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

public class Solution {
    public String addBinary(String a, String b) {
        if(a.length() < b.length()){
            String tmp = a;
            a = b;
            b = tmp;
        }
        
        int pa = a.length()-1;
        int pb = b.length()-1;
        int carries = 0;
        String rst = "";
        
        while(pb >= 0){
            int sum = (int)(a.charAt(pa) - "0") + (int)(b.charAt(pb) - "0") + carries;
            rst = String.valueOf(sum % 2) + rst;
            carries = sum / 2;
            pa --;
            pb --;
        }
        
        while(pa >= 0){
            int sum = (int)(a.charAt(pa) - "0") + carries;
            rst = String.valueOf(sum % 2) + rst;
            carries = sum / 2;
            pa --;
        }       
        
        if (carries == 1)
            rst = "1" + rst;
        return rst;
    }
}


