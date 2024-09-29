import inheritance.*;
import interfaces.ToString;
import enumerated.Season;
//Collection
import java.util.Collection;
//Iterator
import java.util.Iterator;
//Set
import java.util.HashSet;
import java.util.TreeSet;

public class Main {
    //Generic method
    // methods accepts any type and implements the interface ToString
    public static <T extends ToString> void print(T thing) {
        System.out.println(thing.toString());
    }

    public static void main(String[] args) {
        //Testing java package import
        Dog dog = new Dog("Canine", "Doggo");
        Cat cat = new Cat("Feline", "Catto");
        // System.out.println(dog.toString());
        // System.out.println(cat.toString());


        cat.hunt();
        dog.hunt();
        dog.makeNoise();
        cat.makeNoise();
        cat.flee();

        //enums
        Season season = Season.SPRING;
        print(season);

        //collection
        Dog dog1 = new Dog("Canine", "Doggo2");
        Dog dog2 = new Dog("Canine", "Doggo");
        Dog dog3 = new Dog("Canine", "Doggo");

        //set
        //HashSet<Animal> animals = new HashSet<>();
        //sorted set
        TreeSet<Animal> animals = new TreeSet<>();


        //iterator
        animals.add(dog1);
        animals.add(dog2);
        animals.add(dog3);

        Iterator<Animal> iter = animals.iterator();
        System.out.println("Using iterator:");
        while(iter.hasNext()) {
            Animal a = iter.next();
            print(a);
            a.makeNoise();
        }
        System.out.println("Using for each:");
        for(Animal a : animals) {
            print(a);
            a.makeNoise();
        }
    }
}