package javaa.lab1;

class SavingsAccount {
    static int annualInterestRate;
    private double savingsBalance;

    SavingsAccount(double s) {
        savingsBalance = s;
    }

    static void modifyInterestRate(int x) {
        annualInterestRate = x;
    }

    void calculateMonthlyInterest() {
        double monthlyInterest = (savingsBalance * annualInterestRate) / 12;
        savingsBalance += monthlyInterest;
    }

    void display() {
        System.out.println(savingsBalance);
    }
}

public class savingAccount {
    public static void main(String[] args) {
        SavingsAccount saver1 = new SavingsAccount(2000);
        SavingsAccount saver2 = new SavingsAccount(3000);

        SavingsAccount.modifyInterestRate(4);
        saver1.calculateMonthlyInterest();
        saver2.calculateMonthlyInterest();
        System.out.println("Saver 1 Balance after 4% interest: ");
        saver1.display();
        System.out.println("Saver 2 Balance after 4% interest: ");
        saver2.display();

        SavingsAccount.modifyInterestRate(5);
        saver1.calculateMonthlyInterest();
        saver2.calculateMonthlyInterest();
        System.out.println("Saver 1 Balance after 5% interest: ");
        saver1.display();
        System.out.println("Saver 2 Balance after 5% interest: ");
        saver2.display();
    }
}
