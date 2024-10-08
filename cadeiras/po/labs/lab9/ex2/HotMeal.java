package ex2;

import java.util.*;

public class HotMeal extends Meal {
  public HotMeal(String name, Ingredient ingredient) {
    super(name, ingredient);
  }
  public HotMeal(String name, List<Ingredient> ingredients) {
    super(name, ingredients);
  }
  @Override
  public int calculatePrice() {
    return super.calculatePrice() + 75;
  }
}