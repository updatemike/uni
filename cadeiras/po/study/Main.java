import inheritance.Cat;
import inheritance.Dog;
import interfaces.ToString;
import enumerated.Season;

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
        print(dog);
        print(cat);

        cat.hunt();
        dog.hunt();
        dog.makeNoise();
        cat.makeNoise();
        cat.flee();

        //enums
        Season season = Season.SPRING;
        print(season);
    }
}