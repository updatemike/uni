public abstract class Shape {
    private static int _numberShapes = 0;
    private final int _id;
    private Point _origin;
    private Editor _editor;
    protected Shape(int x, int y) {
        _id = _numberShapes++;
        _origin = new Point(x, y);
        _editor = null;
    }
    protected Point getOrigin() {
        return _origin;
    }
    public void move(int newX, int newY) {
        _origin.move(newX, newY);
    }
    public void draw() {
        System.out.println(_id + " " + getType() + " [" + _origin.drawPoint() + " " + getCharacteristics() + "]");
    }
    protected abstract String getType();
    protected abstract String getCharacteristics();

}