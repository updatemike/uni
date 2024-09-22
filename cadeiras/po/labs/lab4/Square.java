package lab4;

public class Square extends Shape{
    private float _length;
    public Square(int id, Point point, float length) {
        super(id, point);
        _length = length;
    }
    public void draw() {}
}