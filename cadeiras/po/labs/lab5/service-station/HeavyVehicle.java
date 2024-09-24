public class HeavyVehicle extends Vehicle {
    private int _numberBreaks;
    private int _numberAccelerations;

    public HeavyVehicle(String brand) {
        super(brand);
    }
    @Override
    public void doHonk() {
        System.out.println("POO POO");
    }
    public int getNumberBreaks() {
        return _numberBreaks;
    }
    public int getNumberAcceleration() {
        return _numberAccelerations;
    }
}