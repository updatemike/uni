package ex4;

import java.util.*;

public class Article {
  private String _title;
  private List<Author> _authors = new ArrayList<>();
  public Article(String title) {_title=title;}
  public String getTitle() {return _title;}
  public List<Author> getAuthors() {return Collections.unmodifiableList(_authors);}
}
