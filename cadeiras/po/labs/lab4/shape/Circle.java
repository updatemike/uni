public class Circle extends Shape{
    private float _radius;
    public Circle(Point point, float radius) {
        super(point);
        _radius = radius;
    }
    private float getRadius() {
        return _radius;
    }
    public String draw() {
        return "" + getID() + " Circle[" + getPointToString() + " radius: " + getRadius();
    }
}