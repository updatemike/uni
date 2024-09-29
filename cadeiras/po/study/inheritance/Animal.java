package inheritance;

import interfaces.ToString;

public abstract class Animal implements ToString, Comparable<Animal>{
    private String _name;
    Animal(String species, String name) {
        _name = name;
    }
    public String getName() {
        return _name;
    }
    public String toString() {
        return "Name: " + _name + ", Species: " + getSpecies();
    }
    public abstract void makeNoise();
    protected abstract String getSpecies();
    //for collections
    //HashSet
    public boolean equals(Object o) {
        if(this == o) return true;
        if(getClass() != o.getClass()) return false;
        Animal a = (Animal) o;
        return _name.equals(a.getName());
    }
    public int hashCode() {
        return _name.hashCode();
    }
    //TreeSet
    public int compareTo(Animal a) {
        return _name.compareTo(a._name);
    }
}