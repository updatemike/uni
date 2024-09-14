import java.util.Scanner;

/* -----------------------
 *          Tyre
 * -----------------------
 * -_ pressure : float
 * -_ recommendedPressure : float
 * -_ punctured : boolean
 * -----------------------
 * + Tyre (pressure : float, recommended : float)
 * + getPressure () : float
 * + setPressure (pressure : float) : void
 * + getRecommendedPressure () : float
 * + isFlat () : boolean
 * + isPunctured () : boolean
 */
 
public class Tyre {
    private float _pressure;
    private float _recommendedPressure;
    private boolean _punctured;
    private String _options = 
        "Options:\n" +
        "Exit (0), Show Options (1), Print Pressure (2),\n" + 
        "Print Recommended Pressure (3), Set new Pressure (4),\n" +
        "Check if Flat (5), Check if Punctured (6)"; 

    public Tyre(float pressure, float recommended) {
        _pressure = pressure;
        _recommendedPressure = recommended;
    }
    public float getPressure() {
        return _pressure;
    }
    public void setPressure(float pressure) {
        if(_punctured) return;
        _pressure = pressure;
        _punctured = pressure > 1.5*_recommendedPressure ? true : false;
        if(_punctured) _pressure = 0;
    }
    public float getRecommendedPressure() {
        return _recommendedPressure;
    }
    public boolean isFlat() {
        return _pressure < 0.8 * _recommendedPressure;
    }
    public boolean isPunctured() {
        return _punctured;
    }
    public void printOptions() {
        System.out.println(_options);
    }

    public static void main(String[] args) {
        int command = -1;
        float f1, f2;
        Scanner scanner = new Scanner(System.in);

        System.out.println("Let's create a Tyre.");
        System.out.print("Recommended Pressure (float): ");
        f1 = scanner.nextFloat();
        System.out.print("Pressure (float): ");
        f2 = scanner.nextFloat();
        Tyre t = new Tyre(f2, f1);
        
        t.printOptions();
        while(command != 0) {
            System.out.println("------------------------------");
            System.out.print("Command (int): ");
            command = scanner.nextInt();
            switch (command) {
                case 0:
                    System.out.println("Goodbye.");
                    break;
                case 1:
                    t.printOptions();
                    break;
                case 2:
                    System.out.println("Pressure: " + t.getPressure());
                    break;
                case 3:
                    System.out.println("Recommended Pressure: " + t.getRecommendedPressure());
                    break;
                case 4:
                    System.out.print("New Pressure (float): ");
                    f1 = scanner.nextFloat();
                    t.setPressure(f1);
                    break;
                case 5:
                    System.out.println(t.isFlat() ? "Tyre is flat." : "Tyre is not flat.");
                    break;
                case 6:
                    System.out.println(t.isPunctured() ? "Tyre is punctured" : "Tyre is not punctured.");
                    break;
            }

        }
        scanner.close();
    }
}