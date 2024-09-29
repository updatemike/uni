package inheritance;

import interfaces.Predator;
import interfaces.Prey;

public class Cat extends Animal implements Predator, Prey{
    //Cat constructor calls Animal constructor (super)
    public Cat(String species, String name) {
        super(species, name);
    }
    // Override super class methods (abstract methods must be overriden)
    @Override
    public void makeNoise() {
        System.out.println("MEOW!");
    }
    @Override
    protected String getSpecies() {
        return "Feline";
    }
    // Override interface methods
    @Override
    public void hunt() {
        System.out.println("**cat in hunting**");
    }
    @Override
    public void flee() {
        System.out.println("**cat is fleeing**");
    }
}