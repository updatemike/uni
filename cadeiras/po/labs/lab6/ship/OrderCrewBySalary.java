package ship;
import java.util.Comparator;

public class OrderCrewBySalary implements Comparator<Crew> {
    @Override
    public int compare(Crew c1, Crew c2) {
        return ((Integer)c1.getSalary()).compareTo(((Integer)c2.getSalary()));
    }
}
