package inheritance;

import interfaces.ToString;

abstract class Animal implements ToString{
    private String _species;
    private String _name;
    Animal(String species, String name) {
        _species = species;
        _name = name;
    }

    public String toString() {
        return "Name: " + _name + ", Species: " + _species;
    }
    public abstract void makeNoise();
}