/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // basic idea is to level traversal link each evel
        if (root)
        {
            vector<TreeLinkNode *> layerNodes;
            layerNodes.push_back(root);
            // record all his children
            vector<TreeLinkNode *> children;
            
            while (!layerNodes.empty()) {
                
                vector<TreeLinkNode *>::iterator iBeg = layerNodes.begin();
                vector<TreeLinkNode *>::iterator iEnd = layerNodes.end();
                while (iBeg != iEnd)
                {
                    if ((*iBeg)->left) {
                        children.push_back((*iBeg)->left);
                    }
                    if ((*iBeg)->right) {
                        children.push_back((*iBeg)->right);
                    }
                    ++iBeg;
                }
                
                // no more to handle
                if (children.empty())
                    return;
                
                // store layer
                layerNodes.clear();
                iBeg = children.begin();
                iEnd = children.end();
                vector<TreeLinkNode *>::iterator iNext = ++iBeg;
                --iBeg;
                while (iBeg != iEnd) {
                    if (iNext == iEnd)
                        break;
                    (*iBeg)->next = (*iNext);
                    iBeg = iNext;
                    ++iNext;
                }
                
                layerNodes.swap(children);

                
            }
        }
    }
};