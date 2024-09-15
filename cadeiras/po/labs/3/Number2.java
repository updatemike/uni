public class Number2{
    private int _value;
    private static Number2[] _numbers = new Number2[99];

    public Number2() {}
    public Number2(int n) {
        _value = n;
        _numbers[n] = this;
    }
    // private boolean checkNumbers(int n) {
    //     return _numbers[n] != null; 
    // }
    public int getValueInt() {
        return _value;
    }
    public String getValueString() {
        return String.valueOf(_value);
    }
    public boolean isEqual(Number2 n) {
        return _value == n.getValueInt();
    }
    public Number2 getGreater(Number2 n) {
        return _value > n.getValueInt() ? this : n;
    }

    public static void main (String[] args) {
        Number2 n1 = new Number2();
        Number2 n2 = new Number2(0);
        Number2 n3 = new Number2(5);

        System.out.println(n1.getValueInt() + " " + n1.getValueString());
        System.out.println(n1.isEqual(n2) + " " + n1.isEqual(n3));
        System.out.println(n1.getGreater(n2).getValueInt() + " " + n1.getGreater(n3).getValueInt());
    }
}