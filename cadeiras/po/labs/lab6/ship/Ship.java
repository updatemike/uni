package ship;
import java.util.*;

public class Ship {
    HashMap<Integer, Crew> _crew = new HashMap<>();
    public Collection<Crew> getCrewSalaryUnder(int value) {
        Collection<Crew> col = new ArrayList<>();
        for(Crew c : _crew.values()) {
            if(c.getSalary() < value) col.add(c);
        }
        return Collections.unmodifiableCollection(col);
    }
    public boolean addCrew(Crew c) {
        Crew a = _crew.put(c.getID(), c);
        if(a == null) return false;
        return true;
    }
    public void listCrew() {
        for(Crew c : _crew.values()) {System.out.println(c);}
    }
    public boolean removeCrewByID(int id) {
        return !(_crew.remove(id) == null);
    }
    public Collection<Crew> getCrewSalaryLower(int value) {
        Collection<Crew> list = new ArrayList<>();
        for(Crew c : _crew.values()) {
            if(c.getSalary() < value) list.add(c);
        }
        return Collections.unmodifiableCollection(list);
    }
    public boolean removeCrew(int ID) {
        return _crew.remove(ID) == null;
    }
    public void removeAllOlderThan(int year) {
        Iterator<Crew> iter = _crew.values().iterator();
        Crew c;
        while(iter.hasNext()) {
            c = iter.next();
            if(c.getYear()<year) iter.remove();
        }
    }
    public Collection<Crew> getOrderedBySalary() {
        ArrayList<Crew> list = new ArrayList<>(_crew.values());
        Collections.sort(list, new OrderCrewBySalary());
        return Collections.unmodifiableCollection(list);
    }

    public static void main(String[] args) {
        Crew c1 = new Crew("John", 1990, 6000);
        Crew c2 = new Crew("A", 2020, 4000);
        Ship s = new Ship();
        s.addCrew(c1);
        s.addCrew(c2);
        s.listCrew();;
        System.out.println("----------------------");
        System.out.println(s.removeCrewByID(10));
        // System.out.println(s.removeCrewByID(0));
        // s.removeAllOlderThan(2000);
        // s.listCrew();
        System.out.println("----------------------");
        Collection<Crew> col = s.getOrderedBySalary();
        for(Crew c : col) {
            System.out.println(c);
        }
    }
}