package company;
import java.util.Comparator;

public class EmployeeComparatorSalaryName implements Comparator<Employee>{
    @Override
    public int compare(Employee e, Employee e2) {
        // int compare = ((Integer)e.getSalary()).compareTo(((Integer)e2.getSalary()));
        int compare = ((Integer)e.getSalary()).compareTo(((Integer)e2.getSalary()));
        if(compare == 0) return e.getName().compareTo(e2.getName());
        return compare;
    }   
}
