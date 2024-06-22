/* Simulate a random walk
   Outputs the number of steps taken to reach Manhattan distance r
   when taking random steps in N, W, E, S directions
   https://en.wikipedia.org/wiki/Random_walk
   https://en.wikipedia.org/wiki/Brownian_motion
 */

public class RandomWalker {
    public static void main(String[] args) {
        int r = Integer.parseInt(args[0]);
        int i = 0;
        int j = 0;
        int steps = 0;
        int direction;
        System.out.println("(" + i + ", " + j + ")");
        while (Math.abs(i) + Math.abs(j) != r) {
            direction = (int) (Math.random() * 4);
            if (direction < 1) i += 1;
            else if (direction < 2) i -= 1;
            else if (direction < 3) j += 1;
            else j -= 1;
            System.out.println("(" + i + ", " + j + ")");
            steps += 1;
        }
        System.out.println("steps = " + steps);
    }
}
