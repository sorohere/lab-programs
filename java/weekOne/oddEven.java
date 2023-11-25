import java.util.Scanner;
public class oddEven{
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        System.out.print("enter number: ");
        int num = scanner.nextInt();
        if (num % 2 == 0){
            System.out.print("number is even\n");
        }
        else{
            System.out.print("number is odd\n");
        }
        
    }
}