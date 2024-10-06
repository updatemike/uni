package core;

import java.util.*;

public class IntegerManager {
    private List<Integer> _numbers;
    public IntegerManager() {
        _numbers = new ArrayList<>();
    }
    public boolean addNumber(Integer n) {
        if(_numbers.contains(n)) return false;
        _numbers.add(n);
        return true;
    }
    public boolean removeNumber(Integer n) {
        if(!(_numbers.contains(n))) return false;
        _numbers.remove(n);
        return true;
    }
    public List<Integer> getNumbers() {
        return Collections.unmodifiableList(_numbers);
    }
    public int getSize() {return _numbers.size();}
}