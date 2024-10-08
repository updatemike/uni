package ex4;

import java.util.*;

public class Editor {
  List<Publication> _publicationList = new ArrayList<>();
  public Publication getPublication(String name, int id) {
    for(Publication p : _publicationList) {
      if(p.getName().equals(name) && p.getId() == (id)) return p;
    }
    return null;
  }
  public List<Publication> getPublicationsWithAuthor(String name) {
    List<Publication> list = new ArrayList<>();
    for(Publication p : _publicationList) {
      if(p.hasAuthor(name)) list.add(p);
    }
    return Collections.unmodifiableList(list);
  }
}