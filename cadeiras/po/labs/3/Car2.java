/* -----------------------
 *          Car
 * -----------------------
 * - _brand     : String
 * - _mileage   : float
 * - _tyres     : Tyre[]
 * - _maxSpeed  : int
 * - _nTyres    : int
 * -----------------------
 * + Car(brand:String, max:int, tyres:Tyre[], nTyres:int)
 * - setTyres(Tyre[] tires)     : void
 * + getMileage()               : float
 * + getBrand()                 : String
 * + getMaxSpeed()              : int
 * + hasFlat()                  : boolean
 * + setMileage(m:float)        : void
 * + changeTyres(tyres:Tyre[])  : boolean
 */

public class Car2 {
    private String  _brand;
    private float   _mileage;
    private Tyre[]  _tyres;
    private int     _maxSpeed;
    private int     _nTyres;

    public Car2(String brand, int maxSpeed, Tyre[] tyres, int n) {
        _brand = brand;
        _maxSpeed = maxSpeed;
        _mileage = 0;
        _tyres = new Tyre[n];
        _nTyres = n;
        setTyres(tyres);
    }

    private void setTyres(Tyre[] tyres) {
        for(int i = 0; i < _nTyres; i++) {
            _tyres[i] = tyres[i];
        }
    }

    public float getMileage() {
        return _mileage;
    }

    public String getBrand() {
        return _brand;
    }

    public int getMaxSpeed() {
        return _maxSpeed;
    }

    public boolean hasFlat() {
        for(Tyre tyre:_tyres) {
            if(tyre.isFlat()) return true;
        }
        return false;
    }

    public void setMileage(float mileage) {
        if(mileage < 0) return;
        _mileage = mileage; 
    }

    public boolean changeTyres(Tyre[] tires) {
        if(tires.length != _nTyres) return false;
        for(Tyre tyre:tires) {
            float r = tires[0].getRecommendedPressure();
            if(tyre.getRecommendedPressure() != r) return false;
        }
        setTyres(tires);
        return true;
    }


}
