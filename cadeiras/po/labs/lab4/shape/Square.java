public class Square extends Shape{
    private float _length;
    public Square(Point point, float length) {
        super(point);
        _length = length;
    }
    private float getLength() {
        return _length;
    }
    public String draw() {
        return "" + getID() + " Square[" + getPointToString() + " length: " + getLength();
    }
}