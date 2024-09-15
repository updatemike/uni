public class Bottle{
    private final String COR;
    private final int MAX_CAPACITY = 100;
    private int _quantity;

    public Bottle(String cor) {
        COR = cor;
    }
    public int addLiquid(int q) {
        int total = q + _quantity;
        _quantity = total > MAX_CAPACITY ? MAX_CAPACITY : total;
        return MAX_CAPACITY - _quantity;
    }
    public String getCor() {
        return COR;
    }
    public int getQuantity() {
        return _quantity;
    }
    public boolean isEmpty() {
        return _quantity == 0;
    }
    public boolean isEqual(Bottle b) {
        return COR == b.getCor() && _quantity == b.getQuantity();
    }
    public static void main(String[] args) {
        Bottle b1 = new Bottle("Verde");
        Bottle b2 = new Bottle("Verde");

        System.out.println(b1.isEqual(b2)); //true
        System.out.println(b1.isEmpty()); //true

        System.out.println(b1.addLiquid(5)); //95
        System.out.println(b1.isEqual(b2)); //false
        System.out.println(b1.isEmpty()); //false
    }
}
