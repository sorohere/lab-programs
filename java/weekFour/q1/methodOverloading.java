class methodOverloading {
    void add(int a, int b) {
        System.out.println("ans : " + a+b);
    }

    void add(double a, double b) {
        System.out.println("ans : "+ a+b);
    }

    void add(String a, String b) {
        System.out.println("ans : "+ a+b);
    }

    public static void main(String args[]) {

        methodOverloading m1 = new methodOverloading();
        m1.add(1,2);
        m1.add(12.345, 34.434);
        m1.add("Saurabh ", "sORo");

    }
}