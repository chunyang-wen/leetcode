/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        unordered_map old2new;
        RandomListNode* dummy = new RandomListNode(-1);
        RandomListNode* tmp = head;
        RandomListNode* curr = dummy;
        while (tmp) {
            RandomListNode* newNode = new RandomListNode(tmp->label);
            old2new[tmp] = newNode;
            curr->next = newNode;
            curr = curr -> next;
            tmp = tmp->next;
        }
        tmp = head;
        while (tmp) {
            if (tmp->random) {
                old2new[tmp]->random = old2new[tmp->random];
            }
            tmp = tmp-> next;
        }
        return dummy->next;
    }
};

