public class Pump {
    private int _pumpID;
    private float _consumed;
    public Pump(int id) {
        _pumpID = id;
        _consumed = 0;
    }
    public int getPumpID() {
        return _pumpID;
    }
    public float getConsumed() {
        return _consumed;
    }
    public void setConsumed(float quantity) {
        _consumed += quantity;
    }
    
}
