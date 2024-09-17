public class Number3 {
    private int _val;

    public Number3() {}
    public Number3(int n) {
        _val = n;
    }
    public void set(int n) {
        _val = n;
    }
    public int get() {
        return _val;
    }
    public String toString() {
        return String.valueOf(_val);
    }
    public boolean equals(Number3 number) {
        return _val == number.get();
    }
    public int getGreater(Number3 number) {
        int n = number.get();
        if(_val > n) return _val;
        return n;
    }
    public static void main(String[] args) {
        Number3 n1 = new Number3();
        Number3 n2 = new Number3(20);
        System.out.println("n1: " + n1 + "\nn2: " + n2);
        System.out.println("n1 == n2? " + n1.equals(n2));
        System.out.println("Greater number: " + n1.getGreater(n2));
        n1.set(20);
        System.out.println("n1: " + n1 + "\nn2: " + n2);
        System.out.println("n1 == n2? " + n1.equals(n2));
    }
}
