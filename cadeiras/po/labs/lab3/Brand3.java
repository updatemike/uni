public class Brand3 {
    private String _name;
    private int _year;
    private Pen3[] _pens;

    public Brand3(String name, int year) {
        _name = name;
        _year = year;
        _pens = new Pen3[1000];
    }
    public void createPen(int capacity, String color) {
        Pen3 newPen = new Pen3(this, color, capacity);
        int maxPens = _pens.length;
        for(int i = 0; i < maxPens; i++) {
            if(_pens[i] == null) {
                _pens[i] = newPen;
                return;
            }
        }
    }
}
