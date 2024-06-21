public class UniformRandom {
    public static void main(String[] args) {
        double a = Math.random();
        double b = Math.random();
        double max = Math.max(a, b);
        double min = Math.min(a, b);
        System.out.println(a);
        System.out.println(b);
        double c = Math.random();
        max = Math.max(max, c);
        min = Math.min(min, c);
        System.out.println(c);
        double d = Math.random();
        max = Math.max(max, d);
        min = Math.min(min, d);
        System.out.println(d);
        double e = Math.random();
        max = Math.max(max, e);
        min = Math.min(min, e);
        System.out.println(e);
        double avg = (a + b + c + d + e) / 5.0;
        System.out.println("Max: " + max);
        System.out.println("Min: " + min);
        System.out.println("Average: " + avg);  
    }
}
