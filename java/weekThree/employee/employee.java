public class Employee {
    private static int employee_no = 0;
    private static double total_expenses = 0;
    private String employee_ID;
    private String Department;
    private double salary;
    Employee(String Employee_ID, String department, double Salary){
        employee_ID = Employee_ID;
        salary = Salary;
        Department = department;
        total_expenses += Salary;
        employee_no++;
    }
    void display(){
        System.out.println("Employee ID: "+employee_ID+ "  Department: " + Department +"  Salary: "+salary);
    }
    public static void main(String[] args) {
        Employee s1 = new Employee("1MS22CS119","Software Developer",200000);
        Employee s2 = new Employee("1MS22CS112","Data Analyst", 120560);
        Employee s3 = new Employee("1MS22CS124","Software Tester", 90422);
        Employee s4 = new Employee("1MS22CS126","Financial Advisory", 180000);
        s1.display();
        s2.display();
        s3.display();
        s4.display();
        System.out.println("\n");
        System.out.println("Total Number of Emlpoyee: "+ employee_no);
        System.out.println("Total Salary Expenses: " + total_expenses);
    }
}
