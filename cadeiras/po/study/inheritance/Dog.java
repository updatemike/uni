package inheritance;

import interfaces.Predator;

public class Dog extends Animal implements Predator{
    //Dog constructor calls Animal constructor (super)
    public Dog(String species, String name) {
        super(species, name);
    }
    // Override super class methods (abstract methods must be overriden)
    @Override
    public void makeNoise() {
        System.out.println("WOOF WOOF!");
    }
    // Override Interface methods
    @Override
    public void hunt() {
        System.out.println("**dog is hunting**");
    }
}