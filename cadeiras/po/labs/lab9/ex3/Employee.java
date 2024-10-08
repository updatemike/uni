package ex3;

public abstract class Employee {
  private String _name;
  private int _birth;
  protected Employee(String name, int birth) {
    _name = name;
    _birth = birth;
  }
  public String getName() {return _name;}
  public int getBirth() {return _birth;}
  public abstract void work();
}