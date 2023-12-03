import java.util.Scanner;

public class grading {
    public static void main(String[]args) {
        Scanner scanner = new Scanner(System.in);

        boolean check = true;
        while(check){

            System.out.print("Enter the number of question: ");
            int n = scanner.nextInt();

            int[] answer = new int[n];
            double percent = 0;
            int cnt = 0;
            System.out.print("Enter the correct answers: ");
            for(int i = 0; i<n; i++) {
                answer[i] = scanner.nextInt();
            }

            System.out.print("Enter your answers: ");
            for(int i = 0; i<n; i++) {
                int num = scanner.nextInt();
                if(answer[i] == num) {
                    cnt ++;
                }
            }

            percent = (cnt * 100) / n;
            System.out.println("Total correct ans is: " + cnt + " percentage is: " + percent);

            System.out.println("Do you want to grade another quiz?? (0/1)");

            int temp = scanner.nextInt();
            if(temp == 0) check = false;
        }

    }
}