package ex4;

import java.util.*;

public class Magazine extends Publication {
  List<Article> _articles = new ArrayList<>();
  public Magazine(String name, int id) {super(name,id);}
  public List<Article> getArticles() {return Collections.unmodifiableList(_articles);}
  public boolean hasAuthor(String name) {
    for(Article a : getArticles()) {
      for(Author author : a.getAuthors()) {
        if(author.getName().equals(name))
          return true;
      }
    }
    return false;
  }
}
