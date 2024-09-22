package lab4;

public class ServiceStation {
    private float _fuelCapacity;
    private float _fuelQuantity;
    private FuelPump[] _pumps;
    public ServiceStation(float capacity) {
        setFuelCapacity(capacity);
        setFuelQuantity(capacity);
        _pumps = new FuelPump[10];
    }
    public float getFuelQuantity() {
        return _fuelQuantity;
    }
    public void setFuelQuantity(float quantity) {
        _fuelQuantity = quantity;
    }
    public float getFuelCapacity() {
        return _fuelCapacity;
    }
    public void setFuelCapacity(float capacity) {
        _fuelCapacity = capacity;
    }
    public float getFuel(float quantity, FuelPump pump) {
        for(FuelPump p:_pumps) {
            if(p.equals(pump)) {
                p.addConsumed(quantity);
                break;
            }
        }
        if(quantity > getFuelQuantity()) {
            float tmp = getFuelQuantity();
            setFuelQuantity(0);
            return tmp;
        }
        setFuelQuantity(getFuelQuantity() - quantity);
        return quantity;
    }
    public float addFuel(float quantity) {
        float total = quantity + getFuelQuantity();
        float capacity = getFuelCapacity();
        if(total > capacity) {
            setFuelQuantity(capacity);
            return total - capacity;
        }
        setFuelQuantity(total);
        return 0;
    }
}