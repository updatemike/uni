public class NoSuchIdentifierException extends Exception{
    private static final long serialVersionUID=1L;
    private int _id;

    public NoSuchIdentifierException(int id) {_id = id;}
    public NoSuchIdentifierException(int id, Exception cause) {
        super(cause);
        _id = id;
    }
    public int getId() {return _id;}
}
