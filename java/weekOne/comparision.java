import java.util.Scanner;

public class comparision{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("enter number 1: ");
        int a = sc.nextInt();
        System.out.print("enter number 2: ");
        int b = sc.nextInt();
        System.out.println("equality: " + (a == b));
        System.out.println("inequality: " + (a != b));
        System.out.println("smaller: " + (a < b));
        System.out.println("larger: " + (a > b));
        System.out.println("smaller or equal to: " + (a <= b));
        System.out.println("larger or equal to: " + (a >= b));

    }
}
