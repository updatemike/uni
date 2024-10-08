package ex2;

public class Ingredient {
  private String _name;
  private int _price;
  public Ingredient(String name, int price) {
    _name = name;
    _price = price;
  }
  public int getPrice() {return _price;}
  public String getName() {return _name;}
}