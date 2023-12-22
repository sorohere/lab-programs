class SavingsAccount {
    private static double annualInterestRate;
    private double savingsBalance;

    public SavingsAccount(double savingsBalance) {
        this.savingsBalance = savingsBalance;
    }

    public void calculateMonthlyInterest() {
        double monthlyInterest = (savingsBalance * annualInterestRate / 12) / 100; 
        savingsBalance += monthlyInterest;
    }

    public static void modifyInterestRate(double newRate) {
        annualInterestRate = newRate;
    }

    public double getSavingsBalance() {
        return savingsBalance;
    }
}

public class Test {
    public static void main(String[] args) {
        SavingsAccount saver1 = new SavingsAccount(2000.00);
        SavingsAccount saver2 = new SavingsAccount(3000.00);

        SavingsAccount.modifyInterestRate(4.0);

        saver1.calculateMonthlyInterest();
        saver2.calculateMonthlyInterest();

        System.out.println("Saver1 Balance after 4% interest: Rs." + saver1.getSavingsBalance());
        System.out.println("Saver2 Balance after 4% interest: Rs." + saver2.getSavingsBalance());

        SavingsAccount.modifyInterestRate(5.0);

        saver1.calculateMonthlyInterest();
        saver2.calculateMonthlyInterest();

        System.out.println("Saver1 Balance after 5% interest: Rs." + saver1.getSavingsBalance());
        System.out.println("Saver2 Balance after 5% interest: Rs." + saver2.getSavingsBalance());
    }
}
