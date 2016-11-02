/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班，
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

public class Solution {
    public class SuperNode {
        int ans;
        int small, large;
        boolean isBST;
        public SuperNode() {
            ans = 0;
            isBST = true;
            small = Integer.MAX_VALUE;
            large = -Integer.MAX_VALUE;
        }
    }
    public int largestBSTSubtree(TreeNode root) {
        return dfs(root).ans;
    }
    public SuperNode dfs(TreeNode node) {
        if (node == null) {
            return new SuperNode();
        }
        SuperNode now = new SuperNode();
        SuperNode left = dfs(node.left);
        SuperNode right = dfs(node.right);
        if (left.small < node.val) {
            now.small = left.small;
        } else {
            now.small = node.val;
        }
        now.large = Math.max(right.large,node.val);
        if (left.isBST && right.isBST && left.large = node.val) {
            now.ans = left.ans + right.ans +1;
            now.isBST = true;
        } else {
            now.ans=Math.max(left.ans,right.ans);
            now.isBST = false;
        }
        return now;
    }
}
