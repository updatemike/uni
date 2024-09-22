public abstract class Shape {
    private int _id;
    private Point _point;
    private Editor _editor;
    private static int _idCounter = 0;

    protected Shape(Point point) {
        _id = _idCounter++;
        _point = point;
    }
    public int getID() {
        return _id;
    }
    public void setEditor(Editor editor) {
        _editor = editor;
    }
    public void removeEditor() {
        _editor = null;
    }
    protected void move(float dX, float dY) {
        _point.moveX(dX);
        _point.moveY(dY);
    }
    protected String getPointToString() {
        return _point.toString();
    }
    protected abstract String draw();

}