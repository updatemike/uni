package lab4;

public class HeavyVehicle extends Vehicle {
    private int _numberAccelerations;
    private int _numberBreaks;
    public HeavyVehicle(String brand) {
        super(brand);
    }
    @Override
    public void doHonk() {
        System.out.println("POO POO");
    }
    @Override
    public void doBreak() {
        _numberBreaks++;
        super.doBreak();
    }
    @Override
    public void doAccelerate() {
        _numberAccelerations++;
        super.doAccelerate();
    }
    public int getNumberBreaks() {
        return _numberBreaks;
    }
    public int getNumberAccelerations() {
        return _numberAccelerations;
    }
}