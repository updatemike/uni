package lab4;

public class Circle extends Shape{
    private float _radius;
    public Circle(int id, Point point, float radius) {
        super(id, point);
        _radius = radius;
    }
    public void draw() {}
}