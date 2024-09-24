public class Vehicle {
    private String _brand;
    private ServiceStation _station;

    public Vehicle(String brand) {
        _brand = brand;
    }
    public void setStation(ServiceStation station) {
        _station = station;
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
    public void getFuel(float quantity, int pumpID) {
        System.out.println(_station.getFuel(quantity, pumpID));
    }
    public String getBrand() {
        return _brand;
    }

}