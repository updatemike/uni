package ex2;

import java.util.*;

public abstract class Meal {
  private List<Ingredient> _ingredientList;
  private String _name;
  protected Meal(String name, Ingredient ingredient) {
    _ingredientList = new ArrayList<>();
    _name = name;
    _ingredientList.add(ingredient);
  }
  protected Meal(String name, List<Ingredient> ingredients) {
    _name = name;
    _ingredientList = new ArrayList<>(ingredients);
  }
  public void addIngredient(Ingredient ingredient) {_ingredientList.add(ingredient);}
  public boolean removeIngredient(Ingredient in) {
    if(_ingredientList.size() == 1) return false;
    for(Ingredient i : _ingredientList) {
      if(i.equals(in)){
        _ingredientList.remove(i);
        return true;
      }
    }
    return false;
  }
  public int calculatePrice() {
    int price = 0;
    for(Ingredient i : _ingredientList) {
      price += i.getPrice();
    }
    return price;
  }
  public static void main(String[] args) {
		Meal ref = new HotMeal("nomeQuente", new Ingredient("Tomate", 20));
		Meal ref2 = new ColdMeal("nomeFria", new Ingredient("Chorico", 40));
		
		ref.addIngredient(new Ingredient("Chorico", 40));
		ref2.addIngredient(new Ingredient("Tomate", 20));
		
		System.out.println(ref.calculatePrice());
		System.out.println(ref2.calculatePrice());
	}
}