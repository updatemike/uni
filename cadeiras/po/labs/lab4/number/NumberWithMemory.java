package lab4;

public class NumberWithMemory extends Number {
    private int _memory;
    public NumberWithMemory(int value) {
        super(value);
        setMemory(value);
    }
    public void setMemory(int value) {
        _memory = value;
    }
    public int getMemory() {
        return _memory;
    }
    public void undo() {
        int tmp = getValue();
        setValue(getMemory());
        setMemory(tmp);
    }
    
}