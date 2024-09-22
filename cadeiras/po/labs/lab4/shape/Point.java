public class Point {
    private float _positionX;
    private float _positionY;
    Point(float x, float y) {
        _positionX = x;
        _positionY = y;
    }
    public void moveX(float dX) {
        _positionX += dX;
    }
    public void moveY(float dY) {
        _positionY += dY;
    }
    public float getX() {
        return _positionX;
    }
    public float getY() {
        return _positionY;
    }
    public String toString() {
       return "x:" + _positionX + " y: " + _positionY;
    }
}