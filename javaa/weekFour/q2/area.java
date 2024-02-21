public class area {
    void Area(int a, int b) {
        System.out.println("area :"+ a*b);
    }

    void Area(double a, double b) {
        System.out.println("area :"+ a*b);
    }

    public static void main (String args[]) {
        area a1 = new area();
        a1.Area(5,10);
        a1.Area(20.0, 32.89);
    }
}
