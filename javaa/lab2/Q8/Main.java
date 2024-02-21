package javaa.lab2.Q8;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a string:");
        String s = sc.nextLine();
        int count = 0;

        if (s.length() > 0) {
            char prevChar = s.charAt(0);
            for (int i = 1; i < s.length(); i++) {
                char currentChar = s.charAt(i);
                if (currentChar == prevChar) {
                    count++;
                }
                prevChar = currentChar;
            }
        }

        System.out.println("Number of adjacent repeated characters: " + count);
    }
}
