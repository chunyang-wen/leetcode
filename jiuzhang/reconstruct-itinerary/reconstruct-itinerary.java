/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班，
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

public class Solution {
    public List findItinerary(String[][] tickets) {
        Map> hashmap = new HashMap<String, PriorityQueue<String>>();
        List list = new ArrayList<String>();
        String cur = "JFK";
        int length = tickets.length;
        for (int i = 0; i < length; i++) {
            if (!hashmap.containsKey(tickets[i][0])) {
                hashmap.put(tickets[i][0], new PriorityQueue());
            }
            hashmap.get(tickets[i][0]).add(tickets[i][1]);
        }
        dfs(cur, hashmap, list);
        Collections.reverse(list);
        return list;
    }
    public void dfs(String cur, Map> hashmap, List<String> list) {
        while (hashmap.containsKey(cur) && !hashmap.get(cur).isEmpty()) {
            dfs(hashmap.get(cur).poll(), hashmap, list);
        }
        list.add(cur);
    }
}

