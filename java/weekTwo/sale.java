import java.util.Scanner;

public class list_sale {
    public static void main(String[]args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of product: ");
        int n = scanner.nextInt();

        int ans = 0;
        int maxnum= -1;
        int minnum = scanner.nextInt();
        int minid = 1;
        int maxid = 1;

        maxnum = minnum;

        for(int i = 1; i<n; i++) {
            int num = scanner.nextInt();
            ans += num;
            if(num < maxnum) {
                maxnum = num;
                maxid = i+1;
            }
            
            if(num > minnum) {
                minnum = num;
                minid = i+1;
            }
        }

        System.out.println("the average is: " + ans/n);
        System.out.println("the sum is: " + ans);
        System.out.println("product id is: " + maxid + " maximum sale is: " + maxnum);
        System.out.println("product id is: " + minid + " minimum sale is: " + minnum);
    }
}