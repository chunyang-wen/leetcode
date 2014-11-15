/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        
        return sortedArrayToBSTHelper(num,0,num.size());
    }
private:
    TreeNode * sortedArrayToBSTHelper(vector<int> &num, int low, int high) {
        if (low >= high)
            return NULL;
        int mid = (high-low)/2 + low;
        TreeNode * cur = new TreeNode(num[mid]);
        cur->left = sortedArrayToBSTHelper(num,low, mid);
        cur->right = sortedArrayToBSTHelper(num,mid+1,high);
        return cur;
    }
};