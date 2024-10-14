package company;

public class Manager extends Employee {
  
  public Manager(String name) {
    super(name);
  }
  
  public int getCost() {
    return 1000;
  }
  
  public void doWork() {
    System.out.println("Manager is working");
  }
}
