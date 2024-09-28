package enumerated;

import interfaces.ToString;

public enum Season implements ToString {
    SPRING("nice","sunny"),
    SUMMER("hot", "sunny"),
    FALL("nice", "ok"),
    WINTER("cold", "rainy");

    private String _temp;
    private String _weather;

    Season(String temp, String weather) {
        _temp = temp;
        _weather = weather;
    }
    public String toString() {
        return "Temperature: " + _temp + " Weather: " + _weather;
    }
}