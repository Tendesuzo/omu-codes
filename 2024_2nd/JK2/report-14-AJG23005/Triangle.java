// AJG23005 中 天花

public class Triangle extends Shape {
    public double x1;
    public double y1;
    public double x2;
    public double y2;
    public double x3;
    public double y3;

    Triangle(double x1, double y1, double x2, double y2, double x3, double y3) {
        this.x1 = x1;
        this.y1 = y1;
        this.x2 = x2;
        this.y2 = y2;
        this.x3 = x3;
        this.y3 = y3;
    }

    public String toString() {
        return "三角形:" + "(" + x1 + ", " + y1 + ")" + ", " + "(" + x2 + ", " + y2 + ")" + ", " + "(" + x3 + ", " + y3 + ")";
    }

    public double area() {
        double s = (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0;
        return Math.abs(s);
    }

    public double perimeter() {
        return Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2)) + Math.sqrt(Math.pow(x3 - x2, 2) + Math.pow(y3 - y2, 2)) + Math.sqrt(Math.pow(x1 - x3, 2) + Math.pow(y1 - y3, 2));
    }
}
