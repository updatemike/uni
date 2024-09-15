/* -----------------------
 *          Pen
 * -----------------------
 * - _quantity  : int
 * - _capacity  : float
 * - _brand     : Brand
 * -----------------------
 * + Pen (capacity : int, brand : String, color : String)
 * + getColor()                     : String
 * + getBrand()                     : String
 * + getCapacity()                  : int
 * + getQUantity()                  : int
 * + write(input:String)            : void
 * + refill(q:int)                  : int
 * + refill(q:int, color:String)    : int
 * + isEqual(pen:Pen)               : boolean
 */

public class Pen2 {
    private int _quantity;
    private int _capacity;
    private Brand2 _brand;
    private String _color;
    private String _options = 
        "Options:\n" +
        "Exit (0), Show Options (1), Print Brand (2),\n" + 
        "Print Color (3), Print Remaining Ink (4),\n" + 
        "Write Text (5), Refill Pen (6), Refill Pen with new color (7).";
    
    public Pen2 (int capacity, Brand2 brand, String color) {
        _quantity = _capacity = capacity;
        _brand = brand;
        _color = color;
    }
    public String getColor() {
        return _color;
    }
    public String getBrand() {
        return _brand.getName();
    }
    public int getCapacity() {
        return _capacity;
    }
    public int getQuantity() {
        return _quantity;
    }
    public void write(String input) {
        if (_quantity == 0) {
            System.out.println("Out of ink.");   
            return;
        }
        int len = input.length();
        System.out.println(input);
        if(len<_quantity) _quantity -= len;
        else _quantity = 0;
    }
    public int refill(int q) {
        int total = _quantity + q;
        if (total > _capacity) {
            _quantity = _capacity;
            return total - _capacity;
        }
        else {
            _quantity = total;
            return 0;
        }
    }
    public int refill(int q, String color) {
        return color.equals(_color) ? refill(q) : -1;
    }
    public void printOptions() {
        System.out.println(_options);
    }

    public boolean isEqual(Pen2 pen) {
        return (_brand.getName().equals(pen.getBrand()) && _color.equals(pen.getColor()) && _capacity == pen.getCapacity());
    }

}
