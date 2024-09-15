public class TrenaryAndGate{
    private AndGate _gateA;
    private AndGate _gateB;

    public TrenaryAndGate() {
        _gateA = new AndGate();
        _gateB = new AndGate();
    }
    public void setInput1(boolean v) {
        _gateA.setInputA(v);
    }
    public void setInput2(boolean v) {
        _gateA.setInputB(v);
    }
    public void setInput3(boolean v) {
        _gateB.setInputB(v);
    }
    public boolean getOutput() {
        _gateB.setInputA(_gateA.getOutput());
        return _gateB.getOutput();
    }

    public static void main(String[] args) {
        TrenaryAndGate g1 = new TrenaryAndGate();
        System.out.println(g1.getOutput());
        g1.setInput1(true);
        g1.setInput2(true);
        g1.setInput3(true);
        System.out.println(g1.getOutput());
    }
}