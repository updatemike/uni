public class Square extends Shape{
    private int _length;
    public Square(int x, int y, int length) {
        super(x,y);
        _length = length;
    }
    public String getType() {
        return "Square";
    }
    public String getCharacteristics() {
        return "length: " + _length;
    }
}