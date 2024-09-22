package lab4;

public class Vehicle {
    private final String _brand;
    private ServiceStation _station;
    public Vehicle(String brand) {
        _brand = brand;
        _station = null;
    }
    public String getBrand() {
        return _brand;
    }
    public void doAccelerate() {
        System.out.println("VRUM VRUM");
    }
    public void doBreak() {
        System.out.println("GRRR GRRR");
    }
    public void doHonk() {
        System.out.println("PII PII");
    }
    public void getFuel(float value, FuelPump pump) {
       System.out.println(_station.getFuel(value, pump)); 
    }
}