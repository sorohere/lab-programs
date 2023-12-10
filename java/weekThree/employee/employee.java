public class Employee {
    private static int employeeNo = 0; 
    private static double totalExpenses = 0; 

    private String employeeID;
    private String department;
    private double salary;

    public Employee(String employeeID, String department, double salary) {
        this.employeeID = employeeID;
        this.salary = salary;
        this.department = department;
        totalExpenses += salary;
        employeeNo++;
    }

    public void display() {
        System.out.println("Employee ID: " + employeeID + "  Department: " + department + "  Salary: " + salary);
    }

    public static void displayTotalEmployees() {
        System.out.println("Total Number of Employees: " + employeeNo);
    }

    public static void displayTotalSalaryExpenses() {
        System.out.println("Total Salary Expenses: " + totalExpenses);
    }

    public static void main(String[] args) {
        Employee s1 = new Employee("1MS22CS119", "Software Developer", 200000);
        Employee s2 = new Employee("1MS22CS112", "Data Analyst", 120560);
        Employee s3 = new Employee("1MS22CS124", "Software Tester", 90422);
        Employee s4 = new Employee("1MS22CS126", "Financial Advisory", 180000);

        s1.display();
        s2.display();
        s3.display();
        s4.display();

        Employee.displayTotalEmployees();
        Employee.displayTotalSalaryExpenses();
    }
}
