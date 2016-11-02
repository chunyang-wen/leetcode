/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班，
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

public class SnakeGame {
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    private class Position {
        public int x, y;
        public Position(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    private boolean gameOver;
    private int[][] food;
    private int foodGet;
    private int width, height;
    private HashSet usedMap;
    private Deque queue;
    public SnakeGame(int width, int height, int[][] food) {
        this.width = width;
        this.height = height;
        gameOver = false;
        foodGet = 0;
        usedMap = new HashSet();
        this.food = food;
        queue = new LinkedList();
        usedMap.add(0);
        queue.offer(new Position(0, 0));
        if (food.length > 0 && food[foodGet][0] == 0 && food[foodGet][1] == 0) {
            foodGet++;
        }
    }
    
    /** Moves the snake.
        @param direction - "U" = Up, "L" = Left, "R" = Right, "D" = Down 
        @return The game"s score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    public int move(String direction) {
        if (gameOver) {
            return -1;
        }
        int incx = 0, incy = 0;
        switch (direction) {
            case "U": incx = -1; incy = 0; break;
            case "L": incx = 0; incy = -1; break;
            case "R": incx = 0; incy = 1; break;
            case "D": incx = 1; incy = 0; break;
            default: break;
        }
        int x = queue.peekLast().x + incx, y = queue.peekLast().y + incy;
        if (x >= 0 && x = 0 && y < width) {
            queue.offerLast(new Position(x, y));
            if (foodGet < food.length && x == food[foodGet][0] && y == food[foodGet][1]) {
                foodGet++;
            } else {
                usedMap.remove(queue.peekFirst().x * width + queue.peekFirst().y);
                queue.pollFirst();
            }
            if (usedMap.contains(x * width + y)) {
                return -1;
            } else {
                usedMap.add(x * width + y);
            }
            return foodGet;
        } else {
            gameOver = true;
            return -1;
        }
    }
}
