package ex1;

public interface Queue {
  public abstract void enqueue(Object obj);
  public abstract Object dequeue() throws EmptyQueueException;
  public abstract int size();
}