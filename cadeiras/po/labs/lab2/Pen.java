import java.util.Scanner;

/* -----------------------
 *          Pen
 * -----------------------
 * - _quantity  : int
 * - _capacity  : float
 * - _brand     : String
 * - _options   : String
 * -----------------------
 * + Pen (capacity : int, brand : String, color : String)
 * + getColor()             : String
 * + getBrand()             : String
 * + getCapacity()          : int
 * + getQUantity()          : int
 * + write(input:String)    : void
 * + refill(q:int)          : int
 * + refill(q:int, color    : String) : int
 * + printOptions()         : void
 * + isEqual(pen:Pen)       : boolean
 */

public class Pen {
    private int _quantity;
    private int _capacity;
    private String _brand;
    private String _color;
    private String _options = 
        "Options:\n" +
        "Exit (0), Show Options (1), Print Brand (2),\n" + 
        "Print Color (3), Print Remaining Ink (4),\n" + 
        "Write Text (5), Refill Pen (6), Refill Pen with new color (7),\n" + 
        "Make a new pen and check if they are equal (8).";
    
    public Pen (int capacity, String brand, String color) {
        _quantity = _capacity = capacity;
        _brand = brand;
        _color = color;
    }
    public String getColor() {
        return _color;
    }
    public String getBrand() {
        return _brand;
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

    public boolean isEqual(Pen pen) {
        return (_brand.equals(pen.getBrand()) && _color.equals(pen.getColor()) && _capacity == pen.getCapacity());
    }

    public static void main(String[] args) {
        int command = -1;
        String str;
        int n;
        Pen p2;
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Let's create a pen.");

        System.out.print("Color (string): ");
        String color = scanner.nextLine();

        System.out.print("Brand (string): ");
        String brand = scanner.nextLine();

        System.out.print("Ink Capacity (int): ");
        int capacity = scanner.nextInt();

        Pen p = new Pen(capacity, brand, color);
        p.printOptions();
        while (command != 0) {
            System.out.println("------------------------------");
            System.out.print("Command (int): ");
            command = scanner.nextInt();
            switch (command) {
                case 0:
                    System.out.println("Goodbye.");
                    break;
                case 1:
                    p.printOptions();
                    break;
                case 2:
                    System.out.println("Brand: " + p._brand);
                    break;
                case 3:
                    System.out.println("Color: " + p._color);
                    break;
                case 4:
                    System.out.println("Remaining Ink: " + p._quantity);
                    break;
                case 5:
                    System.out.print("Text to write (string): ");
                    scanner.nextLine();
                    str = scanner.nextLine(); 
                    p.write(str);
                    break;
                case 6:
                    System.out.print("How much Ink to refill (int): ");
                    n = scanner.nextInt();
                    System.out.println("You have " + p.refill(n) + " extra Ink.");
                    break;
                case 7:
                    System.out.print("How much Ink to refill (int): ");
                    n = scanner.nextInt();
                    System.out.print("Color (string): ");
                    scanner.nextLine();
                    str = scanner.nextLine();
                    n = p.refill(n, str);
                    System.out.println(n == -1 ? "Pen has different colored Ink." : "You have " + n + " extra Ink.");
                case 8:
                    System.out.println("Let's create a pen.");
                    scanner.nextLine();
                    System.out.print("Color (string): ");
                    color = scanner.nextLine();
                    System.out.print("Brand (string): ");
                    brand = scanner.nextLine();
                    System.out.print("Ink Capacity (int): ");
                    capacity = scanner.nextInt();
                    p2 = new Pen(capacity, brand, color);
                    System.out.println(p.isEqual(p2) ? "The pen is the same." : "The pen is diferent.");
            }
        }
        scanner.close();
    }
}
