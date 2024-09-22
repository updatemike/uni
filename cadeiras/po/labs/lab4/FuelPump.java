package lab4;

public class FuelPump {
    private float _consumed;
    public FuelPump() {
        setConsumed(0);
    }
    private void setConsumed(float value) {
        _consumed = value;
    }
    public float getConsumed() {
        return _consumed;
    }
    public void addConsumed(float value) {
        setConsumed(_consumed + value);
    }
}