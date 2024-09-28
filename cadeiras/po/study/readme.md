# Packages
[Video](https://www.youtube.com/watch?v=NZ7NfZD8T2Y)
```java
package packagename;
import packagename.*;
import packagename.A;
```
- Follows file path
- Dog is in study/inheritance
- - package inheritance;
- Main is in study/
- - import inheritance.Dog; //import Dog
- - import packages.*; //import all inside inheritance file/package
- Visibility
- - package-private is accessible to anyone in the same package and that imports the package/file

# Overloading
```java
method(){}
method(String str) {}
method(int i) {}
```
- wich method will be called depends on the arguments of the call
- the signature of a method in java is it's name and the parameters (type and number)

# Inheritance
[Video](https://www.youtube.com/watch?v=Zs342ePFvRI)
```java
class Dog extends Animal {}
```
- "is a" relationship
- Dog inherits all fields and methods from Animal
- if I create Animal doggo = new Dog();
- - doggo is of static (at compile) class Animal but dynamic (at runtime) class Dog
- - methods called with doggo.method() will first look for the method in Dog then in Animal if they don't exist
- - methods that don't exist in animal even if Dog has them aren't accessible, needs casting
- - (Dog)doggo.method()
- - downcast needs to be explicit, upcast can be implicit
- Dog doesn't inherit any private methods of Animal and can't directly access private fields of Animal

# Override
[Video](https://www.youtube.com/watch?v=E-0MMeNi5Cw)
```java
@Override
method() {}
```

- subclass overrides method from superclass
- when method is called for Dog, java looks in Dog first then looks in Animal

# Interface
[Video](https://www.youtube.com/watch?v=GhslBwrRsnw)
```java
- public Interface B {}
- class A implements B, C {}
```

- template applied to class
- "can be", "can do" relationship
- class can implement multiple interfaces
- methods behave like abstract methods
- fields behave like public final static fields

# Generics
[Video](https://www.youtube.com/watch?v=jUcAyZ5OUm0)
- methods
```java
//print method accepts any type
public static <T> void print(T thing) {
    System.out.println(thing.toString());
}
```
- can make methods that can take multiple types (class and interface) as arguments
- don't need to make a method for each reference data type
---
- classes
```java
public class ArrayList <T> {}
ArrayList<Dog> array = new ArrayList<>();
```
- ArrayList is a generic class
- Generic classes can have multiple Classes as "parameters"
```java
public class HashMap <K, V> {}
HashMap<String, Dog> dogs = new HashMap<>();
```
- like hash Maps
---
- bounded types
- limit the types that can be used in generic
- use extends for both class and interfaces
- example of the generic method print that only accept Types that use the interface ToString
```java
//print method accepts any type that implements the interface ToString
public static <T extends ToString> void print(T thing) {
    System.out.println(thing.toString());
}
```
