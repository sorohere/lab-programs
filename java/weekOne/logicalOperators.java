import java.util.Scanner;

class logicalOperators{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        boolean high = true;
        boolean low = false;

        System.out.println("and operation: " + (high && low));
        System.out.println("or operation: " + (high || low));
        System.out.println("not operation on high: " + (!high));
    }
}