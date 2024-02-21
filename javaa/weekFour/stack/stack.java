import java.util.*;

public class Stack {

    private int size;
    private List<Integer> arr = new ArrayList<>();
    private int position = -1;

    Stack(int size) {
        this.size = size;
    }

    boolean isUnderflow() {
        if (position == -1) {
            System.out.println("Stack underflow");
            return true;
        }
        return false;
    }

    boolean isOverflow() {
        if (position == size - 1) {
            System.out.println("Stack overflow");
            return true;
        }
        return false;
    }

    void push(int num) {
        if (isOverflow()) return;
        else {
            position++;
            arr.add(position, num);
        }
    }

    void pop() {
        if (isUnderflow()) return;
        else {
            position--;
        }
    }

    void peek() {
        if (isUnderflow()) return;
        else {
            System.out.println(arr.get(position));
        }
    }

    void display() {
        System.out.print("Elemets : ");
        for (int i = 0; i <= position; i++) {
            System.out.print(arr.get(i) + " ");
        }
        System.out.println("\n");
    }

    public static void main(String args[]) {
        Stack s1 = new Stack(5);
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.print("Press 1 for push\nPress 2 for pop\nPress 3 for peek\nPress 4 for display\nEnter your choice (1/2/3/4): ");
            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter element: ");
                    int element = scanner.nextInt();
                    s1.push(element);
                    break;

                case 2:
                    s1.pop();
                    break;

                case 3:
                    s1.peek();
                    break;

                case 4:
                    s1.display();
                    break;

                default:
                    System.out.println("Invalid choice");
                    break;
            }
            
            System.out.print("what to exit (0/1): ");
            int check = scanner.nextInt();
            if (check == 1) break;
        }
        scanner.close();
    }
}
