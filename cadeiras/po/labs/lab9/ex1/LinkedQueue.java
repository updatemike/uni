package ex1;

import java.util.*;

public class LinkedQueue implements Queue{
  List<Object> _queue = new LinkedList<>();

  public void enqueue(Object obj){_queue.add(obj);}
  public Object dequeue() throws EmptyQueueException{
    if (_queue.isEmpty()) throw new EmptyQueueException();
    return _queue.removeFirst();
  }
  public int size(){return _queue.size();}
  public int countEqual(Object obj) {
    int counter = 0;
    for(Object o : _queue) {
      if(obj.equals(o)) counter++;
    }
    return counter;
  }
}