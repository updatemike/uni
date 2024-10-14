package company;

public class Project {
  private Member _m;

  Project (Member m) {
    _m = m;
  }
  public int getCost() {return _m.getCost();}
  public void doWork() {_m.doWork();}
}
