/* Applies the haversine formula to calculate the great-circle distance
   between a set of given longitude and latitude coordinates.
   This represents the shortest distance between two points on the
   circular intersection of the sphere that contains them.
   reference: https://en.wikipedia.org/wiki/Haversine_formula
 */
public class GreatCircle {
    public static void main(String[] args) {
        // coordinates passed in through the command line
        double x1 = Math.toRadians(Double.parseDouble(args[0]));
        double y1 = Math.toRadians(Double.parseDouble(args[1]));
        double x2 = Math.toRadians(Double.parseDouble(args[2]));
        double y2 = Math.toRadians(Double.parseDouble(args[3]));

        // calculate haversine of the lat and long coordinates
        double havLat = Math.pow(Math.sin((x2 - x1) / 2.0), 2);
        double havLong = Math.pow(Math.sin((y2 - y1) / 2.0), 2);

        // form the determinant
        double radicand = havLat + Math.cos(x1) * Math.cos(x2) * havLong;
        double r = 6371.0; // mean radius to the Earth in km

        // calculate the distance using the haversine distance formula
        double distance = 2 * r * Math.asin(Math.sqrt(radicand));
        System.out.println(distance + " kilometers");
    }
}
