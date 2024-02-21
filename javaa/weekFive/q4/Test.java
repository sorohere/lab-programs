abstract class Student {
    String name;
    int ID;
    double grade;
    int age;

    public Student(String name, int ID, double grade, int age) {
        this.name = name;
        this.ID = ID;
        this.grade = grade;
        this.age = age;
    }

    final void displayInfo(Student obj) {
        System.out.println("Grad Student: " + obj.name + ", ID: " + obj.ID + ", Grade: " + obj.grade);
    }


    boolean isPassed(double grade) {
        return grade >= 50.0;
    }
}

class Undergrad extends Student {
    public Undergrad(String name, int ID, double grade, int age) {
        super(name, ID, grade, age);
    }

    @Override
    boolean isPassed(double grade) {
        return grade > 70.0;
    }
}

class Grad extends Student {
    public Grad(String name, int ID, double grade, int age) {
        super(name, ID, grade, age);
    }

    @Override
    boolean isPassed(double grade) {
        return grade > 80.0;
    }
}

public class Test {
    public static void main(String[] args) {
        Undergrad undergradStudent = new Undergrad("John", 123, 75.5, 20);
        Grad gradStudent = new Grad("Alice", 456, 88.2, 25);

        undergradStudent.displayInfo(undergradStudent);
        System.out.println("Passed: " + undergradStudent.isPassed(undergradStudent.grade));

        gradStudent.displayInfo(gradStudent);
        System.out.println("Passed: " + gradStudent.isPassed(gradStudent.grade));
    }
}