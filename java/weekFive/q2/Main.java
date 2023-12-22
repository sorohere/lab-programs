class Student {
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

    boolean isPassed(double grade) {
        return grade >= 50.0; 
    }
}

class Undergrad extends Student {
    public Undergrad(String name, int ID, double grade, int age) {
        super(name, ID, grade, age);
    }
}

class Grad extends Student {
    public Grad(String name, int ID, double grade, int age) {
        super(name, ID, grade, age);
    }
}

public class Main {
    public static void main(String[] args) {
        Undergrad undergradStudent = new Undergrad("John", 123, 75.5, 20);
        Grad gradStudent = new Grad("Alice", 456, 88.2, 25);

        System.out.println(undergradStudent.name + " passed: " + undergradStudent.isPassed(undergradStudent.grade));
        System.out.println(gradStudent.name + " passed: " + gradStudent.isPassed(gradStudent.grade));
    }
}

