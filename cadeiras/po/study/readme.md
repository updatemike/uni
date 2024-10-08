# Packages
[Video](https://www.youtube.com/watch?v=NZ7NfZD8T2Y)
```java
package packagename;
import packagename.*;
import packagename.A;
```
- Follows file path
- Dog is in study/inheritance
```java
package inheritance;
```
- Main is in study/
```java
import inheritance.Dog; //import Dog
import inheritance.*; //import all inside inheritance file/package
```
- Visibility
- - package-private is accessible to anyone in the same package
- - importing a file doesn't affect visibility, it just allows you to use a name instead of package.name

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
```java
Animal doggo = new Dog();
```
- - doggo is of static (at compile) class Animal but dynamic (at runtime) class Dog
- - methods called with doggo.method() will first look for the method in Dog then in Animal if they don't exist
- - methods that don't exist in animal even if Dog has them aren't accessible, needs casting
```java
(Dog)doggo.method()
```
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
public Interface B {}
class A implements B, C {}
```

- template applied to class
- "can be", "can do" relationship
- class can implement multiple interfaces
- methods behave like abstract methods
- fields behave like public final static fields

# Enumerated 
[Video](https://www.youtube.com/watch?v=TCMhP8trGwY)
- ordered listing of constant items in a collection
- each item behaves like an Object
- items cannot be changed after compilation
- you can assign values (fields) to each item (contructor) and use those fields with methods
```java
public enum Season{
    //enum items and values
    WINTER("cold", "rainy");
    //enum fields
    String _temp;
    String _weather;
    //enum constructor
    Season(String temp, String weather) {
        _temp = temp;
        _weather = weather;
    }
    //enum methods
    public String toString() {
        return "Temperature: " + _temp + " Weather: " + _weather;
    }
}
// Instanciating a Season and calling method
Seaon season = Season.SPRING;
season.toString();
```

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
# Collection<T> (interface)
[long video list about data structures used](https://www.youtube.com/playlist?list=PLUDwpEzHYYLu9-xrx5ykNH8wmN1C1qClk)
```java
import java.util.Collection;
Collection<Animal> animals = new ArrayList<>();
```
- methods
```java
boolean add()
boolean remove()
void clear()
boolean contains(T)
boolean isEmpty()
int size()
```
## Iterator and For Each
```java
import java.util.Iterator;
Iterator<Animal> iter = animals.iterator()
while(iter.hasNext()) {
    Animal a = iter.next();
    //Do something
}

for(Animal animal : animals){
    //Do something
}
```
- When a Collection is changed (add, remove) you can't keep iterating it: break;
- To do multiple remove ops: iter.remove();
## Set
[video](https://www.youtube.com/watch?v=QvHBHuuddYk)
- Collection with only unique objects
- boolean equals(Object), should override
- not ordered
- make usre you can't make 2 instances of the object equal and can't change the haschode
### HashSet
```java
import java.util.HashSet;
HashSet<Animal> animals = new HashSet<>();
```
- int hashCode(), should override (ex: Only use name of animal, needs to be unique)
## SortedSet
- an ordered Set
- int compareTo(T a), should override
```java
public class Animal implements Comparable<Animal> {
    public int compareTo(Animal a) {}
}
```
### TreeSet
```java
import java.util.TreeSet;
TreeSet<Animal> animals = new TreeSet<>();
```
## List
[video](https://www.youtube.com/watch?v=5dscMs2hnDI)
- has duplicates, ordered
- has index based operations
- uses ListIterator instad of Iterator
### ArrayList
```java
import java.util.ArrayList;
ArrayList<Animal> animals = new ArrayList<>();
```
- uses an array and resizes it when full
- add with index or at end
### LinkedList
```java
import java.util.LinkedList;
LinkedList<Animal> animals = new LinkedList<>();
```
- uses double linked list
- add with index, end or start
- using index is a O(n) operation because it has to iterate
- can access from start or end of List

# Collections
```java
import java.util.Collections;
```
- useful methods
```java
Collections.sort(List<> list); //implements Comparable<Type> and compareTo(Object o) method
Collections.sort(List<> list, Comparator comp);
Collections.unmodifiableCollection(list)
```
- remember List<> needs to be initiated and so do Comparators
- sort only works on List types
## Comparator
```java
import java.util.Comparator;
public class EmployeeComparatorSalaryName implements Comparator<Employee>{
    @Override
    public int compare(Employee e, Employee e2) {
        // int compare = ((Integer)e.getSalary()).compareTo(((Integer)e2.getSalary()));
        int compare = ((Integer)e.getSalary()).compareTo(((Integer)e2.getSalary()));
        if(compare == 0) return e.getName().compareTo(e2.getName());
        return compare;
    }   
}
public class Company {
    public Collection<Employee> getOrderedSalaryName() {
        ArrayList<Employee> list = new ArrayList<>(_employees);
        Collections.sort(list, new EmployeeComparatorSalaryName());
        return Collections.unmodifiableCollection(list);
    }
}
```

# Map<K, V> (interface)
[video](https://www.youtube.com/watch?v=H62Jfv1DJlU)
```java
import java.util.Map;
Map<String, Animal> animals = new HashMap<>()
```
- key - value pair
- unique key
- methods
```java
V put(K key, V value)
V remove(Object key)
V get(Object key)
boolean containsKey(Object key)
int size()
Set<K> keySet()
Collection<V> values()
void clear()

```
## Iterating
- keySet()
- values()
## HashMap
- unorderes
- uses hashcode

## TreeMap
- ordered
- compareTo() or comparator
