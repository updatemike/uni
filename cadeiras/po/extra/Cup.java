public class Cup {
    public final int MAX_CAPACITY;
    private int _quantity;
    private static Cup[] _cups = new Cup[10];
    private static int _nCups;

    public Cup(int capacity) {
        MAX_CAPACITY = capacity;
        _cups[_nCups++] = this;
    }
    public int addLiquid(int quantity) {
        int total = quantity + _quantity;
        _quantity = total > MAX_CAPACITY ? MAX_CAPACITY : total;
        return _quantity;
    }
    public int getQuantity() {
        return _quantity;
    }
    public int getMaxCapacity() {
        return MAX_CAPACITY;
    }
    public boolean isEmpty() {
        return _quantity == 0;
    }
    public boolean isEqual(Cup c) {
        return MAX_CAPACITY == c.getMaxCapacity() && _quantity == c.getQuantity();
    }
    public static int getNumberOfCups() {
        return _nCups;
    }
    public static void listCups() {
        for(Cup c:_cups) {
            if(c == null) return;
            System.out.printf("Cup:\nCapacity: %d Quantity: %d.\n", c.MAX_CAPACITY, c._quantity);
        }
    }
    public static void main(String[] args) {
        Cup c1 = new Cup(10);
        Cup c2 = new Cup(10);

        c1.addLiquid(5);
        c2.addLiquid(5);
        System.out.println(c1.isEqual(c2)); //true
        
        c2.addLiquid(10);
        System.out.println(c2.getMaxCapacity() + " " + c2.getQuantity()); //10 10
        System.out.println(c1.isEqual(c2)); //false

        System.out.println(Cup.getNumberOfCups());
        Cup.listCups();
    }
}