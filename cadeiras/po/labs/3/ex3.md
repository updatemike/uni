// find best practices errors

public class ComputeSum {
  public static ComputeSum _sum = null; //attribute should start with lower case
  
  private int _total; //attribute should start with _

  public ComputeSum(int t) {
    _total = t;
  }

  // compute sum of the elements in the vector
  public void vectorSum (int[] myVector) { //variable names should use camel case and not _
    int i = 0;
    _total = 0;

    while (i<myVector.length) {
      total += myVector[i++];
    }       
  }

  private int getTotal() { //methods should use came case not _
    return _total;
  }

  private void setTotal(int newTotal) { //again camel case for SetTotal and NewTotal
    _total = newTotal;
  }
}