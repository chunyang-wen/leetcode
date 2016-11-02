/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector &lists) {
        // write your code here
        ListNode* tmp_node = NULL;
        ListNode* tar_node = NULL;
        ListNode* new_node = NULL;
        ListNode* result = NULL;
        for (int i = 0; i < lists.size(); ++i) {
            tmp_node = lists[i];
            if (NULL == tmp_node) {
                continue;
            }
            if (NULL == result) {
                result = new ListNode(tmp_node->val);
                tmp_node = tmp_node->next;
            } else {
                if (result->val > tmp_node->val) {
                    new_node = new ListNode(tmp_node->val);
                    new_node->next = result;
                    result = new_node;
                    tmp_node = tmp_node->next;
                }
            }
            tar_node = result;
            while (tmp_node != NULL) {
                while (NULL != tar_node->next && tar_node->next->val val) {
                    tar_node = tar_node->next;
                }
                if (NULL == tar_node->next) {
                    new_node = new ListNode(tmp_node->val);
                    tar_node->next = new_node;
                } else {
                    new_node = new ListNode(tmp_node->val);
                    new_node->next = tar_node->next;
                    tar_node->next = new_node;
                }
                tmp_node = tmp_node->next;
            }
        }
        return result;
    }
};




