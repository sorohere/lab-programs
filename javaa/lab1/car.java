package javaa.lab1;

class Car {
    int speed;
    double regularPrice;
    String color;

    Car(int speed, double regularPrice, String color) {
        this.speed = speed;
        this.regularPrice = regularPrice;
        this.color = color;
    }

    double getSalePrice() {
        return regularPrice;
    }
}

class Truck extends Car {
    int weight;

    Truck(int speed, double regularPrice, String color, int weight) {
        super(speed, regularPrice, color);
        this.weight = weight;
    }

    double getSalePrice() {
        if (weight > 2000) {
            regularPrice *= 0.9;
        } else {
            regularPrice *= 0.8;
        }
        return regularPrice;
    }
}

class Ford extends Car {
    int manufacturerDiscount;

    Ford(int speed, double regularPrice, String color, int manufacturerDiscount) {
        super(speed, regularPrice, color);
        this.manufacturerDiscount = manufacturerDiscount;
    }

    double getSalePrice() {
        regularPrice -= manufacturerDiscount;
        return regularPrice;
    }
}

class Sedan extends Car {
    int length;

    Sedan(int speed, double regularPrice, String color, int length) {
        super(speed, regularPrice, color);
        this.length = length;
    }

    double getSalePrice() {
        if (length > 20) {
            regularPrice *= 0.95;
        } else {
            regularPrice *= 0.9;
        }
        return regularPrice;
    }
}

public class car {
    public static void main(String[] args) {
        Truck truck = new Truck(65, 2500000, "Red", 3000);
        System.out.println("Price of truck is " + truck.getSalePrice());

        Car car = new Car(100, 800000, "Black");
        System.out.println("Price of Car is " + car.getSalePrice());

        Ford ford = new Ford(120, 2200000, "Yellow", 120000);
        System.out.println("Price of ford is " + ford.getSalePrice());

        Sedan sedan = new Sedan(100, 3500000, "Blue", 22);
        System.out.println("Price of Sedan is " + sedan.getSalePrice());
    }
}
