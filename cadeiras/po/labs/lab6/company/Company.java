package company;
import java.util.*;

public class Company {
    HashSet<Employee> _employees = new HashSet<>();

    public boolean addEmployee(Employee employee) {return _employees.add(employee);}
    public void printAll() {for(Employee e :_employees) System.out.println(e);}
    public Collection<Employee> getEmployeesSalaryHigher(int val) {
        ArrayList<Employee> list = new ArrayList<>();
        for(Employee e : _employees) if(e.getSalary()>val) list.add(e);
        return list;
    }
    public void removeEmployeesStartingWith(String start) {
        Iterator<Employee> iter = _employees.iterator();
        Employee e;
        while(iter.hasNext()) {
            e = iter.next();
            if(e.getName().startsWith(start)) iter.remove();
        }
    }
    public Collection<Employee> getOrderedSalaryName() {
        ArrayList<Employee> list = new ArrayList<>(_employees);
        Collections.sort(list, new EmployeeComparatorSalaryName());
        return Collections.unmodifiableCollection(list);
    }

    public static void main(String[] args) {
        Employee e1 = new Employee("Ziggy", 2000);
        Employee e2 = new Employee("Ziggy", 3000);
        Employee e3 = new Employee("Ann", 3000);
        Employee e4 = new Employee("Zetta", 2000);
        Employee e5 = new Employee("Mike", 3000);
        Employee e6 = new Employee("Tate", 4000);
        Employee e7 = new Employee("Andrew", 5000);

        Company c = new Company();
        c.addEmployee(e1);
        c.addEmployee(e2);
        c.addEmployee(e3);
        c.addEmployee(e4);
        c.addEmployee(e5);
        c.addEmployee(e6);
        c.addEmployee(e7);
        System.out.println("------------------------");
        c.printAll();
        System.out.println("------------------------");
        Collection<Employee> list;
        list = c.getEmployeesSalaryHigher(3000);
        for(Employee e : list) System.out.println(e);
        System.out.println("------------------------");
        c.removeEmployeesStartingWith("Z");
        c.printAll();
        System.out.println("------------------------");
        list = c.getOrderedSalaryName();
        for(Employee e : list) System.out.println(e);
        System.out.println("------------------------");
    }
}
