public class Tyre3{
    private float _pressure;
    private float _recommendedPressure;

    public Tyre3(float recommended) {
        _pressure = _recommendedPressure = recommended;
    }

    public float getRecommendedPressure() {
        return _recommendedPressure;
    }

    public boolean hasFlat() {
        return _pressure < 0.8 * _recommendedPressure;
    }
}