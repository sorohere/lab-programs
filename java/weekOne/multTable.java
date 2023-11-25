import java.util.Scanner;

public class multTable{
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        System.out.print("enter number: ");
        int num = scanner.nextInt();
        for (int i = 0; i < 10; i++){
            System.out.print(num*(i + 1) + "\n");
        }
    }
}