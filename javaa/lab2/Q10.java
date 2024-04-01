import java.util.Scanner;

class NameException extends Exception {
    String name;

    NameException(String n) {
        name = n;
    }

    public String toString() {
        return name + " is not an acceptable name";
    }
}

class AgeException extends Exception {
    int age;

    AgeException(int a) {
        age = a;
    }

    public String toString() {
        return age + " is greater than 50";
    }
}

class Employee {
    int age;
    String name;

    Employee(int a, String n) {
        age = a;
        name = n;
    }

    void display() {
        System.out.println("Employee Name: " + name + "\nEmployee age: " + age);
    }
}

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Name and age");
        int a;
        String n;
        try {
            n = sc.nextLine();
            if (isNumeric(n)) {
                throw new NameException(n);
            }
            a = sc.nextInt();
            if (a > 50) {
                throw new AgeException(a);
            }
            Employee emp = new Employee(a, n);
            emp.display();
        } catch (NameException e) {
            System.out.println(e);
        } catch (AgeException e) {
            System.out.println(e);
        }
    }

    public static boolean isNumeric(String str) {
        try {
            Double.parseDouble(str);
            return true;
        } catch (NumberFormatException e) {
            return false;
        }
    }
}
