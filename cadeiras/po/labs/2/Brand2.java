import java.util.Scanner;

public class Brand2 {
    private String _name;
    private Date2 _date;
    private Pen2[] _pens;
    private int _nPens;
    private String _options;

    public Brand2(String name, Date2 date) {
        _name = name;
        _date = date;
        _pens = new Pen2[1000];
        _nPens = 0;
        _options = 
        "Options:\n" +
        "Exit (0), Show Options (1), Print Brand (2), Create a Pen (3), List Pens (4)."; 
    }

    public String getName() {
        return _name;
    }

    public Date2 getDate() {
        return _date;
    }

    public void createPen(int capacity, String color) {
        Pen2 pen = new Pen2(capacity, this, color);
        _pens[_nPens++] = pen;
    }

    public void listPens() {
        System.out.println(_nPens == 1 ? "There is 1 Pen" : "There are " + _nPens + " Pens.");
        if (_nPens == 0) return;
        for(int i = 0; i < _nPens; i++) {
            System.out.println("");
            System.out.println("Pen " + (i+1) + ".");
            System.out.println("Color: " + _pens[i].getColor());
            System.out.println("Capacity: " + _pens[i].getCapacity());
        }
    }

    public void printOptions() {
        System.out.println(_options);
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String str;
        int n, day, month, year, command = -1;

        System.out.println("Create a brand.");
        System.out.print("Brand Name: ");
        str = scanner.nextLine();
        System.out.print("Day of creation: ");
        day = scanner.nextInt();
        System.out.print("Month of creation: ");
        month = scanner.nextInt();
        System.out.print("Year of creation: ");
        year = scanner.nextInt();
        Date2 date = new Date2(day, month, year);
        Brand2 brand = new Brand2(str, date);

        brand.printOptions();
        while(command != 0) {
            System.out.println("------------------------------");
            System.out.print("Command (int): ");
            command = scanner.nextInt();

            switch(command) {
                case 0:
                    break;
                case 1:
                    brand.printOptions();
                    break;
                case 2:
                    System.out.println("Brand name: " + brand.getName());
                    System.out.println("Brand date: " + brand.getDate().getDayInt() + 
                                                    "/" + brand.getDate().getMonthInt() + 
                                                    "/" + brand.getDate().getYearInt() + ".");
                    break;
                case 3:
                    System.out.println("Create a pen.");
                    System.out.print("Capacity: ");
                    n = scanner.nextInt();
                    scanner.nextLine();
                    System.out.print("Color: ");
                    str = scanner.nextLine();
                    brand.createPen(n, str);
                    break;
                case 4:
                    brand.listPens();
                    break;
            }
        }
        scanner.close();
    }
}
