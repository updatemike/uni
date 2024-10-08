package ex3;

public class Operator extends Employee {
  public Operator(String name, int birth) {
    super(name, birth);
  }
  public void work() {System.out.println("Operator " + getName() + " is operating.");}
}