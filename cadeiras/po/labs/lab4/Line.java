package lab4;

public class Line extends Shape{
    private Point _pointB;
    public Line(int id, Point pointA, Point pointB) {
        super(id, pointA);
        _pointB = pointB;
    }
    @Override
    public void move(float dX, float dY) {
        super.move(dX, dY);
        _pointB.moveX(dX);
        _pointB.moveY(dY);
    }
    public void draw() {}
}