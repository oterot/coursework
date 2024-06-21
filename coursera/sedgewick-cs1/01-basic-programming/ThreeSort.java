public class ThreeSort {
    public static void main(String[] args) {  
        int a = Integer.parseInt(args[0]);
        int b = Integer.parseInt(args[1]);
        int c = Integer.parseInt(args[2]);
        int x = Math.max(a, b);
        int y = Math.max(a, c);
        int z = Math.max(b, c);
        int max = Math.max(x, y);
        max = Math.max(max, z);
        int mid = Math.min(x, y);
        mid = Math.min(mid, z);
        int min = Math.min(a, b);
        min = Math.min(min, c);
        String outPut = min + " " + mid + " " + max;
        System.out.println(outPut);
    }
}
