package ex3;

import java.util.*;

public class Factory {
  List<Employee> _employeeList = new ArrayList<>();
  public void produce() {
    for (Employee emp : _employeeList) {
      emp.work();
    }
  }
  public void addEmployee(Employee e) {_employeeList.add(e);}
  public static void main(String[] args) {
		Factory fab = new Factory();
		fab.addEmployee(new Manager("John", 1980));
		fab.addEmployee(new Operator("Ann", 1990));
		fab.produce();
	}
}