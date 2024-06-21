public class GreatCircle {
    public static void main(String[] args) {
        double x1 = Math.toRadians(Double.parseDouble(args[0]));
        double y1 = Math.toRadians(Double.parseDouble(args[1]));
        double x2 = Math.toRadians(Double.parseDouble(args[2]));
        double y2 = Math.toRadians(Double.parseDouble(args[3]));
        double dx = (x2 - x1) / 2.0;
        double dy = (y2 - y1) / 2.0;
        double sindx = Math.pow(Math.sin(dx), 2);
        double sindy = Math.pow(Math.sin(dy), 2);
        double determinant = sindx + Math.cos(x1) * Math.cos(x2) * sindy;
        double r = 6371.0; // mean radius to the Earth in km
        double distance = 2 * r * Math.asin(Math.sqrt(determinant));
        System.out.println(distance + " kilometers");
    }
}
