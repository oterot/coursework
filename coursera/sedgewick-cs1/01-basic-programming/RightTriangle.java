/*  Tests to see if the 3 given lengths can constitute the 3 sides
    of a right triangle.
 */

public class RightTriangle {
    public static void main(String[] args) {
        // 3 side lengths are passed in as command-line arguments
        int a = Integer.parseInt(args[0]);
        int b = Integer.parseInt(args[1]);
        int c = Integer.parseInt(args[2]);

        // Check to see if all sides are positive
        boolean positive = a > 0 && b > 0 && c > 0;

        /* Check to see if the sum of any pair of sides squared is
           equal to the other side squared
         */
        boolean ABC = (Math.pow(a, 2) + Math.pow(b, 2)) == Math.pow(c, 2);
        boolean ACB = (Math.pow(a, 2) + Math.pow(c, 2)) == Math.pow(b, 2);
        boolean BCA = (Math.pow(b, 2) + Math.pow(c, 2)) == Math.pow(a, 2);
        boolean rightTriangle = (ABC || ACB || BCA) && positive;

        // True if the sides given constitute a right triangle
        System.out.println(rightTriangle);
    }
}
