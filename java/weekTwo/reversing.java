import java.util.Scanner;

public class reversing {
    public static void main(String[]args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter the number of rows: ");
        int n = scanner.nextInt();
        System.out.println(0);
        for(int i =1; i<n; i++) {
            for(int j= 0; j<=i*i; j+=i) {
                System.out.print(j + " ");
            }
            System.out.println("");
        }
    }
}