package ex3;

public class Manager extends Employee {
  public Manager(String name, int birth) {
    super(name, birth);
  }
  public void work() {System.out.println("Manager " + getName() + " is managing");}
}