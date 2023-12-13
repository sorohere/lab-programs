public class stringss {
    void add(String a, String b) {
        System.out.println("ans :"+ a +" "+ b);
    }

    void add(String a, String b, String c) {
        System.out.println("ans :"+ a +" "+ b +" "+ c);
    }

    public static void main (String args[]) {
        stringss a1 = new stringss();
        a1.add("hello","world");
        a1.add("Saurabh", "aka", "sORo");
    }
}