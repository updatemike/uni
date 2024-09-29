package ship;

public class Crew {
    private static int _lastID = 0;
    private final int _id;
    private String _name;
    private int _year;
    private int _salary;

    public Crew(String name, int year, int salary) {
        _name = name;
        _year = year;
        _salary = salary;
        _id = _lastID++;
    }
    public boolean equals(Object o) {
        if(o instanceof Crew) return _id == ((Crew)o)._id;
        return false;
    }
    public String getName() {return _name;}
    public int getYear() {return _year;}
    public int getSalary() {return _salary;}
    public int getID() {return _id;}
    public String toString() {return "ID: " + _id + " Name: " + _name + " Salary: " + _salary + " Birth: " + _year;}
}