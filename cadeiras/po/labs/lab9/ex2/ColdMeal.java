package ex2;

import java.util.*;

public class ColdMeal extends Meal {
  public ColdMeal(String name, Ingredient ingredient) {
    super(name, ingredient);
  }
  public ColdMeal(String name, List<Ingredient> ingredients) {
    super(name, ingredients);
  }
  @Override
  public int calculatePrice() {
    return super.calculatePrice() + 50;
  }
}