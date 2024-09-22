package lab4;

public class Number {
    private int _value;
    public Number(int value) {
        setValue(value);
    }
    public void setValue(int value) {
        _value = value;
    }
    public int getValue() {
        return _value;
    }
}