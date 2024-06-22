public class GeneralizedHarmonic {
    public static void main(String[] args) {
        int n = Integer.parseInt(args[0]);
        int r = Integer.parseInt(args[1]);
        double sum = 0.0;
        double p;

        for (int i = 1; i <= n; i++) {
            p = i;
            for (int j = 1; j < r; j++) {
                p *= i;
            }
            sum += (1 / p);
        }
        System.out.println(sum);
    }
}
