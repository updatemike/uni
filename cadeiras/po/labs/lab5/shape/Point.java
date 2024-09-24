public class Point {
    private int _posX;
    private int _posY;
    Point(int x, int y) {
        _posX = x;
        _posY = y;
    }
    public int getX() {
        return _posX;
    }
    public int getY() {
        return _posY;
    }
    public void move(int newX, int newY) {
        _posX = newX;
        _posY = newY;
    }
    public String drawPoint() {
        return "X: " + _posX + ", Y: " + _posY;
    }
}
