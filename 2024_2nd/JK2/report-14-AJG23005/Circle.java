// AJG23005 中 天花

public class Circle extends Shape {
    public double x;
    public double y;
    public double radius;

    Circle(double x, double y, double radius) {
        this.x = x;
        this.y = y;
        this.radius = radius;
    }

    public String toString() {
        return "円:(" + x + ", " + y + "), radius=" + radius;
    }

    public double area() {
        return Math.PI * Math.pow(radius, 2);
    }

    public double perimeter() {
        return 2 * Math.PI * radius;
    }
}
