/* Generate 5 uniform random numbers between 0 and 1
   Output their average, min, and max
   Required to only use random, max, and min, function from Math library
 */

public class UniformRandom {
    public static void main(String[] args) {
        // generate 5 pseudo-random numbers between 0 and 1
        double a = Math.random();
        double b = Math.random();
        double c = Math.random();
        double d = Math.random();
        double e = Math.random();

        //calculate the average
        double avg = (a + b + c + d + e) / 5.0;

        // compare and store them in max to keep track of the max and min
        double max = Math.max(a, b);
        double min = Math.min(a, b);
        max = Math.max(max, c);
        min = Math.min(min, c);
        max = Math.max(max, d);
        min = Math.min(min, d);

        // after final comparison we should be left with the max and min
        max = Math.max(max, e);
        min = Math.min(min, e);

        // output the variables
        System.out.println(a);
        System.out.println(b);
        System.out.println(c);
        System.out.println(d);
        System.out.println(e);

        // output the summary statistics
        System.out.println("Max: " + max);
        System.out.println("Min: " + min);
        System.out.println("Average: " + avg);
    }
}
