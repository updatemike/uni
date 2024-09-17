// find compilation errors
// Sum.java:

public class Sum {
  public static Sum _s = null;
  
  private int _total;

  public Sum(int t) {
    _total = t;                         //names didn't match
  }

 public int computeVectorSum(int[] v) {
    int i = 0;
    _total = 0;

    while (i < v.length) {              //originally i wasn't initiated with a value
      _total += v[i++];
    }
       
    return _total;                      //original return type was void, this returns int
  }

  public int getTotal() {
    return _total;
  }
}

// Main.java:

public class Main {

  public static void main(String[] args) {
    int i;
    int[] v = new int[args.length];
 
    Sum sum = new Sum(0);                        // construtor sem args n existe
    
    for (i = 0; i < args.length; i++) {
      v[i] = Integer.parseInt(args[i]);
    }

    Sum._s = sum;
    sum.computeVectorSum(v);                    //this is non-static method
    System.out.println(sum.getTotal());         //getTotal was a private method, can't be accesses outside itself
  }
}