import java.util.*;

public class Person implements Walker {
  private String _name = "Mike";
  private String _id = "123";

  public void walk() {
    System.out.println("I'm walking here!");
  }
  //Inner class
  private class OrderByNameId implements Comparator<Person>{
    public int compare(Person p1, Person p2) {
      int comp = p1._name.compareTo(p2._name);
      if (comp == 0) return p1._id.compareTo(p2._id);
      return comp;
    }
  }
  public List<Person> ordered(Collection<Person> col) {
    List<Person> list = new ArrayList<>(col);
    Collections.sort(list,new OrderByNameId());
    return Collections.unmodifiableList(list);
  }
}