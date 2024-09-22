public class Line extends Shape{
    private Point _pointB;
    public Line(Point pointA, Point pointB) {
        super(pointA);
        _pointB = pointB;
    }
    @Override
    public void move(float dX, float dY) {
        super.move(dX, dY);
        _pointB.moveX(dX);
        _pointB.moveY(dY);
    }
    public String draw() {
        return "" + getID() + " Line[" + getPointToString() + " " + _pointB.toString();
    }
}