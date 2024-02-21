package javaa.lab2.Q6;

class A {
    synchronized void displayTable(int n) {
        try {
            for (int i = 1; i <= 10; i++) {
                System.out.println(i * n);
                Thread.sleep(1000);
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class Mul extends Thread {
    private A a;
    private int n;

    Mul(A a, int n) {
        this.a = a;
        this.n = n;
    }

    public void run() {
        a.displayTable(n);
    }
}

public class Main {
    public static void main(String[] args) {
        A a = new A();
        Mul m = new Mul(a, 8);
        Mul m1 = new Mul(a, 9);
        m.start();
        m1.start();
    }
}

