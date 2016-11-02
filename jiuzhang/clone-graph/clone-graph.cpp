/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *clone(UndirectedGraphNode *node, map &table)
    {
        if(node==NULL)
            return NULL;
            
        if(table.find(node->label)!=table.end())
            return table[node->label];
        
        UndirectedGraphNode *newnode=new UndirectedGraphNode(node->label);
        table[newnode->label]=newnode;

        for(int i=0;ineighbors.size();i++)
        {
            UndirectedGraphNode *neighbor=clone(node->neighbors[i],table);
            newnode->neighbors.push_back(neighbor);
        }
        
        return newnode;
    }
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        map visitTable;
        return clone(node,visitTable);
    }
};

