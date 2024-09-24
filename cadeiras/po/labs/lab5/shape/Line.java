public class Line extends Shape {
    private Point _end;
    public Line(int originX, int originY, int endX, int endY) {
        super(originX, originY);
        _end = new Point(endX, endY);
    }
    public String getType() {
        return "Line";
    }
    public String getCharacteristics() {
        return _end.drawPoint();
    }
    @Override
    public void move(int newX, int newY) {
        Point origin = super.getOrigin();
        int dx = newX - origin.getX();
        int dy = newY - origin.getY();
        super.move(newX, newY);
        _end.move(_end.getX() + dx, _end.getY() + dy);
    }
}