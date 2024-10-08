package ex4;

public abstract class Publication {
  private String _name;
  private int _id;
  protected Publication(String name, int id) {
    _name = name;
    _id = id;
  }
  public String getName() {return _name;}
  public int getId() {return _id;}
  public abstract boolean hasAuthor(String name);
  
}
