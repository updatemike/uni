public class TernaryAndGate3 {
    private AndGate3 _g1 = new AndGate3();
    private AndGate3 _g2 = new AndGate3();
    
    public TernaryAndGate3() {
        _g2.setA(_g1.getOutput());
    }
    public void setA(boolean val) {
        _g1.setA(val);
        _g2.setA(_g2.getOutput());
    }
    public void setB(boolean val) {
        _g1.setB(val);
        _g2.setA(_g1.getOutput());
    }
    public void setC(boolean val) {
        _g2.setB(val);
    }
    public boolean getOutput() {
        return _g2.getOutput();
    }
    public static void main(String[] args) {
        TernaryAndGate3 gate = new TernaryAndGate3();
        System.out.println("Gate output: " + gate.getOutput());
        gate.setA(true);
        System.out.println("Gate output: " + gate.getOutput());
        gate.setB(true);
        System.out.println("Gate output: " + gate.getOutput());
        gate.setC(true);
        System.out.println("Gate output: " + gate.getOutput());
    }
}
