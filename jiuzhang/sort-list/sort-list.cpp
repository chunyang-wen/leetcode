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
     * @param head: The first node of linked list.
     * @return: You should return the head of the sorted linked list,
                    using constant space complexity.
     */
    ListNode *sortList(ListNode *head) {
        // write your code here
        if(head == NULL) return head;
        if(head -> next == NULL){
            return head;
        }
        
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast -> next != NULL && fast -> next -> next != NULL){
            fast = fast -> next;
            fast = fast -> next;
            slow = slow -> next;
        }
        
        ListNode* mid = slow -> next;
        slow -> next = NULL;
        
        ListNode* list1 = sortList(head);
        ListNode* list2 = sortList(mid);
        
        ListNode* sorted = merge(list1 , list2);
        return sorted;
    }
    ListNode* merge(ListNode* list1 , ListNode* list2){
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        
        ListNode* head;
        ListNode* tmp;
        
        if(list1 -> val  val){
            head = list1;
            list1 = list1 -> next;
        }else{
            head = list2;
            list2 = list2 -> next;
        }
        tmp = head;
        
        while(list1 != NULL && list2 != NULL){
            if(list1 -> val  val){
                tmp -> next = list1;
                tmp = list1;
                list1 = list1 -> next;
            }else{
                tmp -> next = list2;
                tmp = list2;
                list2 = list2 -> next;
            }
        }
        if(list1 != NULL) tmp -> next = list1;
        if(list2 != NULL) tmp -> next = list2;
        
        return head;
    }
};




