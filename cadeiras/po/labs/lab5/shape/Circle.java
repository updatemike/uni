public class Circle extends Shape{
    private int _radius;
    public Circle(int x, int y, int radius) {
        super(x, y);
        _radius = radius;
    }
    public String getType() {
        return "Circle";
    }
    public String getCharacteristics() {
        return "radius: " + _radius;
    }
}