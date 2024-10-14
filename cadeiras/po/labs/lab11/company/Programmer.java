package company;

public class Programmer extends Employee {
  
  public Programmer(String name) {
    super(name);
  }
  
  public int getCost() {
    return 1500;
  }
  
  public void doWork() {
    System.out.println("Normal Programmer is programming");
  }
}
