/* approximates the square root function using Newton-Raphson method
   https://en.wikipedia.org/wiki/Newton%27s_method
 */

public class Sqrt {
    public static void main(String[] args) {
        double EPS = Math.ulp(15.0); // error tolerance (15 places)
        double c = Double.parseDouble(args[0]);
        double t = c;
        while (Math.abs(t - c / t) > t * EPS)
            t = (c / t + t) / 2.0;
        System.out.println(t);
    }
}
