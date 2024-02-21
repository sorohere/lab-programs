package javaa.lab2.Q5;

import java.util.Scanner;

class TriangleException extends Exception {
    public String toString() {
        return "Not an acceptable triangle";
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a, b, c;

        System.out.println("Enter the lengths of the three sides of a triangle:");
        a = sc.nextInt();
        b = sc.nextInt();
        c = sc.nextInt();

        try {
            if ((a < b + c) && (b < a + c) && (c < a + b))
                System.out.println("Valid Triangle");
            else
                throw new TriangleException();
        } catch (TriangleException e) {
            System.out.println(e);
        }
    }
}

