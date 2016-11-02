/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

// version 1: (Recommend)
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        int size = getListSize(head);
        return convertHelper(head, size);
    }
    
    int getListSize(ListNode *head) {
        int size = 0;
        while (head != NULL) {
            head = head->next;
            size++;
        }
        return size;
    }
    
    TreeNode *convertHelper(ListNode *&head, int size) {
        if (size == 0) {
            return NULL;
        }
        
        TreeNode *root = new TreeNode(0);
        root->left = convertHelper(head, size / 2);
        root->val = head->val; head = head->next;
        root->right = convertHelper(head, size - size / 2 - 1);
        return root;
    }
};

// version 2:
struct ResultType {
    TreeNode *tree;
    ListNode *next;
};

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        
        int size = getListSize(head);
        ResultType result = convertHelper(head, size);
        return result.tree;
    }
    
    int getListSize(ListNode *head) {
        int size = 0;
        while (head != NULL) {
            head = head->next;
            size++;
        }
        return size;
    }
    
    ResultType convertHelper(ListNode *head, int size) {
        ResultType result;
        
        if (size == 1) {
            result.tree = new TreeNode(head->val);
            result.next = head->next;
            return result;
        }
        
        ResultType left = convertHelper(head, size / 2);
        result.tree = new TreeNode(left.next->val);
        result.tree->left = left.tree;
        if (left.next->next == NULL || size - size / 2 - 1 == 0) {
            result.tree->right = NULL;
            result.next = left.next->next;
            return result;
        }
        ResultType right = convertHelper(left.next->next, size - size / 2 - 1);
        result.tree->right = right.tree;
        result.next = right.next;
        return result;
    }
};

