package pencilcase;

public class Pencil {
    private String _brand;
    private String _color;
    public Pencil(String brand, String color) {
        _brand = brand;
        _color = color;
    }
    public boolean equals(Pencil p) {return _brand.equals(p._brand) && _color.equals(p._color);}
    public String getColor() {return _color;}
    public String getBrand() {return _brand;}
    public String toString() {return "Brand: " + _brand + " Color: " + _color;}
}