package company;

public abstract class Employee implements Member {
  private String _name;
  
  public Employee(String name) {
    _name = name;
  }
  
  public abstract int getCost();
  
  public abstract void doWork();
}