interface Drawable{
    void draw();
}
class Circle implements Drawable {
    @Override
    public void draw(){
        System.out.println("This is a Circle");
    }
}
class Rectangle implements Drawable {
    @Override
    public void draw(){
        System.out.println("This is a Rectangle");
    }
}
class Main{
    public static void main(String[] args) {
        Circle obj1 = new Circle();
        Rectangle obj2 = new Rectangle();
        obj1.draw();
        obj2.draw();
    }
}
