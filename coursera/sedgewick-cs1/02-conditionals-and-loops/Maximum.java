// print the maximum of two numbers

public class Maximum {
    public static void main(String[] args) {
        int x = Integer.parseInt(args[0]);
        int y = Integer.parseInt(args[1]);
        int max;

        if (x > y) max = x;
        else max = y;
        System.out.println(max);

    }
}
