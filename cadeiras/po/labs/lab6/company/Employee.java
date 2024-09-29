package company;

public class Employee {
    private final String _name;
    private int _salary;

    Employee(String name, int salary) {
        _name = name;
        _salary = salary;
    }
    public boolean equals(Object o) {
        if(o instanceof Employee) {
            Employee e = (Employee)o;
            return _name.equals(e._name);
        }
        return false;
    }
    public String toString() {
        return "Name: " + _name + " Salary: " + _salary;
    }
    public int hashCode() {
        return _name.hashCode();
    }
    public String getName() {return _name;}
    public int getSalary() {return _salary;}
}