/* Example of using static decomposition to structure code */

public class TwoMessages {
    // main calls our static methods
    public static void main(String[] args) {
        message1();
        message2();
        System.out.println("Exiting main...");
    }

    // define 1st static method
    public static void message1() {
        System.out.println("This is message1.");

    }

    // 2nd static method
    public static void message2(){
        System.out.println("This is message2.");

    }
}
