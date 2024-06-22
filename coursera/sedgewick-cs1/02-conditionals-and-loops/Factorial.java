// example of for loop, used to calculate factorial product
public class Factorial {
    public static void main(String[] args) {
        int N = Integer.parseInt(args[0]);
        long product = 1;
        for (int i = 1; i <= N; i++)
            product *= i;
        System.out.println(product);
    }
}
