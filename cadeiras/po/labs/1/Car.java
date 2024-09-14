import java.util.Scanner;

/* -----------------------
 *          Car
 * -----------------------
 * - _brand     : String
 * - _mileage   : float
 * - _tyres     : Tyre[]
 * - _maxSpeed  : int
 * - _speed     : int
 * - _break     : boolean
 * -----------------------
 * + Car(brand:String, max:int, tyres:Tyre[])
 * + getMileage()           : float
 * + getBrand()             : String
 * + checkTyresFlat()       : boolean
 * + setMileage(m:float)    : void
 * + isMoving()             : boolean
 * + getBreak()             : boolean
 * + changeBreak()          : void
 * + setSpeed(s:int)        : void
 */

public class Car {
    private String _brand;
    private float _mileage;
    private int _maxSpeed;
    private int _speed;
    private boolean _break;
    private Tyre[] _tyre = new Tyre[4];
    private String _options = 
        "Options:\n" +
        "Exit (0), Show Options (1), Print Brand (2),\n" + 
        "Print Mileage (3), Check for flat tyre (4),\n" +
        "Check break status (5), Check if car is moving (6)\n" +
        "Set new mileage (7), Change break status (8), Change speed (9)"; 

    public Car(String brand, int maxSpeed, Tyre tyres[]) {
        _brand = brand;
        _maxSpeed = maxSpeed;
        _break = true;
        
        for(int i = 0; i < 4; i++) {
            _tyre[i] = tyres[i];
        }
    }

    public float getMileage() {
        return _mileage;
    }

    public String getBrand() {
        return _brand;
    }

    public boolean checkTyresFlat() {
        for(Tyre tyre:_tyre) if(tyre.isFlat()) return true;
        return false;
    }

    public void setMileage(float mileage) {
        _mileage = mileage;
    }

    public boolean isMoving() {
        return !(_speed == 0);
    }

    public boolean getBreak() {
        return _break;
    }

    public void changeBreak() {
        _break = _break ? false : true;
        if(_break) _speed = 0;
    }

    public void setSpeec(int speed) {
        if (speed > _maxSpeed || speed < 0 || _break) return;
        _speed = speed;
    }

    public void printOptions() {
        System.out.println(_options);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String txt1;
        int i1, command = -1;
        float f1, f2;
        Tyre[] tires = new Tyre[4];

        System.out.println("Let's create a Car.");
        System.out.print("Brand (string): ");
        txt1 = scanner.nextLine();
        System.out.print("Max Speed (int): ");
        i1 = scanner.nextInt();
        for(int i = 0; i < 4; i++) {
            System.out.println("Tyre " + i + ".");
            System.out.print("Recommended Pressure (float): ");
            f1 = scanner.nextFloat();
            System.out.print("Pressure (float): ");
            f2 = scanner.nextFloat();
            tires[i] = new Tyre(f2, f1);
        }
        Car car = new Car(txt1, i1, tires);
        
        car.printOptions();
        while(command != 0) {
            System.out.println("------------------------------");
            System.out.print("Command (int): ");
            command = scanner.nextInt();
            switch (command) {
                case 0:
                    System.out.println("Goodbye.");
                    break;
                case 1:
                    car.printOptions();
                    break;
                case 2:
                    System.out.println("Brand: " + car.getBrand());
                    break;
                case 3:
                    System.out.println("Mileage: " + car.getMileage());
                    break;
                case 4:
                    System.out.println(car.checkTyresFlat() ? "There is a flat tyre." : "No flat tyres.");
                    break;
                case 5:
                    System.out.println(car.getBreak() ? "Break in on." : "Break is off.");
                    break;
                case 6:
                    System.out.println(car.isMoving() ? "Car is moving." : "Car has stopped.");
                    break;
                case 7:
                    System.out.print("New mileage: ");
                    car.setMileage(scanner.nextFloat());
                    break;
                case 8:
                    car.changeBreak();
                    System.out.println(car.getBreak() ? "Break activated." : "Break deactivated");
                    break;
                case 9:
                    System.out.print("New speed: ");
                    car.setSpeec(scanner.nextInt());
                    break;
            }

        }
        scanner.close();
    }
}
