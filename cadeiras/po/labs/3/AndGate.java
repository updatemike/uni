public class AndGate {
    private boolean _gateA;
    private boolean _gateB;

    public AndGate() {}
    public AndGate(boolean a, boolean b) {
        _gateA = a;
        _gateB = b;
    }
    public void setInputA(boolean v) {
        _gateA = v;
    }
    public void setInputB(boolean v) {
        _gateB = v;
    }
    public boolean getOutput() {
        return _gateA && _gateB;
    }
    public static void main(String[] args) {
        AndGate g1 = new AndGate();
        AndGate g2 = new AndGate(true, true);

        System.out.println("g1: " + g1.getOutput()); //false
        System.out.println("g2: " + g2.getOutput()); //true
        g1.setInputA(true);
        g2.setInputB(false);
        System.out.println("g1: " + g1.getOutput()); //false
        System.out.println("g2: " + g2.getOutput()); //false
    }
}