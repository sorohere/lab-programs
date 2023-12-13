public class shape {
    public double calculateArea() {
        return 0; 
    }

    public static void main(String[] args) {
    Circle circle = new Circle(5.0);
    Rectangle rectangle = new Rectangle(4.0, 6.0);

    double circleArea = circle.calculateArea();
    double rectangleArea = rectangle.calculateArea();

    System.out.println("Circle Area: " + circleArea);
    System.out.println("Rectangle Area: " + rectangleArea);
    }
}

class Circle extends shape {
    private double radius;

    Circle(double radius) {
        this.radius = radius;
    }

    @Override
    public double calculateArea() {
        return 3.14 * radius * radius;
    }
}

class Rectangle extends shape {
    private double length;
    private double width;

    Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }

    @Override
    public double calculateArea() {
        return length * width;
    }
}