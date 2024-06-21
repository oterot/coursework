/* Outputs the given integers in ascending order making use of
   only the min and max functions.
 */

public class ThreeSort {
    public static void main(String[] args) {
        // 3 integers are passed in via the command-line
        int a = Integer.parseInt(args[0]);
        int b = Integer.parseInt(args[1]);
        int c = Integer.parseInt(args[2]);

        /* The idea here is that by comparing the max values of
           each pair, we eliminate the original minimum value.
         */
        int x = Math.max(a, b);
        int y = Math.max(a, c);
        int z = Math.max(b, c);

        /* The maximum of the remaining values will be the maximum of
           the original values.
         */
        int max = Math.max(x, y);
        max = Math.max(max, z);

        /* The minimum of the remaining values will be the median of the
           original values.
         */
        int mid = Math.min(x, y);
        mid = Math.min(mid, z);

        // Now go back and get the minimum of the original values
        int min = Math.min(a, b);
        min = Math.min(min, c);

        // Output the sequence in ascending order
        String outPut = min + " " + mid + " " + max;
        System.out.println(outPut);
    }
}
