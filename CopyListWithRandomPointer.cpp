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
    RandomListNode *copyRandomList(RandomListNode *head) {
        // add aditional next pointer
        if (!head)
            return head;
        RandomListNode *start = head;
        RandomListNode *node;
        while(start) {
            node = start->next;
            start->next = new RandomListNode(start->label);
            start->next->random = start->random;
            start->next->next = node;
            start = node;
        }
        
        start = head;
        while(start) {
            start = start->next;
            if (start->random)
                start->random = start->random->next;
            start = start->next;
        }
        
        // break the list
        RandomListNode *head1 = head->next;
        RandomListNode *start1 = head1;
        start = head;
        while (start) {
            node = start1->next;
            start->next = node;
            start = start->next;
            if (!node)
                break;
            start1->next = node->next;
            start1 = start1->next;
        }
        
        return head1;
        
    }
};