public class RightTriangle {
    public static void main(String[] args) {
        int a = Integer.parseInt(args[0]);
        int b = Integer.parseInt(args[1]);
        int c = Integer.parseInt(args[2]);
        boolean positive = a > 0 && b > 0 && c > 0;
        boolean ABC = (Math.pow(a, 2) + Math.pow(b, 2)) == Math.pow(c, 2);
        boolean ACB = (Math.pow(a, 2) + Math.pow(c, 2)) == Math.pow(b, 2);
        boolean BCA = (Math.pow(b, 2) + Math.pow(c, 2)) == Math.pow(a, 2);
        boolean rightTriangle = (ABC || ACB || BCA) && positive;
        System.out.println(rightTriangle);
    }
}
