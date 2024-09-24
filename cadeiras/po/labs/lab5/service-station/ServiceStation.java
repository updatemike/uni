public class ServiceStation {
    private final float _capacity;
    private float _quantity;
    private final Pump[] _pumps;
    public ServiceStation(float capacity) {
        _pumps = new Pump[10];
        _quantity = _capacity = capacity;
        for(int i = 0; i < 10; i++) {
            _pumps[i] = new Pump(i);
        }
    }
    public float getFuel(float quantity, int pumpID) {
        Pump p = findPump(pumpID);
        if(_quantity == 0) return 0;
        if(quantity > _quantity) {
            p.setConsumed(_quantity);
            float tmp = quantity - _quantity;
            _quantity = 0;
            return tmp;
        }
        p.setConsumed(quantity);
        _quantity -= quantity;
        return quantity;
    }
    private Pump findPump(int pumpID) {
        for(Pump p:_pumps) {
            if(pumpID == p.getPumpID()) return p;
        }
        return null;
    }
    public float setQuantity(float quantity) {
        float total = quantity + _quantity;
        if(total > _capacity) {
            _quantity = _capacity;
            return total - _capacity;
        }
        _quantity = total;
        return 0;
    }

    public static void main(String[] args) {
        Vehicle[] _vehicles = new Vehicle[10];
        ServiceStation station = new ServiceStation(1000);
        for(int i = 0; i < 10; i++) {
            Vehicle v;
            _vehicles[i] =  i < 5 ? new Vehicle("XPTO" + i) : new HeavyVehicle("XPTO" + i);
            _vehicles[i].setStation(station);
            v = _vehicles[i];
            System.out.println("Vehicle " + i);
            System.out.println("Brand: " + v.getBrand());
            v.doHonk();
            v.getFuel(150, 2);
        }
    }
}