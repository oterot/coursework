// print the absolute value of a number

public class AbsoluteValue {
    public static void main(String[] args) {
        int x = Integer.parseInt(args[0]);
        if (x < 0) x = -x;
        System.out.println(x);
    }
}
