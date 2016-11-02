/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班，
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

public class Solution {
    public void addArc(Map> graph, String vexStart, String vexEnd, double value) {
        Map arcMap;
        if (graph.containsKey(vexStart)) {
            arcMap = graph.get(vexStart);
        } else {
            arcMap = new HashMap();
        }
        arcMap.put(vexEnd, value);
        graph.put(vexStart, arcMap);
    }

    public double getValue(Map> graph, String vexStart, String vexEnd) {
        if (graph.get(vexStart) == null || graph.get(vexEnd) == null) {
            return -1;
        }

        Queue queue = new LinkedList<>();   //queue uesd for bfs
        Map value = new HashMap<>();    //distance from vexStart
        Set validation = new HashSet<>();   //check if the vertex has been in the queue

        //init
        queue.add(vexStart);
        validation.add(vexStart);
        value.put(vexStart, 1d);

        String currentNode, nextNode;
        while (!queue.isEmpty()) {
            currentNode = queue.remove();
            for (Map.Entry arc : graph.get(currentNode).entrySet()) {
                nextNode = arc.getKey();
                value.put(nextNode, value.get(currentNode) * arc.getValue());
                if (nextNode.equals(vexEnd)) {
                    return value.get(vexEnd);
                } else if (!validation.contains(nextNode)) {
                    queue.add(nextNode);
                    validation.add(nextNode);
                }
            }
        }
        return -1;
    }

    public double[] calcEquation(String[][] equations, double[] values, String[][] queries) {

        Map> graph = new HashMap<>();

        for (int i = 0; i < equations.length; i++) {
            //add arcs for both directions
            addArc(graph, equations[i][0], equations[i][1], values[i]);
            addArc(graph, equations[i][1], equations[i][0], 1 / values[i]);
        }

        double[] answer = new double[queries.length];
        for (int i = 0; i < answer.length; i++) {
            answer[i] = getValue(graph, queries[i][0], queries[i][1]);
        }

        return answer;
    }
}
