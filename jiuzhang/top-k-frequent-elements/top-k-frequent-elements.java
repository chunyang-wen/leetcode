/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班，
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

public class Solution {
    public List topKFrequent(int[] nums, int k) {
        Map hashmap = new HashMap<Integer, Integer>();
        PriorityQueue> queue = new PriorityQueue<Map.Entry<Integer, Integer>>(
            new Comparator>() {
                public int compare(Map.Entry e1, Map.Entry<Integer, Integer> e2) {
                    return e1.getValue() - e2.getValue();
                }
            });
        for (int i = 0; i < nums.length; i++) {
            if (!hashmap.containsKey(nums[i])) {
                hashmap.put(nums[i], 1);
            } else {
                hashmap.put(nums[i], hashmap.get(nums[i]) + 1);
            }
        }
        
        for (Map.Entry entry : hashmap.entrySet()) {
            if (queue.size() < k) {
                queue.offer(entry);
            } else if (queue.peek().getValue() < entry.getValue()) {
                queue.poll();
                queue.offer(entry);
            }
        }
        
        List ans = new ArrayList<Integer>();
        for (Map.Entry entry : queue)
            ans.add(entry.getKey());
        return ans;
    }
}
