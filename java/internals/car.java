class Car {
    int speed;
    double regularPrice;
    String color;

    Car(int s, double price, String c) {
        speed = s;
        regularPrice = price;
        color = c;
    }

    double getSalePrice() {
        return regularPrice;
    }
}

class Truck extends Car {
    int weight;

    Truck(int s, double price, String c, int w) {
        super(s, price, c);
        weight = w;
    }

    double getSalePrice() {
        if (weight > 2000) {
            regularPrice *= 0.9;
            return regularPrice;
        } else {
            regularPrice *= 0.8;
            return regularPrice;
        }
    }
}

class Ford extends Car {
    int manufacturerDiscount, year;

    Ford(int s, double price, String c, int m) {
        super(s, price, c);
        manufacturerDiscount = m;
    }

    double getSalePrice() {
        regularPrice -= manufacturerDiscount;
        return regularPrice;
    }
}

class Sedan extends Car {
    int length;

    Sedan(int s, double price, String c, int l) {
        super(s, price, c);
        length = l;
    }

    double getSalePrice() {
        if (length > 20) {
            regularPrice *= 0.95;
            return regularPrice;
        } else {
            regularPrice *= 0.9;
            return regularPrice;
        }
    }
}

public class Program4 {
    public static void main(String[] args) {
        Truck t = new Truck(65, 2500000, "Red", 3000);
        System.out.println("Price of truck is " + t.getSalePrice());

        Car c = new Car(100, 800000, "Black");
        System.out.println("Price of Car is " + c.getSalePrice());

        Ford f = new Ford(120, 2200000, "Yellow", 120000);
        System.out.println("Price of ford is " + f.getSalePrice());

        Sedan s = new Sedan(100, 3500000, "Blue", 22);
        System.out.println("Price of Sedan is " + s.getSalePrice());
    }
}
