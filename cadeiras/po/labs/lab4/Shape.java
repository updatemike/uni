package lab4;

public abstract class Shape {
    private int _id;
    private Point _point;
    private Editor _editor;

    protected Shape(int id, Point point) {
        _id = id;
        _point = point;
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
    protected abstract void draw();
}