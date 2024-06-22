/* Simulates a random walk until distance r reached when randomly
   moving either N, W, E, S from a center point.  Repeats for given
   number of trials and outputs the average number of steps taken.
   https://en.wikipedia.org/wiki/Monte_Carlo_method
   https://en.wikipedia.org/wiki/Random_walk
   https://en.wikipedia.org/wiki/Brownian_motion
 */

public class RandomWalkers {
    public static void main(String[] args) {
        int r = Integer.parseInt(args[0]);
        int trials = Integer.parseInt(args[1]);
        int i, j, steps;
        long totalSteps = 0;
        int direction;

        for (int n = 0; n < trials; n++) {
            steps = 0;
            i = 0;
            j = 0;
            while (Math.abs(i) + Math.abs(j) != r) {
                direction = (int) (Math.random() * 4);
                if (direction < 1) i += 1;
                else if (direction < 2) i -= 1;
                else if (direction < 3) j += 1;
                else j -= 1;
                steps += 1;
            }
            totalSteps += steps;
        }
        System.out.println("average number of steps = "
                + totalSteps / (double) trials);
    }
}
