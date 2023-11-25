import java.util.Scanner;
public class calculator{
public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    System.out.print("enter operator: ");
    char operator = sc.next().charAt(0);
    System.out.print("enter num1: ");
    int a = sc.nextInt();
    System.out.print("enter second number: ");
    int b = sc.nextInt();


    switch(operator){
        case '+':
            System.out.print("sum is: " + (a + b));
            break;
        case '-':
            System.out.println("difference is: " + (a - b));
            break;
        case '*':
            System.out.println("product is: " + (a * b));
            break;
        case '/':
            System.out.println("quotient is: " + (a / b));
            break;
        case '%':
            System.out.println("remainder is: " + (a % b));
            break;
        default: 
            System.out.println("enter operator properly");
            break;

    }
}}