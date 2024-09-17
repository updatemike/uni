public class AndGate3 {
    private boolean _inputA;
    private boolean _inputB;

    public AndGate3(){}
    public AndGate3(boolean inputA, boolean inputB) {
        _inputA = inputA;
        _inputB = inputB;
    }
    public void setA(boolean val) {
        _inputA = val;
    }
    public void setB(boolean val) {
        _inputB = val;
    }
    public boolean getOutput() {
        return _inputA && _inputB;
    }
    public static void main(String[] args) {
        AndGate3 gate = new AndGate3();
        System.out.println("Gate output: " + gate.getOutput());
        gate.setA(true);
        System.out.println("Gate output: " + gate.getOutput());
        gate.setB(true);
        System.out.println("Gate output: " + gate.getOutput());
    }
}
