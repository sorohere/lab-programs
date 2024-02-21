package javaa.lab2.Q7;

interface Calc {
    int res(int x, int y);
}

public class Main {
    public static void main(String[] args) {
        Calc addition = (x, y) -> (x + y);
        System.out.println("\nSUM IS: " + addition.res(2, 3));

        Calc multiplication = (x, y) -> (x * y);
        System.out.println("\nPRODUCT IS: " + multiplication.res(3, 4));
    }
}

