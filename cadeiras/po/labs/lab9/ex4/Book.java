package ex4;

import java.util.*;

public class Book extends Publication{
  List<Author> _authors = new ArrayList<>();
  public Book(String name, int id) {super(name,id);}
  public boolean hasAuthor(String name) {
    for(Author a : _authors)  {
      if(a.getName().equals(name)) 
        return true;
    }
    return false;
  }
}
