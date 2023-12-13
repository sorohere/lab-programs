import java.util.*;;

public class vehicle {
    public void starting() {
        System.out.println("Vehicle is starting.");
    }

    public static void main(String[] args) {
    Car car = new Car();
    MotorCycle motorCycle = new MotorCycle();

    car.starting();
    motorCycle.starting();
    }
}

class Car extends vehicle {

    @Override
    public void starting() {
        System.out.println("Car is starting.");
    }
}

class MotorCycle extends vehicle {

    @Override
    public void starting() {
        System.out.println("MotoCycle is starting.");
    }
}