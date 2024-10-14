package company;

import java.util.*;

public class Team implements Member {
  private Set<Member> _members = new HashSet<>();
  public int getCost() {
    int cost = 0;
    for(Member m: _members)
      cost += m.getCost();
    return (int) (cost * 1.1);
  }
  public void doWork() {
    for(Member m : _members) 
      m.doWork();
  }
}
