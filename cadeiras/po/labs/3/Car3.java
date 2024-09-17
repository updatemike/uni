public class Car3 {
    private String _brand;
    private long _mileage;
    private Tyre3[] _tyres;

    public Car3(Tyre3[] tyres, String brand) {
        int nTyres = tyres.length;
        _brand = brand;
        _mileage = 0;
        _tyres = new Tyre3[nTyres];
        for(int i = 0; 0 < nTyres; i++) {
            _tyres[i] = tyres[i];
        }
    }
    public long getMileage() {
        return _mileage;
    }
    public String getBrand() {
        return _brand;
    }
    public void setMileage(long mileage) {
        _mileage = mileage;
    }
    public boolean hasFlat() {
        for(Tyre3 tyre:_tyres) {
            if(tyre.hasFlat()) return true;
        }
        return false;
    }
    public boolean changeTyres(Tyre3[] tyres) {
        int nTyres = _tyres.length;
        if(tyres.length != nTyres) return false;
        for(int i = 0; i < nTyres; i++) {
            if(tyres[i] == null || 
                tyres[i].getRecommendedPressure() != _tyres[i].getRecommendedPressure()) {
                    return false;
                }
        }
        for(int i = 0; i < nTyres; i++) {
            _tyres[i] = tyres[i];
        }
        return true;
    }
}
