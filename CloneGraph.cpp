/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // we use a map record the address of each label
        // unordered_map<int, UndirectedGraphNode>
        unordered_map<int, UndirectedGraphNode*> graphMap;
        return cloneGraphHelper(node,graphMap);
    }
private:
    UndirectedGraphNode* cloneGraphHelper(UndirectedGraphNode *node, unordered_map<int, UndirectedGraphNode*> &graphMap) {
        if (!node)
            return node;
        UndirectedGraphNode *nodeCopy;
        if (!graphMap.count(node->label)) {
            // we do not have the node
            nodeCopy = new UndirectedGraphNode(node->label);
            graphMap[node->label] = nodeCopy;
        }
        else {
            return graphMap[node->label];
        }
        
        vector<UndirectedGraphNode *> neighbors = node->neighbors;
        UndirectedGraphNode * neighbor;
        
        int len = neighbors.size();
        for (int i = 0; i < len; ++i) {
            nodeCopy->neighbors.push_back(cloneGraphHelper(neighbors[i],graphMap));
        }
        
        return nodeCopy;
    }
};